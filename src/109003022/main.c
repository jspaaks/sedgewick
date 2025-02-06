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
    uint32_t nedges_short;
} Retain;

Retain count_the_points_that_qualify (size_t npoints, Point * points, float distance);
void initialize_random_number_generation (unsigned int seed);
void report (size_t npoints, const Point * points, const Retain * retain, float distance);
float unitrand (void);

Retain count_the_points_that_qualify (const size_t npoints, Point * points, const float distance) {
    Retain retain = {
        .d = FLT_MAX,
        .i = -1,
        .j = -1,
        .nedges_short = 0,
    };
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
                retain.nedges_short++;
            }
        }
    }
    return retain;
}

void initialize_random_number_generation (unsigned int seed) {
    srand(seed);
}

int main (int argc, const char * argv[]) {

    // collect user input
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

    initialize_random_number_generation(seed);

    // initialize the array of points
    Point * points = malloc(npoints * sizeof(*points));
    for (size_t i = 0; i < npoints; i++) {
        points[i].x = unitrand();
        points[i].y = unitrand();
    }

    Retain retain = count_the_points_that_qualify(npoints, points, distance);
    report(npoints, points, &retain, distance);

    // deallocate and exit
    free(points);
    points = nullptr;
    exit(EXIT_SUCCESS);
}

void report (const size_t npoints, const Point * points, const Retain * retain, const float distance) {
    const uint32_t nedges = 0.5 * npoints * (npoints - 1);
    printf("Randomly generated %zu points in the unit square.\n", npoints);
    printf("The minimum distance is %.3f, which is the distance from\n"
           "point %zu (.x = %.3f, .y = %.3f) to\n"
           "point %zu (.x = %.3f, .y = %.3f)\n",
           retain->d, retain->i, points[retain->i].x, points[retain->i].y, retain->j, points[retain->j].x,
           points[retain->j].y);
    printf("Out of all %u edges, %u were shorter than %f\n", nedges, retain->nedges_short, distance);
}

float unitrand (void) {
    return 1.0 * rand() / RAND_MAX;
}
