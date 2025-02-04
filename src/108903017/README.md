# 108903017

```console
$ ./dist/bin/108903017 -h
usage: 108903017 -h
       108903017 --help
       108903017 [OPTIONS]... MAXINT NRAND

    Count occurrences of randomly generated integers.

    Options

        -o, --report_occurrences
            Report the counts for each integer 0..MAXINT.

        -u, --report_unique
            Report the number of unique integers found.

    Required

        MAXINT
            The maximum value any randomly generated integer
            can have. Maximum allowed value is 65535.

        NRAND
            The number of randomly generated integers.

$ ./dist/bin/108903017 --report_unique --report_occurrences 10 3
value     number of occurrences
0         0
1         1
2         0
3         0
4         2
5         0
6         0
7         0
8         0
9         0
Found 2 unique integers.
$ ./dist/bin/108903017 --report_unique 1000 500
Found 382 unique integers.
```
