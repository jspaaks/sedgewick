#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <float.h>

int8_t find_largest_8(void);
int16_t find_largest_16(void);
int32_t find_largest_32(void);
int64_t find_largest_64(void);

int8_t find_largest_8(void) {
    uint8_t u = (uint8_t) (-1);
    return (int8_t)(u / 2);
}

int16_t find_largest_16(void) {
    uint16_t u = (uint16_t) (-1);
    return (int16_t)(u / 2);
}

int32_t find_largest_32(void) {
    uint32_t u = (uint32_t) (-1);
    return (int32_t)(u / 2);
}

int64_t find_largest_64(void) {
    uint64_t u = (uint64_t) (-1);
    return (int64_t)(u / 2);
}

int main (void) {
    int8_t largest_8 = find_largest_8();
    fprintf(stdout, "largest int8 found : %d\n", largest_8);
    fprintf(stdout, "INT8_MAX           : %d\n\n", INT8_MAX);

    int16_t largest_16 = find_largest_16();
    fprintf(stdout, "largest int16 found: %d\n", largest_16);
    fprintf(stdout, "INT16_MAX          : %d\n\n", INT16_MAX);

    int32_t largest_32 = find_largest_32();
    fprintf(stdout, "largest int32 found: %d\n", largest_32);
    fprintf(stdout, "INT32_MAX          : %d\n\n", INT32_MAX);

    int64_t largest_64 = find_largest_64();
    fprintf(stdout, "largest int64 found: %ld\n", largest_64);
    fprintf(stdout, "INT64_MAX          : %ld\n\n", INT64_MAX);

    fprintf(stdout, "SHRT_MAX           : %d\n", SHRT_MAX);
    fprintf(stdout, "INT_MAX            : %d\n", INT_MAX);
    fprintf(stdout, "LONG_MAX           : %ld\n\n", LONG_MAX);
    fprintf(stdout, "FLT_MAX            : %f\n", FLT_MAX);
    fprintf(stdout, "DBL_MAX            : %f\n\n", DBL_MAX);

}
