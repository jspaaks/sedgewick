# 108203010

```console
$ 108203010 -h
usage: 108203010 -h
       108203010 --help
       108203010 [OPTIONS]...

    Generate random triangles whose vertices are from the interval [0, 1) and
    report on selected statistics of the set of drawn triangles.

    Options
        -a, --report_avg
            Report the average triangle size of the set.

        -h, --help
            Show this help and exit.

        -m, --report_max
            Report the maximum triangle size of the set.

        -q, --report_areas
            Report each triangle area.

        -t, --report_triangles
            Report each triangle.

        -n NTRIANGLES, --ntriangles NTRIANGLES
            The number of triangles to generate (default 7).

```

```console
$ ./dist/bin/108203010 --report_max --report_avg --ntriangles 3
average area of triangle: 0.096
average area of triangle (theory): 0.076
max area of triangle: 0.154
max area of triangle (theory): 0.500
$ ./dist/bin/108203010 --report_max --report_avg --ntriangles 100000000
average area of triangle: 0.076
average area of triangle (theory): 0.076
max area of triangle: 0.490
max area of triangle (theory): 0.500
```
