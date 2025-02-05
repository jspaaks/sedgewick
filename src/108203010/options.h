#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"
#include <stddef.h>

bool options_get_report_avg (const Kwargs * kwargs);
bool options_get_report_areas (const Kwargs * kwargs);
bool options_get_report_max (const Kwargs * kwargs);
bool options_get_report_triangles (const Kwargs * kwargs);
const KwargsClass * options_get_classes (void);
size_t options_get_nclasses (void);
size_t options_get_ntriangles (const Kwargs * kwargs);
void options_show_usage (void);

#endif
