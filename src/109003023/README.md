# 109003023

```console
$ ./dist/bin/109003023 --help
usage: 109003023 -h
       109003023 --help
       109003023 [OPTIONALS, REQUIREDS]...

    Generate points in the multidimensional unit square, calculate the
    lengths of all edges, then report the smallest distance found as well as
    how many of the edges between the points are shorter than a critical
    distance.

    Optional

        -n NDIMS, --ndims NDIMS (positive integer)
            The number of dimension to use for defining points.

        -s SEED, --seed SEED (positive integer)
            The seed to use for initializing the pseudo-random number
            generator. If omitted, the value of time(nullptr) is used.

    Required

        -p NPOINTS, --npoints NPOINTS (positive integer)
            The number of points to generate in the NDIMS-dimensional unit
            square.

        -d DISTANCE, --distance DISTANCE (floating point)
            The critical distance.

$ ./dist/bin/109003023 --seed 12345 --distance 0.2 --npoints 100 --ndims 5
Randomly generated 100 points in the 5-dimensional unit square.
The minimum distance is 0.151, which is the distance from
point 30 (0.366, 0.474, 0.871, 0.642, 0.797) to
point 60 (0.311, 0.362, 0.902, 0.649, 0.876)
Out of all 4950 edges, 4 were shorter than 0.200000
```
