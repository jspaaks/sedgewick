#include "point.h"
#include <math.h>


float calc_distance (Point a, Point b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
