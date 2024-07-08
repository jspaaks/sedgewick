```shell
cp --recursive template newdir
sed -i s/template/newdir/g newdir/.codeblocks/project.cbp
```

Format for the directories is e.g.

```c
#include <stdio.h>

int main (void) {
    int ivolume = 1;
    int ipage = 83;
    int ichapter = 3;
    int iexercise = 5;
    fprintf(stdout, "%01d%03d%02d%03d\n", ivolume, ipage, ichapter, iexercise);
}

# should return 108303005
```
