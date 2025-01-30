#include "options.h"
#include "point.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float unitrand() {
    return  1.0 * rand() / RAND_MAX;
}


int main (int argc, const char * argv[]) {

    // initialize random number generation
    srand(time(nullptr));

    // read the user input
    const size_t npositionals = 2;
    const Kwargs * kwargs = kwargs_create(argc, argv, 0, nullptr, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    size_t npoints = options_get_npoints(kwargs);
    float distance = options_get_distance(kwargs);

    // initialize the array of points
    Point * points = malloc(npoints * sizeof(*points));
    for (size_t i = 0; i < npoints; i++) {
        points[i].x = unitrand();
        points[i].y = unitrand();
    }

    // count the points that qualify
    uint32_t nedges_short = 0;
    for (size_t i = 0; i < npoints; i++) {
        for (size_t j = i + 1; j < npoints; j++) {
            if (calc_distance(points[i], points[j]) < distance) {
                nedges_short++;
            }
        }
    }

    // report
    uint32_t nedges = 0.5 * npoints * (npoints - 1);
    printf("Randomly generated %zu points in the unit square.\n"
           "Out of all %u edges, %u were shorter than %f\n",
           npoints, nedges, nedges_short, distance);

    exit(EXIT_SUCCESS);
}
