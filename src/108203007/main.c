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

    srand(time(nullptr));

    constexpr size_t n = 10;
    const int r = 125;
    Point2 points[n] = {};
    for (size_t i = 0; i < n; i++) {
        points[i] = point_draw(r);
    }
    ClosestPoint2 closest = {
        .distance = FLT_MAX,
        .point = points[1],
    };
    fprintf(stdout, "{%7.3f, %7.3f}\n", points[0].x, points[0].y);
    for (size_t i = 1; i < n; i++) {
        float distance = point_calc_euclidean_distance(&points[0], &points[i]);
        fprintf(stdout, "{%7.3f, %7.3f}: %.3f\n", points[i].x, points[i].y, distance);
        if (distance < closest.distance) {
            closest = (ClosestPoint2){
                .distance = distance,
                .point = points[i],
            };
        }
    }
    fprintf(stdout, "Closest point to {.x = %.3f, .y = %.3f} is {.x = %.3f, .y = %.3f} at a distance of %.3f.\n",
            points[0].x, points[0].y, closest.point.x, closest.point.y, closest.distance);
    exit(EXIT_SUCCESS);
}
