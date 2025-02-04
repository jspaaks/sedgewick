#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"
#include <stdint.h>
#include <stdlib.h>

KwargsClass * options_get_classes (void);
uint16_t options_get_maxint (const Kwargs * kwargs);
size_t options_get_nclasses (void);
size_t options_get_nrand (const Kwargs * kwargs);
bool options_get_report_occurrences (const Kwargs * kwargs);
bool options_get_report_unique (const Kwargs * kwargs);
void options_show_usage (void);

#endif
