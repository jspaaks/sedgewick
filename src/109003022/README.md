# 109003022

```console
$ ./dist/bin/109003022 --help
usage: 109003022 -h
       109003022 --help
       109003022 [OPTIONALS, REQUIREDS]...

    Generate points in the 2-D unit square, calculate the lengths of all
    edges, then report the smallest distance found as well as how many of
    the edges between the points are shorter than a critical distance.

    Optional

        -s SEED, --seed SEED (positive integer)
            The seed to use for initializing the pseudo-random number
            generator. If omitted, the value of time(nullptr) is used.

    Required

        -p NPOINTS, --npoints NPOINTS (positive integer)
            The number of points to generate in the 2-D unit square.

        -d DISTANCE, --distance DISTANCE (floating point)
            The critical distance.

$ ./dist/bin/109003022 --distance 0.2 -p 70
Randomly generated 70 points in the unit square.
The minimum distance is 0.013, which is the distance from
point 21 (.x = 0.257, .y = 0.171) to
point 27 (.x = 0.247, .y = 0.162)
Out of all 2415 edges, 237 were shorter than 0.200000
```
