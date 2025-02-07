#include "options.h"
#include "kwargs/kwargs.h"
#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

static const KwargsClass classes[4] = {
    {
     .shortname = "-d",
     .longname = "--distance",
     .type = KWARGS_REQUIRED,
     },
    {
     .shortname = "-n",
     .longname = "--ndims",
     .type = KWARGS_OPTIONAL,
     },
    {
     .shortname = "-p",
     .longname = "--npoints",
     .type = KWARGS_REQUIRED,
     },
    {
     .shortname = "-s",
     .longname = "--seed",
     .type = KWARGS_OPTIONAL,
     },
};

const KwargsClass * options_get_classes (void) {
    return &classes[0];
}

float options_get_distance (const Kwargs * kwargs) {
    const char * s = kwargs_get_required_value("--distance", kwargs);
    float distance;
    int count = sscanf(s, " %f", &distance);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    return distance;
}

size_t options_get_nclasses (void) {
    return sizeof(classes) / sizeof(classes[0]);
}

uint16_t options_get_ndims (const Kwargs * kwargs) {
    const char * s = kwargs_get_optional_value("--ndims", kwargs);
    if (s == nullptr) {
        return (size_t) 2;
    }
    int64_t ndims;
    int count = sscanf(s, " %" SCNi64, &ndims);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    if (1 <= ndims && ndims <= UINT16_MAX) {
        return (uint16_t) ndims;
    } else {
        fprintf(stderr, "ERROR: Value of NDIMS (%s) is out of range, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
}

size_t options_get_npoints (const Kwargs * kwargs) {
    const char * s = kwargs_get_required_value("--npoints", kwargs);
    int64_t npoints;
    int count = sscanf(s, " %" SCNi64, &npoints);
    if (count != 1) {
        fprintf(stderr, "ERROR: Problem reading \"%s\" as a number, aborting.\n", s);
        exit(EXIT_FAILURE);
    }
    if (0 < npoints) {
        return (size_t) npoints;
    } else {
        fprintf(stderr, "ERROR: Value of NPOINTS (%s) is out of range, aborting.\n", s);
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
    fprintf(stdout, "usage: 109003023 -h\n"
                    "       109003023 --help\n"
                    "       109003023 [OPTIONALS, REQUIREDS]...\n"
                    "\n"
                    "    Generate points in the multidimensional unit square, calculate the\n"
                    "    lengths of all edges, then report the smallest distance found as well as\n"
                    "    how many of the edges between the points are shorter than a critical\n"
                    "    distance.\n"
                    "\n"
                    "    Optional\n"
                    "\n"
                    "        -n NDIMS, --ndims NDIMS (positive integer)\n"
                    "            The number of dimension to use for defining points.\n"
                    "\n"
                    "        -s SEED, --seed SEED (positive integer)\n"
                    "            The seed to use for initializing the pseudo-random number\n"
                    "            generator. If omitted, the value of time(nullptr) is used.\n"
                    "\n"
                    "    Required\n"
                    "\n"
                    "        -p NPOINTS, --npoints NPOINTS (positive integer)\n"
                    "            The number of points to generate in the NDIMS-dimensional unit\n"
                    "            square.\n"
                    "\n"
                    "        -d DISTANCE, --distance DISTANCE (floating point)\n"
                    "            The critical distance.\n"
                    "\n");
}
