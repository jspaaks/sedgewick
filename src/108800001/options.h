#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"

size_t options_get_npoints (const Kwargs * kwargs);
float options_get_distance (const Kwargs * kwargs);
void options_show_usage (void);

#endif
