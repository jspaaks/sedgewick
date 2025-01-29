#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>


static const KwargsClass classes[] = {
    {
        .longname = "--maxint",
        .shortname = "-m",
        .type = KWARGS_REQUIRED
    }
};


const KwargsClass * options_get_classes (void) {
    return &classes[0];
}


size_t options_get_nclasses (void) {
    return sizeof(classes) / sizeof(classes[0]);
}


size_t options_get_maxint (const Kwargs * kwargs) {
    const char * s = kwargs_get_required_value("--maxint", kwargs);
    size_t maxint;
    sscanf(s, " %zu", &maxint);
    return maxint;
}


void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108400001 -h\n"
            "       108400001 --help\n"
            "       108400001 [OPTIONS]...\n"
            "\n"
            "    Use the sieve of Eratosthenes to print all prime numbers\n"
            "    between 2 and MAXINT.\n"
            "\n"
            "    Required\n"
            "        -m MAXINT, --maxint MAXINT\n"
            "            The maximum integer to include in the analysis.\n"
            );
}
