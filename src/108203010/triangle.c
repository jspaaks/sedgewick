#include "triangle.h"
#include <stdio.h>
#include <math.h>

float triangle_calc_area (Triangle * triangle) {
    float one = triangle->a.x * (triangle->b.y - triangle->c.y);
    float two = triangle->b.x * (triangle->c.y - triangle->a.y);
    float three = triangle->c.x * (triangle->a.y - triangle->b.y);
    return 0.5 * fabsf(one + two + three);
}


Triangle triangle_draw (void) {
    return (Triangle) {
        .a = point_draw(),
        .b = point_draw(),
        .c = point_draw()
    };
}


void triangle_print(Triangle * triangle) {
    fprintf(stdout, "{\n");
    fprintf(stdout, "  a.x: %7.3f,\n", triangle->a.x);
    fprintf(stdout, "  a.y: %7.3f,\n", triangle->a.y);
    fprintf(stdout, "  b.x: %7.3f,\n", triangle->b.x);
    fprintf(stdout, "  b.y: %7.3f,\n", triangle->b.y);
    fprintf(stdout, "  c.x: %7.3f,\n", triangle->c.x);
    fprintf(stdout, "  c.y: %7.3f\n", triangle->c.y);
    fprintf(stdout, "}\n");
}


