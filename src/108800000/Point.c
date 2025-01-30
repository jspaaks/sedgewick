#include "Point.h"
#include <math.h>

float distance(struct point a, struct point b)
  { float dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
  }
