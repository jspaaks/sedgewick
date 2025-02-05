#include "point.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float distance;
    Point2 point;
} ClosestPoint2;

int main (void) {
    Point2 points[3] = {
        {
         .x = -1,
         .y = -1,
         },
        {
         .x = 0,
         .y = 0,
         },
        {
         .x = 1,
         .y = 1,
         },
    };
    const float tolerance = 0.0001;
    if (point_test_is_collinear(&points[0], &points[1], &points[2], tolerance)) {
        fprintf(stdout, "collinear points\n");
    } else {
        fprintf(stdout, "noncollinear points\n");
    }
    exit(EXIT_SUCCESS);
}
