#include "point.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

float point_calc_distance_squared (Point * a, Point * b) {
    if (a->ndims != b->ndims) {
        fprintf(stderr, "ERROR: points must havwe the same dimensionality in order to\n"
                        "accurately calcualte the distance between them, aborting.\n");
        exit(EXIT_FAILURE);
    }
    float hypo2 = 0.f;
    for (uint16_t i = 0; i < a->ndims; i++) {
        float diff = a->xs[i] - b->xs[i];
        hypo2 += diff * diff;
    }
    return hypo2;
}

void point_initialize (const size_t npoints, Point * points, const uint16_t ndims) {
    for (size_t ipoint = 0; ipoint < npoints; ipoint++) {
        float * xs = malloc(ndims * sizeof(float));
        if (xs == nullptr) {
            fprintf(stderr, "ERROR: Problems allocating memory for point %zu, aborting.\n", ipoint);
            exit(EXIT_FAILURE);
        }
        for (uint16_t idim = 0; idim < ndims; idim++) {
            xs[idim] = 1.0 * rand() / RAND_MAX;
        }
        points[ipoint] = (Point){
            .ndims = ndims,
            .xs = xs,
        };
    }
}

void point_destroy (const size_t npoints, Point ** points) {
    for (size_t ipoint = 0; ipoint < npoints; ipoint++) {
        free((*points)[ipoint].xs);
        (*points)[ipoint].xs = nullptr;
    }
    free(*points);
    *points = nullptr;
}
