# 108903013

```console
$ ./dist/bin/108903013 --help
usage: 108903013 -h
       108903013 --help
       108903013 [OPTIONS]... MAXINT

    Use the sieve of Eratosthenes to find all prime numbers
    less than MAXINT.

    Options

        -n, --report_number
            Report the number of primes found.

        -p, --report_primes
            Report the primes found.

    Required

        MAXINT
            The maximum integer to include in the analysis.
$ ./dist/bin/108903013 -p -n 10
   2    3    5    7 
Found 4 primes.
$ ./dist/bin/108903013 -n 1000
Found 168 primes.
$ ./dist/bin/108903013 -n 10000
Found 1229 primes.
$ ./dist/bin/108903013 -n 100000
Found 9592 primes.
$ ./dist/bin/108903013 -n 1000000
Found 78498 primes.
```
