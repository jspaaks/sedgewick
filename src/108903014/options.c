#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>


static KwargsClass classes[4] = {
    {
        .shortname = "-c",
        .longname = "--report_cumulative",
        .type = KWARGS_FLAG
    },
    {
        .shortname = "-n",
        .longname = "--report_number",
        .type = KWARGS_FLAG
    },
    {
        .shortname = "-p",
        .longname = "--report_primes",
        .type = KWARGS_FLAG
    },
    {
        .shortname = "-w",
        .longname = "--ncolsmax",
        .type = KWARGS_OPTIONAL
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


size_t options_get_ncolsmax (const Kwargs * kwargs) {
    const char * s = kwargs_get_optional_value("--ncolsmax", kwargs);
    if (s == nullptr) {
        return (size_t) 20;
    }
    size_t ncolsmax;
    sscanf(s, " %zu", &ncolsmax);
    return ncolsmax;
}


bool options_get_report_cumulative (const Kwargs * kwargs) {
    bool a = kwargs_has_flag("--report_cumulative", kwargs);
    bool b = kwargs_get_optional_value("--ncolsmax", kwargs) != 0;
    return a || b;
}


bool options_get_report_number (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_number", kwargs);
}


bool options_get_report_primes (const Kwargs * kwargs) {
    return kwargs_has_flag("--report_primes", kwargs);
}


void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108903013 -h\n"
            "       108903013 --help\n"
            "       108903013 [OPTIONS]... MAXINT\n"
            "\n"
            "    Use the sieve of Eratosthenes to find all prime numbers\n"
            "    less than or equal to MAXINT.\n"
            "\n"
            "    Options\n"
            "\n"
            "        -c, --report_cumulative\n"
            "            Report the cumulative distribution of primes.\n"
            "\n"
            "        -n, --report_number\n"
            "            Report the number of primes found.\n"
            "\n"
            "        -p, --report_primes\n"
            "            Report the primes found.\n"
            "\n"
            "        -w NCOLSMAX, --ncolsmax NCOLSMAX\n"
            "            The maximum number of colums to use for printing the\n"
            "            cumulative distribution of primes (implies use of\n"
            "            --report_cumulative flag; default 20).\n"
            "\n"
            "    Required\n"
            "\n"
            "        MAXINT\n"
            "            The maximum integer to include in the analysis.\n"
            "\n"
            );
}
