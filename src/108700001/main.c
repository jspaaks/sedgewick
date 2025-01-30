#include "options.h"
#include "kwargs/kwargs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int heads() {
    return rand() < RAND_MAX / 2;
}


int main(int argc, const char * argv[]) {
    srand(time(nullptr));
    const size_t npositionals = 2;
    const Kwargs * kwargs = kwargs_create(argc, argv, 0, nullptr, npositionals);
    if (kwargs_requires_help(kwargs)) {
        options_show_usage();
        kwargs_destroy((Kwargs **) &kwargs);
        exit(EXIT_SUCCESS);
    }
    size_t ntosses = options_get_ntosses(kwargs);
    size_t ntrials = options_get_ntrials(kwargs);
    size_t * counts = malloc((ntosses + 1) * sizeof(size_t));
    for (size_t itoss = 0; itoss <= ntosses; itoss++) {
        counts[itoss] = 0;
    }
    for (size_t itrial = 0; itrial < ntrials; itrial++) {
        size_t cnt = 0;
        for (size_t itoss = 0; itoss <= ntosses; itoss++) {
            if (heads()) {
                cnt++;
            }
        }
        counts[cnt]++;
    }
    for (size_t itoss = 0; itoss <= ntosses; itoss++) {
        printf("%2zu ", itoss);
        for (size_t i = 0; i < counts[itoss]; i += 10) {
            printf("*");
        }
        printf("\n");
    }
}
