#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>


size_t options_get_maxint (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(0, kwargs);
    size_t maxint;
    sscanf(s, " %zu", &maxint);
    return maxint;
}


void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108400001 -h\n"
            "       108400001 --help\n"
            "       108400001 MAXINT\n"
            "\n"
            "    Use the sieve of Eratosthenes to print all prime numbers\n"
            "    between 2 and MAXINT.\n"
            "\n"
            "    Required\n"
            "        MAXINT\n"
            "            The maximum integer to include in the analysis.\n"
            );
}
