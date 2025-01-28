#include "polar_point.h"
#include <stdlib.h>


int main (void) {
    PolarPoint2 point = {
        .ell = 0.4,
        .angle = 90
    };
    polar_point_print(&point);
    exit(EXIT_SUCCESS);
}
