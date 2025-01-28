#ifndef POINT_H
#define POINT_H

typedef struct point2 Point2;

struct point2 {
    float x;
    float y;
};


Point2 point_draw (int r);
void point_print (Point2 * point);
float point_calc_euclidean_distance (Point2 * from, Point2 * to);
bool point_test_is_collinear (Point2 * p0, Point2 * p1, Point2 * p2, float tolerance);

#endif
