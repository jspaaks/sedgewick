# 108903019

```console
$ ./dist/bin/108903019 --help
usage: 108903019 -h
       108903019 --help
       108903019 [OPTIONS]... MAXINT NTRIALS

    1. Randomly generate integers between 0 and MAXINT inclusive until all
       values have been drawn at least once;
    2. Store the number of integers drawn;
    3. Repeat for NTRIALS trials;

    Options

        -c NCOLSMAX, --ncolsmax NCOLSMAX
            The number of columns to use for reporting the probability
            distribution.

        -o, --no-outcomes
            Don't report the outcomes for individual trials.

        -d, --no-distribution
            Don't report the probability distribution.

        -s SEED, --seed SEED
            The positive integer seed to use for initializing the pseudo-random
            number generator.

    Required

        MAXINT
            The maximum value any randomly generated integer
            can have. Maximum allowed value is 65534.

        NTRIALS
            The number of trials.

$ ./dist/bin/108903019 --seed 12345 --no-distribution 10 5
Trial      Draws needed before
           all numbers repeat
0          50
1          38
2          22
3          35
4          43
$ ./dist/bin/108903019 --seed 12345 --no-outcomes --ncolsmax 20 1000 100000
Draws needed before    Count         Distribution
all numbers repeat
4361                   1
4362                   0
4363                   0
4364                   0
4365                   0
4366                   0
4367                   0
4368                   0
4369                   0
<output omitted>
7290                   36            ************
7291                   46            ***************
7292                   36            ************
7293                   37            ************
7294                   31            **********
7295                   42            **************
7296                   34            ***********
7297                   58            ********************
7298                   28            *********
7299                   26            ********
7300                   38            *************
7301                   41            **************
7302                   33            ***********
7303                   37            ************
<output omitted>
18877                  0
18878                  0
18879                  0
18880                  0
18881                  0
18882                  0
18883                  0
18884                  0
18885                  0
18886                  1
```
