#include "kwargs/kwargs.h"
#include "options.h"
#include "triangle.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, const char * argv[]) {

    srand(time(nullptr));
    size_t nclasses = options_get_nclasses();
    const KwargsClass * classes = options_get_classes();
    const size_t npositionals = 0;
    const Kwargs * kwargs = kwargs_create(argc, argv, nclasses, classes, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    size_t ntriangles = options_get_ntriangles(kwargs);

    double area = DBL_MIN;
    double avg_area = 0.0;
    double max_area = DBL_MIN;

    bool report_triangles = options_get_report_triangles(kwargs);
    bool report_areas = options_get_report_areas(kwargs);

    for (size_t i = 0; i < ntriangles; i++) {
        Triangle triangle = triangle_draw();
        if (report_triangles) {
            triangle_print(&triangle);
        }
        area = (double) triangle_calc_area(&triangle);
        if (report_areas) {
            fprintf(stdout, "area: %.3f\n", area);
        }
        avg_area += area / ntriangles;
        max_area = area > max_area ? area : max_area;
    }
    if (options_get_report_avg(kwargs)) {
        fprintf(stdout, "average area of triangle: %.3lf\n", avg_area);
        fprintf(stdout, "average area of triangle (theory): %.3lf\n", (double) 11 / 144);
    }
    if (options_get_report_max(kwargs)) {
        fprintf(stdout, "max area of triangle: %.3lf\n", max_area);
        fprintf(stdout, "max area of triangle (theory): %.3lf\n", 0.5);
    }
    exit(EXIT_SUCCESS);
}
