#ifndef POINT_H
#define POINT_H
#include <stdint.h>

typedef struct point2 Point2;

struct point2 {
    float x;
    float y;
};

Point2 point_draw (int r);
void point_print (Point2 * point);
float point_calc_euclidean_distance (Point2 * from, Point2 * to);

#endif
