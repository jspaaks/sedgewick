#include "options.h"
#include "point.h"
#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct retain {
    float dsquared;
    size_t i;
    size_t j;
    uint32_t nedges_short;
} Retain;

Retain count_the_points_that_qualify (size_t npoints, Point * points, float dsquared_threshold);
void initialize_random_number_generation (unsigned int seed);
void report (size_t npoints, const Point * points, const Retain * retain, float distance_squared,
             uint16_t ndims);
float unitrand (void);

Retain count_the_points_that_qualify (const size_t npoints, Point * points,
                                      const float dsquared_threshold) {
    Retain retain = {
        .dsquared = FLT_MAX,
        .i = -1,
        .j = -1,
        .nedges_short = 0,
    };
    for (size_t i = 0; i < npoints; i++) {
        for (size_t j = i + 1; j < npoints; j++) {
            float dsquared = point_calc_distance_squared(&points[i], &points[j]);
            if (dsquared < retain.dsquared) {
                retain = (Retain){
                    .dsquared = dsquared,
                    .i = i,
                    .j = j,
                };
            }
            if (dsquared < dsquared_threshold) {
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
    const uint16_t ndims = options_get_ndims(kwargs);

    const float dsquared_threshold = distance * distance;

    initialize_random_number_generation(seed);

    // initialize the array of points
    Point * points = malloc(npoints * sizeof(*points));
    if (points == nullptr) {
        fprintf(stderr, "ERROR: Problems allocating memory for points array, aborting.\n");
        exit(EXIT_FAILURE);
    }
    point_initialize(npoints, &points[0], ndims);

    Retain retain = count_the_points_that_qualify(npoints, points, dsquared_threshold);
    report(npoints, points, &retain, dsquared_threshold, ndims);

    // deallocate and exit
    point_destroy(npoints, &points);
    exit(EXIT_SUCCESS);
}

void report (const size_t npoints, const Point * points, const Retain * retain,
             const float dsquared_threshold, const uint16_t ndims) {
    const uint32_t nedges = 0.5 * npoints * (npoints - 1);
    printf("Randomly generated %zu points in the %" PRIu16 "-dimensional unit square.\n", npoints,
           ndims);
    printf("The minimum distance is %.3f, which is the distance from\n", sqrt(retain->dsquared));
    printf("point %zu (", retain->i);
    for (uint16_t idim = 0; idim < points[retain->i].ndims - 1; idim++) {
        printf("%.3f, ", points[retain->i].xs[idim]);
    }
    printf("%.3f", points[retain->i].xs[ndims - 1]);
    printf(") to\n");
    printf("point %zu (", retain->j);
    for (uint16_t idim = 0; idim < points[retain->j].ndims - 1; idim++) {
        printf("%.3f, ", points[retain->j].xs[idim]);
    }
    printf("%.3f", points[retain->j].xs[ndims - 1]);
    printf(")\n");
    printf("Out of all %u edges, %u %s shorter than %f\n", nedges, retain->nedges_short,
           retain->nedges_short == 1 ? "was" : "were", sqrt(dsquared_threshold));
}
