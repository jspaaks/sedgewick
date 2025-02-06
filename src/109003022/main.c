#include "options.h"
#include "point.h"
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct retain {
    float d;
    size_t i;
    size_t j;
} Retain;

float unitrand (void) {
    return 1.0 * rand() / RAND_MAX;
}

int main (int argc, const char * argv[]) {

    // read the user input
    const size_t npositionals = 0;
    const size_t nclasses = options_get_nclasses();
    const KwargsClass * classes = options_get_classes();
    const Kwargs * kwargs = kwargs_create(argc, argv, nclasses, classes, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    const size_t npoints = options_get_npoints(kwargs);
    const float distance = options_get_distance(kwargs);
    const unsigned int seed = options_get_seed(kwargs);

    // initialize random number generation
    srand(seed);

    // initialize the array of points
    Point * points = malloc(npoints * sizeof(*points));
    for (size_t i = 0; i < npoints; i++) {
        points[i].x = unitrand();
        points[i].y = unitrand();
    }

    // count the points that qualify
    Retain retain = {
        .d = FLT_MAX,
        .i = npoints + 1,
        .j = npoints + 1,
    };
    uint32_t nedges_short = 0;
    for (size_t i = 0; i < npoints; i++) {
        for (size_t j = i + 1; j < npoints; j++) {
            float d = calc_distance(points[i], points[j]);
            if (d < retain.d) {
                retain = (Retain){
                    .d = d,
                    .i = i,
                    .j = j,
                };
            }
            if (d < distance) {
                nedges_short++;
            }
        }
    }

    // report
    const uint32_t nedges = 0.5 * npoints * (npoints - 1);
    printf("Randomly generated %zu points in the unit square.\n", npoints);
    printf("The minimum distance is %.3f, which is the distance from\n"
           "point %zu (.x = %.3f, .y = %.3f) to\n"
           "point %zu (.x = %.3f, .y = %.3f)\n",
           retain.d, retain.i, points[retain.i].x, points[retain.i].y, retain.j, points[retain.j].x,
           points[retain.j].y);
    printf("Out of all %u edges, %u were shorter than %f\n", nedges, nedges_short, distance);
    exit(EXIT_SUCCESS);
}
