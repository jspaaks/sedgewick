#include "options.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



int main (int argc, const char * argv[]) {

    const Kwargs * kwargs = kwargs_create(argc, argv, 0, nullptr);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    size_t maxint = options_get_maxint(kwargs);

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
    for (size_t i = 2; i < maxint; i++) {
        if (is_prime[i]) printf("%4zu ", i);
    }
    printf("\n");

    free(is_prime);
    is_prime = nullptr;
    exit(EXIT_SUCCESS);
}
