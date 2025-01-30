#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"

size_t options_get_ntosses (const Kwargs * kwargs);
size_t options_get_ntrials (const Kwargs * kwargs);
void options_show_usage (void);

#endif
