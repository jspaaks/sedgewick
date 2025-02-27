# 109603027

```console
$ ./dist/bin/109603027 4 0 0
ERROR: Value of MOVE_FROM is same as MOVE_TO, aborting.
$ ./dist/bin/109603027 4 0 1
Linked list has 4 members:
 100 101 102 103
After moving the node from 0 to 1:
 100 101 102 103
$ ./dist/bin/109603027 4 0 2
Linked list has 4 members:
 100 101 102 103
After moving the node from 0 to 2:
 101 100 102 103
$ ./dist/bin/109603027 4 0 3
Linked list has 4 members:
 100 101 102 103
After moving the node from 0 to 3:
 101 102 100 103
$ ./dist/bin/109603027 4 0 4
ERROR: Value of MOVE_TO out of range, aborting.
```
