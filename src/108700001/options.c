#include "options.h"
#include "kwargs/kwargs.h"
#include <stddef.h>


size_t options_get_ntosses (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(0, kwargs);
    size_t ntosses;
    sscanf(s, " %zu", &ntosses);
    return ntosses;
}


size_t options_get_ntrials (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(1, kwargs);
    size_t ntrials;
    sscanf(s, " %zu", &ntrials);
    return ntrials;
}


void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108700001 -h\n"
            "       108700001 --help\n"
            "       108700001 NTOSSES NTRIALS\n"
            "\n"
            "    Simulate flipping a coin NTOSSES times, repeat that NTRIALS times,\n"
            "    then report the number of times a trial yielded a given number of\n"
            "    heads as a probability distribution.\n"
            "\n"
            "    Required\n"
            "        NTOSSES\n"
            "            The number of coin tosses in one trial.\n"
            "        NTRIALS\n"
            "            The number of trials.\n"
            );
}
