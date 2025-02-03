# 108903015

Reference program 3.5 (Sieve of Eratosthenes) can't work correctly for N=1000000 due to integer
overflow, so instead used program `./108903013 -n 1000000` which uses an integer type which is
larger and additionally unsigned.

By comparison, the program is slower when skipping the `if (a[i])` check. This is because by
removing the check, the program reassigns zeros where there are zeros already, e.g. for `i=4`, you
assign about half of the zeros you already assigned when evaluating `i=2`.
