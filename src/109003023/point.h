#ifndef POINT_H
#define POINT_H
#include <stddef.h>
#include <stdint.h>

typedef struct point Point;

struct point {
    uint16_t ndims;
    float * xs;
};

float point_calc_distance_squared (Point * a, Point * b);
void point_destroy (const size_t npoints, Point ** points);
void point_initialize (size_t npoints, Point * points, uint16_t ndims);


#endif
