#include "kwargs/kwargs.h"
#include "options.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, const char * argv[]) {

    // initialize random-number generator
    srand(time(nullptr));

    // collect user input
    size_t nclasses = options_get_nclasses();
    const KwargsClass * classes = options_get_classes();
    size_t npositionals = 2;
    const Kwargs * kwargs = kwargs_create(argc, argv, nclasses, classes, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        exit(EXIT_SUCCESS);
    }
    const uint16_t maxint = options_get_maxint(kwargs);
    const size_t nrand = options_get_nrand(kwargs);
    const bool report_occurrences = options_get_report_occurrences(kwargs);
    const bool report_unique = options_get_report_unique(kwargs);

    if (maxint == 0) {
        fprintf(stdout, "ERROR: MAXINT should be 1..%" PRIu16 "\n", UINT16_MAX);
        options_show_usage();
        exit(EXIT_FAILURE);
    }

    if (!report_unique && !report_occurrences) {
        fprintf(stdout, "ERROR: Specify at least one of [--report_occurrences, --report_unique]\n");
        options_show_usage();
        exit(EXIT_FAILURE);
    }

    // allocate array
    uint16_t * counts = calloc(maxint, sizeof(uint16_t));

    // count occurrences
    for (size_t irand = 0; irand < nrand; irand++) {
        double z = (double) rand() / RAND_MAX;
        uint16_t ibin = (uint16_t) (z * maxint);
        counts[ibin]++;
    }

    // report results
    if (report_occurrences) {
        fprintf(stdout, "%-5s     %s\n", "value", "number of occurrences");
        for (size_t i = 0; i < maxint; i++) {
            fprintf(stdout, "%-5zu     %" PRIu16 "\n", i, counts[i]);
        }
    }
    if (report_unique) {
        uint16_t nunique = 0;
        for (uint16_t i = 0; i < maxint; i++) {
            if (counts[i]) {
                nunique++;
            }
        }
        fprintf(stdout, "Found %" PRIu16 " unique integers.\n", nunique);
    }

    // clean up
    free(counts);
    exit(EXIT_SUCCESS);
}
