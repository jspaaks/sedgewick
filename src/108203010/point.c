#include "point.h"
#include <stdlib.h>

Point point_draw (void) {
    return (Point){
        .x = (float) rand() / RAND_MAX,
        .y = (float) rand() / RAND_MAX,
    };
}
