# 108800001

Same as 108800000 but with code refactored for readability.

```console
$ $ ./dist/bin/108800001 -h
usage: 108700001 -h
       108700001 --help
       108700001 NPOINTS DISTANCE

    Generate NPOINTS points in the 2-D unit square and report how many of the
    edges between the points are shorter than the critical distance DISTANCE.

    Required
        NPOINTS (positive integer)
            The number of points.
        DISTANCE (floating point)
            The critical distance.
$ ./dist/bin/108800001 12 0.5
Randomly generated 12 points in the unit square.
Out of all 66 edges, 31 were shorter than 0.500000
```
