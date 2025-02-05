#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>

static KwargsClass classes[2] = {
    {
     .shortname = "-n",
     .longname = "--report_number",
     .type = KWARGS_FLAG,
     },
    {
     .shortname = "-p",
     .longname = "--report_primes",
     .type = KWARGS_FLAG,
     }
};

KwargsClass * options_get_classes (void) {
    return &classes[0];
}

size_t options_get_maxint (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(0, kwargs);
    size_t maxint;
    sscanf(s, " %zu", &maxint);
    return maxint;
}

size_t options_get_nclasses (void) {
    return sizeof(classes) / sizeof(classes[0]);
}

bool options_get_report_number (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_number", kwargs);
}

bool options_get_report_primes (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_primes", kwargs);
}

void options_show_usage (void) {
    fprintf(stdout, "usage: 108903013 -h\n"
                    "       108903013 --help\n"
                    "       108903013 [OPTIONS]... MAXINT\n"
                    "\n"
                    "    Use the sieve of Eratosthenes to find all prime numbers\n"
                    "    less than MAXINT.\n"
                    "\n"
                    "    Options\n"
                    "\n"
                    "        -n, --report_number\n"
                    "            Report the number of primes found.\n"
                    "\n"
                    "        -p, --report_primes\n"
                    "            Report the primes found.\n"
                    "\n"
                    "    Required\n"
                    "\n"
                    "        MAXINT\n"
                    "            The maximum integer to include in the analysis.\n");
}
