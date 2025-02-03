#include "options.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, const char * argv[]) {

    // collect user input
    const size_t nclasses = options_get_nclasses();
    const KwargsClass * classes = options_get_classes();
    const size_t npositionals = 1;
    const Kwargs * kwargs = kwargs_create(argc, argv, nclasses, classes, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    size_t maxint = options_get_maxint(kwargs);
    {
        size_t max_allowed = (size_t) sqrtl((long double) SIZE_MAX);
        if (maxint > max_allowed) {
            fprintf(stderr,
                    "Program won't work correctly for integers larger than %ld, aborting.\n",
                    max_allowed);
            exit(EXIT_FAILURE);
        }
    }
    bool report_number = options_get_report_number(kwargs);
    bool report_primes = options_get_report_primes(kwargs);

    // allocate memory for the is_primes array
    bool * is_prime = calloc(maxint, 1);
    if (is_prime == nullptr) {
        fprintf(stderr, "Error allocating memory for is_primes array, aborting.\n");
        exit(EXIT_FAILURE);
    }

    // initialize all true
    for (size_t i = 2; i < maxint; i++) {
        is_prime[i] = true;
    }

    // set all multiples of i to false, starting at i^2
    for (size_t i = 2; i < maxint; i++) {
        if (is_prime[i]) {
            size_t j = i * i;
            while (j < maxint) {
                is_prime[j] = false;
                j += i;
            }
        }
    }

    // print indices where is_prime is true
    size_t nprimes = 0;
    for (size_t i = 2; i < maxint; i++) {
        if (is_prime[i]) {
            if (report_primes) {
                printf("%4zu ", i);
            }
            nprimes++;
        }
    }
    if (report_primes) {
        printf("\n");
    }
    if (report_number) {
        printf("Found %zu primes.\n", nprimes);
    }

    free(is_prime);
    is_prime = nullptr;
    exit(EXIT_SUCCESS);
}
