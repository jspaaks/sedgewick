#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

typedef struct triangle Triangle;

float triangle_calc_area (Triangle * triangle);
Triangle triangle_draw (void);
void triangle_print (Triangle * triangle);

struct triangle {
    struct point a;
    struct point b;
    struct point c;
};

#endif
