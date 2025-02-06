#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"

const KwargsClass * options_get_classes (void);
float options_get_distance (const Kwargs * kwargs);
size_t options_get_nclasses (void);
size_t options_get_npoints (const Kwargs * kwargs);
unsigned int options_get_seed (const Kwargs * kwargs);
void options_show_usage (void);

#endif
