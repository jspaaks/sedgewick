#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>

size_t options_get_npoints (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(0, kwargs);
    size_t npoints;
    sscanf(s, " %zu", &npoints);
    return npoints;
}

float options_get_distance (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(1, kwargs);
    float distance;
    sscanf(s, " %f", &distance);
    return distance;
}

void options_show_usage (void) {
    fprintf(stdout, "usage: 108700001 -h\n"
                    "       108700001 --help\n"
                    "       108700001 NPOINTS DISTANCE\n"
                    "\n"
                    "    Generate NPOINTS points in the 2-D unit square and report how many of the\n"
                    "    edges between the points are shorter than the critical distance DISTANCE.\n"
                    "\n"
                    "    Required\n"
                    "        NPOINTS (positive integer)\n"
                    "            The number of points.\n"
                    "        DISTANCE (floating point)\n"
                    "            The critical distance.\n");
}
