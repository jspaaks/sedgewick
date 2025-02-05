#include "point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int compare_x (const void * a, const void * b);

Point2 point_draw (int r) {
    return (Point2){
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

bool point_test_is_collinear (Point2 * p0, Point2 * p1, Point2 * p2, float tolerance) {
    constexpr size_t nmemb = 3;
    Point2 * points[nmemb] = { p0, p1, p2 };
    qsort(&points[0], nmemb, sizeof(Point2), compare_x);
    float slope01 = (points[1]->y - points[0]->y) / (points[1]->x - points[0]->x);
    float slope12 = (points[2]->y - points[1]->y) / (points[2]->x - points[1]->x);
    if (fabs(slope12 - slope01) > tolerance) return false;
    return true;
}

int compare_x (const void * a, const void * b) {
    const Point2 * aa = (const Point2 *) a;
    const Point2 * bb = (const Point2 *) b;
    if (aa->x < bb->x) return -1;
    if (aa->x > bb->x) return 1;
    return 0;
}