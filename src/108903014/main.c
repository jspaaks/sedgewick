#include "options.h"
#include <stddef.h>
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
    size_t n = options_get_maxint(kwargs) + 1;
    size_t ncolsmax = options_get_ncolsmax(kwargs);
    bool report_cumulative = options_get_report_cumulative(kwargs);
    bool report_number = options_get_report_number(kwargs);
    bool report_primes = options_get_report_primes(kwargs);

    // allocate memory for the is_primes array
    bool * is_prime = calloc(n, 1);
    if (is_prime == nullptr) {
        fprintf(stderr, "Error allocating memory for is_primes array, aborting.\n");
        exit(EXIT_FAILURE);
    }

    // initialize all true
    for (size_t i = 2; i < n; i++) {
        is_prime[i] = true;
    }

    // set all multiples of i to false, starting at i^2
    for (size_t i = 2; i < n; i++) {
        if (is_prime[i]) {
            size_t j = i * i;
            while (j < n) {
                is_prime[j] = false;
                j += i;
            }
        }
    }

    // reporting
    size_t nprimes[n] = {};
    size_t i_prev_prime = 0;
    for (size_t i = 2; i < n; i++) {
        if (is_prime[i]) {
            if (report_primes) {
                printf("%4zu ", i);
            }
            nprimes[i] = nprimes[i_prev_prime] + 1;
            i_prev_prime = i;
        } else {
            nprimes[i] = nprimes[i_prev_prime];
        }
    }
    if (report_primes) {
        printf("\n");
    }
    if (report_number) {
        printf("Found %zu primes.\n", nprimes[n - 1]);
    }
    if (report_cumulative) {
        size_t primes_per_star = 1;
        if (nprimes[n - 1] >= ncolsmax) {
            primes_per_star = nprimes[n - 1] / ncolsmax;
        }
        for (size_t ielem = 2; ielem < n; ielem++) {
            printf("%10zu: ", ielem);
            size_t nstars = nprimes[ielem] / primes_per_star;
            for (size_t istar = 0; istar < nstars; istar++) {
                printf("*");
            }
            printf("\n");
        }
    }

    // deallocate memory
    free(is_prime);
    is_prime = nullptr;
    exit(EXIT_SUCCESS);
}
