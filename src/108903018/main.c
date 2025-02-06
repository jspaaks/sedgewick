#include "kwargs/kwargs.h"
#include "options.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

void initialize_random_number_generator (unsigned int seed);
void report_distribution (const size_t ntrials, const uint16_t * ndraws, const uint16_t ncolsmax, size_t * bins);
void report_outcomes (size_t ntrials, const uint16_t * ndraws);
void run_the_trials (uint16_t maxint, bool * seen, size_t ntrials, uint16_t * ndraws);

void initialize_random_number_generator (unsigned int seed) {
    srandom(seed);
}

int main (int argc, const char * argv[]) {

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
    const uint16_t ncolsmax = options_get_ncolsmax(kwargs);
    const size_t ntrials = options_get_ntrials(kwargs);
    const bool no_outcomes = options_get_no_outcomes(kwargs);
    const bool no_distribution = options_get_no_distribution(kwargs);
    const unsigned int seed = options_get_seed(kwargs);

    if (maxint == 0) {
        fprintf(stdout, "ERROR: MAXINT should be [1..%" PRIu16 "]\n", UINT16_MAX - 1);
        options_show_usage();
        exit(EXIT_FAILURE);
    }

    // allocate arrays
    bool * seen = calloc(maxint + 1, sizeof(bool));
    if (seen == nullptr) {
        fprintf(stderr, "Error allocating memory for array 'seen', aborting.\n");
        exit(EXIT_FAILURE);
    }
    uint16_t * ndraws = calloc(ntrials, sizeof(uint16_t));
    if (ndraws == nullptr) {
        fprintf(stderr, "Error allocating memory for array 'ndrawn', aborting.\n");
        exit(EXIT_FAILURE);
    }

    initialize_random_number_generator(seed);
    run_the_trials(maxint, &seen[0], ntrials, &ndraws[0]);
    if (!no_outcomes) {
        report_outcomes(ntrials, &ndraws[0]);
    }
    size_t * bins = nullptr;
    if (!no_distribution) {
        report_distribution (ntrials, &ndraws[0], ncolsmax, &bins[0]);
    }

    // clean up
    free(seen);
    free(ndraws);
    free(bins);
    exit(EXIT_SUCCESS);
}

void report_distribution (const size_t ntrials, const uint16_t * ndraws, const uint16_t ncolsmax, size_t * bins) {
    uint16_t ndrawsmin = ndraws[0];
    uint16_t ndrawsmax = ndraws[0];
    for (size_t itrial = 1; itrial < ntrials; itrial++) {
        if (ndraws[itrial] < ndrawsmin) {
            ndrawsmin = ndraws[itrial];
        }
        if (ndraws[itrial] > ndrawsmax) {
            ndrawsmax = ndraws[itrial];
        }
    }
    size_t nbins = ndrawsmax - ndrawsmin + 1;
    bins = calloc(nbins, sizeof(size_t));
    if (bins == nullptr) {
        fprintf(stderr, "ERROR: Problem allocating memory for 'bins' array, aborting.\n");
        exit(EXIT_FAILURE);
    }
    for (size_t itrial = 0; itrial < ntrials; itrial++) {
        size_t ibin = ndraws[itrial] - ndrawsmin;
        bins[ibin]++;
    }
    size_t binsmax = bins[0];
    for (size_t ibin = 1; ibin < nbins; ibin++) {
        if (bins[ibin] > binsmax) {
            binsmax = bins[ibin];
        }
    }
    float f = (float) ncolsmax / binsmax;
    fprintf(stdout, "%-19s    %-10s    %s\n", "Draws needed before", "Count", "Distribution");
    fprintf(stdout, "%-19s    %-10s    %s\n", "repeated number", "", "");
    for (size_t ibin = 0; ibin < nbins; ibin++) {
        fprintf(stdout, "%-19zu    %-10zu    ", ibin + ndrawsmin, bins[ibin]);
        size_t ncols = (size_t) (bins[ibin] * f);
        for (size_t icol = 0; icol < ncols; icol++) {
            fprintf(stdout, "*");
        }
        fprintf(stdout, "\n");
    }
}

void report_outcomes (const size_t ntrials, const uint16_t * ndraws) {
    fprintf(stdout, "%-7s    %s\n", "Trial", "Draws needed before");
    fprintf(stdout, "%-7s    %s\n", "", "repeated number");
    for (size_t i = 0; i < ntrials; i++) {
        fprintf(stdout, "%-7zu    %" PRIu16 "\n", i, ndraws[i]);
    }
}

void run_the_trials (const uint16_t maxint, bool * seen, const size_t ntrials, uint16_t * ndraws) {
    uint16_t nseen = maxint + (uint16_t) 1;
    for (size_t itrial = 0; itrial < ntrials; itrial++) {
        for (size_t iseen = 0; iseen < nseen; iseen++) {
            seen[iseen] = false;
        }
        while (true) {
            double z = (double) random() / RAND_MAX;
            uint16_t ibin = (uint16_t) (z * maxint);
            ndraws[itrial]++;
            if (seen[ibin]) {
                break;
            } else {
                seen[ibin] = true;
            }
        }
    }
}

