# 108903013

```console
$ ./dist/bin/108903014 --help
usage: 108903013 -h
       108903013 --help
       108903013 [OPTIONS]... MAXINT

    Use the sieve of Eratosthenes to find all prime numbers
    less than or equal to MAXINT.

    Options

        -c, --report_cumulative
            Report the cumulative distribution of primes.

        -n, --report_number
            Report the number of primes found.

        -p, --report_primes
            Report the primes found.

        -w NCOLSMAX, --ncolsmax NCOLSMAX
            The maximum number of colums to use for printing the
            cumulative distribution of primes (implies use of
            --report_cumulative flag; default 20).

    Required

        MAXINT
            The maximum integer to include in the analysis.

$ ./dist/bin/108903014 --report_primes --report_number --ncolsmax 8 22
   2    3    5    7   11   13   17   19 
Found 8 primes.
         2: *
         3: **
         4: **
         5: ***
         6: ***
         7: ****
         8: ****
         9: ****
        10: ****
        11: *****
        12: *****
        13: ******
        14: ******
        15: ******
        16: ******
        17: *******
        18: *******
        19: ********
        20: ********
        21: ********
        22: ********
```
