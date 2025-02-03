#include <stdio.h>

// note: values of N larger than sqrt(INT_MAX) won't work or won't
// work correctly due to integer overflow of term i*j. On systems
// with 32 bit signed integers, that means 46340 is the maximum
// allowed value
#define N 10000


int main (void)
  { int i, j, a[N];
    for (i = 2; i < N; i++) a[i] = 1;
    for (i = 2; i < N; i++)
      if (a[i])
        for (j = i; i*j < N; j++) a[i*j] = 0;
    for (i = 2; i < N; i++)
      if (a[i]) printf("%4d ", i);
    printf("\n");
    return 0;
  }
