#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"


KwargsClass * options_get_classes (void);
size_t options_get_maxint (const Kwargs * kwargs);
size_t options_get_nclasses (void);
bool options_get_report_number (const Kwargs * kwargs);
bool options_get_report_primes (const Kwargs * kwargs);
void options_show_usage (void);

#endif
