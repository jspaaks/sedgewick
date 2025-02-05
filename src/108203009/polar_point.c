#include "polar_point.h"
#include <stdio.h>

void polar_point_print (PolarPoint2 * point) {
    fprintf(stdout, "{.ell = %7.3f, .angle = %7.3f}\n", point->ell, point->angle);
}
