# 108700001

Same as 108700000 but with code refactored for readability.

```console
$ ./dist/bin/108700001 -h
usage: 108700001 -h
       108700001 --help
       108700001 NTOSSES NTRIALS

    Simulate flipping a coin NTOSSES times, repeat that NTRIALS times,
    then report the number of times a trial yielded a given number of
    heads as a probability distribution.

    Required
        NTOSSES
            The number of coin tosses in one trial.
        NTRIALS
            The number of trials.
$ ./dist/bin/108700001 32 1000
 0 
 1 
 2 
 3 
 4 
 5 
 6 
 7 *
 8 *
 9 *
10 **
11 **
12 ****
13 *******
14 *********
15 ************
16 ***************
17 **************
18 ************
19 ***********
20 *******
21 *****
22 ***
23 **
24 *
25 *
26 
27 
28 
29 
30 
31 
32 
```
