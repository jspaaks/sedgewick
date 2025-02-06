# 108903018

```console
$ ./dist/bin/108903018 --help
usage: 108903018 -h
       108903018 --help
       108903018 [OPTIONS]... MAXINT NTRIALS

    1. Randomly generate integers between 0 and MAXINT until a
       value is repeated;
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

$ ./dist/bin/108903018 --seed 12345 --no-distribution 10 5
Trial      Draws needed before
           repeated number
0          3
1          3
2          4
3          3
4          6
$ ./dist/bin/108903018 --seed 12345 --no-outcomes --ncolsmax 20 1000 1000000
Draws needed before    Count         Distribution
repeated number
2                      1002
3                      2053          *
4                      2938          **
5                      3924          ***
6                      4985          ***
7                      5870          ****
8                      6812          *****
9                      7516          ******
10                     8569          ******
11                     9491          *******
12                     10455         ********
13                     11066         ********
14                     12168         *********
15                     12847         **********
16                     13298         **********
17                     13926         ***********
18                     14675         ***********
19                     15250         ************
20                     15585         ************
21                     16145         ************
22                     17046         *************
23                     17188         *************
24                     17433         *************
25                     18060         **************
26                     18377         **************
27                     18511         **************
28                     24943         ********************
29                     19016         ***************
30                     19310         ***************
31                     18677         **************
32                     19316         ***************
33                     19570         ***************
34                     19251         ***************
35                     19161         ***************
36                     19022         ***************
37                     18754         ***************
38                     18973         ***************
39                     18510         **************
40                     18231         **************
41                     18316         **************
42                     17570         **************
43                     17633         **************
44                     17034         *************
45                     16976         *************
46                     16448         *************
47                     16254         *************
48                     15672         ************
49                     15178         ************
50                     14802         ***********
51                     14455         ***********
52                     13842         ***********
53                     13514         **********
54                     12986         **********
55                     12620         **********
56                     12180         *********
57                     11386         *********
58                     11186         ********
59                     10824         ********
60                     9879          *******
61                     9654          *******
62                     9210          *******
63                     8762          *******
64                     8285          ******
65                     8016          ******
66                     7528          ******
67                     7454          *****
68                     6844          *****
69                     6574          *****
70                     6241          *****
71                     5946          ****
72                     5534          ****
73                     5114          ****
74                     4932          ***
75                     4625          ***
76                     4329          ***
77                     3993          ***
78                     3832          ***
79                     3487          **
80                     3386          **
81                     2978          **
82                     3070          **
83                     2703          **
84                     2447          *
85                     2353          *
86                     2176          *
87                     2063          *
88                     1862          *
89                     1677          *
90                     1570          *
91                     1476          *
92                     1338          *
93                     1239
94                     1149
95                     1046
96                     991
97                     849
98                     813
99                     721
100                    692
101                    606
102                    535
103                    530
104                    455
105                    427
106                    367
107                    376
108                    356
109                    323
110                    226
111                    240
112                    230
113                    199
114                    178
115                    150
116                    137
117                    119
118                    109
119                    77
120                    77
121                    77
122                    60
123                    54
124                    61
125                    54
126                    33
127                    33
128                    30
129                    32
130                    32
131                    31
132                    20
133                    16
134                    15
135                    13
136                    11
137                    12
138                    9
139                    8
140                    8
141                    3
142                    8
143                    5
144                    3
145                    3
146                    1
147                    3
148                    0
149                    2
150                    2
151                    0
152                    1
153                    1
154                    0
155                    0
156                    0
157                    2
158                    0
159                    0
160                    0
161                    0
162                    0
163                    0
164                    0
165                    1
166                    1
```

Note: The bar at `ndraws` = 28 is consistently too high. This is rather suspect but I can't figure
out what causes it. The location of this effect doesn't vary for different values of `MAXINT`, even
though the peak of the distribution shifts around depending on inputs. It seems to be happening only
for MAXINT > 250 or so.

Less obviously, the bar at `ndraws` = 31 is consistently too low.

The effect is the same after switching to a different random number generator (`random` and
`srandom` from `stdlib.h`) but that apparently is expected because `rand` defers to `random` on
Linux.
