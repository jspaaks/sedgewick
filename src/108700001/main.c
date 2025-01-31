#include "options.h"
#include "kwargs/kwargs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


bool heads (void);


bool heads (void) {
    return rand() < RAND_MAX / 2;
}


int main(int argc, const char * argv[]) {

    // initialize the pseudo-random number generator
    srand(time(nullptr));

    // collect user input
    const size_t npositionals = 2;
    const Kwargs * kwargs = kwargs_create(argc, argv, 0, nullptr, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    size_t ntosses = options_get_ntosses(kwargs);
    size_t ntrials = options_get_ntrials(kwargs);

    // allocate memory and set initial value
    size_t * counts = malloc((ntosses + 1) * sizeof(size_t));
    for (size_t itoss = 0; itoss <= ntosses; itoss++) {
        counts[itoss] = 0;
    }

    // do the experiment
    for (size_t itrial = 0; itrial < ntrials; itrial++) {
        size_t cnt = 0;
        for (size_t itoss = 0; itoss <= ntosses; itoss++) {
            if (heads()) {
                cnt++;
            }
        }
        counts[cnt]++;
    }

    // reporting
    for (size_t itoss = 0; itoss <= ntosses; itoss++) {
        printf("%2zu ", itoss);
        for (size_t i = 0; i < counts[itoss]; i += 10) {
            printf("*");
        }
        printf("\n");
    }

    // deallocate memory and exit
    free(counts);
    counts = nullptr;
    exit(EXIT_SUCCESS);
}
