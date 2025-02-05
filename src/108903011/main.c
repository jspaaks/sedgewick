#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    const size_t n = 99;
    uint8_t arr[99] = {};
    for (size_t i = 0; i < n; i++) {
        arr[i] = 98 - i;
    }
    for (size_t i = 0; i < n; i++) {
        arr[i] = arr[arr[i]];
    }
    for (size_t i = 0; i < n; i++) {
        if (i > 0 && i % 10 == 0) {
            fprintf(stdout, "\n");
        }
        fprintf(stdout, " %2hhu", arr[i]);
    }
    fprintf(stdout, "\n");
    exit(EXIT_SUCCESS);
}
