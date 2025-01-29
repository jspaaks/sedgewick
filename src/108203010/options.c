#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>


static const KwargsClass classes[] = {
    {
        .longname = "--ntriangles",
        .shortname = "-n",
        .type = KWARGS_OPTIONAL
    },
    {
        .longname = "--report_avg",
        .shortname = "-a",
        .type = KWARGS_FLAG
    },
    {
        .longname = "--report_max",
        .shortname = "-m",
        .type = KWARGS_FLAG
    },
    {
        .longname = "--report_areas",
        .shortname = "-q",
        .type = KWARGS_FLAG
    },
    {
        .longname = "--report_triangles",
        .shortname = "-t",
        .type = KWARGS_FLAG
    }
};


const KwargsClass * options_get_classes (void) {
    return &classes[0];
}


size_t options_get_nclasses (void) {
    return sizeof(classes) / sizeof(classes[0]);
}


size_t options_get_ntriangles (const Kwargs * kwargs) {
    const char * s = kwargs_get_optional_value("--ntriangles", kwargs);
    if (s == nullptr) {
        return (size_t) 7;
    }
    size_t ntriangles;
    sscanf(s, " %zu", &ntriangles);
    return ntriangles;
}


bool options_get_report_areas (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_areas", kwargs);
}


bool options_get_report_avg (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_avg", kwargs);
}


bool options_get_report_max (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_max", kwargs);
}


bool options_get_report_triangles (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_triangles", kwargs);
}


void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108203010 -h\n"
            "       108203010 --help\n"
            "       108203010 [OPTIONS]...\n"
            "\n"
            "    Generate random triangles whose vertices are from the interval [0, 1) and\n"
            "    report on selected statistics of the set of drawn triangles.\n"
            "\n"
            "    Options\n"
            "        -a, --report_avg\n"
            "            Report the average triangle size of the set.\n"
            "\n"
            "        -h, --help\n"
            "            Show this help and exit.\n"
            "\n"
            "        -m, --report_max\n"
            "            Report the maximum triangle size of the set.\n"
            "\n"
            "        -q, --report_areas\n"
            "            Report each triangle area.\n"
            "\n"
            "        -t, --report_triangles\n"
            "            Report each triangle.\n"
            "\n"
            "        -n NTRIANGLES, --ntriangles NTRIANGLES\n"
            "            The number of triangles to generate (default 7).\n"
            );
}
