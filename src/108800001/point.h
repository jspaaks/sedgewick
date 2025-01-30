#ifndef POINT_H
#define POINT_H

typedef struct point Point;
struct point {
    float x;
    float y;
};

float calc_distance (Point a, Point b);

#endif
