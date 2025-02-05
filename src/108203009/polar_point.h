#ifndef POLAR_POINT_H
#define POLAR_POINT_H

typedef struct polar_point2 PolarPoint2;

struct polar_point2 {
    float ell;
    float angle;
};

void polar_point_print (PolarPoint2 * point);

#endif
