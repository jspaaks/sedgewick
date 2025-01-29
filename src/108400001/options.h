#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"

const KwargsClass * options_get_classes (void);
size_t options_get_nclasses (void);
size_t options_get_maxint (const Kwargs * kwargs);
void options_show_usage (void);

#endif
