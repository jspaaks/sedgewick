# 109603026

```console
$ ./dist/bin/109603026 5 3 0
First linked list has 5 members:
 1 2 3 4 5
Second linked list has 3 members:
 101 102 103
After inserting the second list into the first list at position 0:
 101 102 103 1 2 3 4 5
$ ./dist/bin/109603026 5 3 1
First linked list has 5 members:
 1 2 3 4 5
Second linked list has 3 members:
 101 102 103
After inserting the second list into the first list at position 1:
 1 101 102 103 2 3 4 5
$ ./dist/bin/109603026 5 3 5
First linked list has 5 members:
 1 2 3 4 5
Second linked list has 3 members:
 101 102 103
After inserting the second list into the first list at position 5:
 1 2 3 4 5 101 102 103
$ ./dist/bin/109603026 5 3 6
ERROR: Value of INSERT_AT out of range, aborting.
```
