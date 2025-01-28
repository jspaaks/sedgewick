#include "point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int compare_x (void * a, void * b);


Point2 point_draw (int r) {
    return (Point2) {
        .x = (float) rand() / RAND_MAX * r,
        .y = (float) rand() / RAND_MAX * r,
    };
}


float point_calc_euclidean_distance (Point2 * from, Point2 * to) {
    float dx = to->x - from->x;
    float dy = to->y - from->y;
    return sqrt(dx * dx + dy * dy);
}


void point_print (Point2 * point) {
    fprintf(stdout, "{.x = %7.3f, .y = %7.3f}\n", point->x, point->y);
}
