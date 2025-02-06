#include "options.h"
#include "kwargs/kwargs.h"
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

static const KwargsClass classes[4] = {
    {
     .shortname = "-c",
     .longname = "--ncolsmax",
     .type = KWARGS_OPTIONAL,
     },
    {
     .shortname = "-d",
     .longname = "--no-distribution",
     .type = KWARGS_FLAG,
     },
    {
     .shortname = "-o",
     .longname = "--no-outcomes",
     .type = KWARGS_FLAG,
     },
    {
     .shortname = "-s",
     .longname = "--seed",
     .type = KWARGS_OPTIONAL,
     }
};

const KwargsClass * options_get_classes (void) {
    return &classes[0];
}

uint16_t options_get_maxint (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(0, kwargs);
    int64_t maxint;
    int count = sscanf(s, " %" SCNi64, &maxint);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    if (0 < maxint && maxint < UINT16_MAX) {
        return (uint16_t) maxint;
    } else {
        fprintf(stderr, "ERROR: Value of MAXINT (%s) is out of range, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
}

size_t options_get_nclasses (void) {
    return sizeof(classes) / sizeof(classes[0]);
}

uint16_t options_get_ncolsmax (const Kwargs * kwargs) {
    const char * s = kwargs_get_optional_value("--ncolsmax", kwargs);
    if (s == nullptr) {
        return 15;
    }
    int64_t ncolsmax;
    int count = sscanf(s, " %" SCNi64, &ncolsmax);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    if (0 < ncolsmax && ncolsmax <= UINT16_MAX) {
        return (uint16_t) ncolsmax;
    } else {
        fprintf(stderr, "ERROR: Value of NCOLSMAX (%s) is out of range, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
}

bool options_get_no_distribution (const Kwargs * kwargs) {
    return kwargs_has_flag("--no-distribution", kwargs);
}

bool options_get_no_outcomes (const Kwargs * kwargs) {
    return kwargs_has_flag("--no-outcomes", kwargs);
}

size_t options_get_ntrials (const Kwargs * kwargs) {
    const char * s = kwargs_get_positional_value(1, kwargs);
    int64_t ntrials;
    int count = sscanf(s, " %" SCNi64, &ntrials);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    if (0 < ntrials) {
        return (size_t) ntrials;
    } else {
        fprintf(stderr, "ERROR: Value of NTRIALS (%s) is out of range, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
}

unsigned int options_get_seed (const Kwargs * kwargs) {
    const char * s = kwargs_get_optional_value("--seed", kwargs);
    if (s == nullptr) {
        return time(nullptr);
    }
    int64_t seed;
    int count = sscanf(s, " %" SCNi64, &seed);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    if (0 < seed && seed <= UINT_MAX) {
        return (unsigned int) seed;
    } else {
        fprintf(stderr, "ERROR: Value of SEED (%s) is out of range, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
}

void options_show_usage (void) {
    fprintf(stdout,
            "usage: 108903019 -h\n"
            "       108903019 --help\n"
            "       108903019 [OPTIONS]... MAXINT NTRIALS\n"
            "\n"
            "    1. Randomly generate integers between 0 and MAXINT inclusive until all\n"
            "       values have been drawn at least once;\n"
            "    2. Store the number of integers drawn;\n"
            "    3. Repeat for NTRIALS trials;\n"
            "\n"
            "    Options\n"
            "\n"
            "        -c NCOLSMAX, --ncolsmax NCOLSMAX\n"
            "            The number of columns to use for reporting the probability\n"
            "            distribution.\n"
            "\n"
            "        -o, --no-outcomes\n"
            "            Don't report the outcomes for individual trials.\n"
            "\n"
            "        -d, --no-distribution\n"
            "            Don't report the probability distribution.\n"
            "\n"
            "        -s SEED, --seed SEED\n"
            "            The positive integer seed to use for initializing the pseudo-random\n"
            "            number generator.\n"
            "\n"
            "    Required\n"
            "\n"
            "        MAXINT\n"
            "            The maximum value any randomly generated integer\n"
            "            can have. Maximum allowed value is %" PRIu16 ".\n"
            "\n"
            "        NTRIALS\n"
            "            The number of trials.\n"
            "\n",
            UINT16_MAX - 1);
}
