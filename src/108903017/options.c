#include "options.h"
#include "kwargs/kwargs.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

static KwargsClass classes[2] = {
    {
     .shortname = "-o",
     .longname = "--report_occurrences",
     .type = KWARGS_FLAG,
     },
    {
     .shortname = "-u",
     .longname = "--report_unique",
     .type = KWARGS_FLAG,
     }
};

KwargsClass * options_get_classes (void) {
    return &classes[0];
}

uint16_t options_get_maxint (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(0, kwargs);
    uint16_t maxint;
    sscanf(s, " %hu", &maxint);
    return maxint;
}

size_t options_get_nclasses (void) {
    return sizeof(classes) / sizeof(classes[0]);
}

size_t options_get_nrand (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(1, kwargs);
    size_t nrand;
    sscanf(s, " %zu", &nrand);
    return nrand;
}

bool options_get_report_occurrences (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_occurrences", kwargs);
}

bool options_get_report_unique (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_unique", kwargs);
}

void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108903017 -h\n"
            "       108903017 --help\n"
            "       108903017 [OPTIONS]... MAXINT NRAND\n"
            "\n"
            "    Count occurrences of randomly generated integers.\n"
            "\n"
            "    Options\n"
            "\n"
            "        -o, --report_occurrences\n"
            "            Report the counts for each integer 0..MAXINT.\n"
            "\n"
            "        -u, --report_unique\n"
            "            Report the number of unique integers found.\n"
            "\n"
            "    Required\n"
            "\n"
            "        MAXINT\n"
            "            The maximum value any randomly generated integer\n"
            "            can have. Maximum allowed value is %" PRIu16 ".\n"
            "\n"
            "        NRAND\n"
            "            The number of randomly generated integers.\n"
            "\n",
            UINT16_MAX);
}
