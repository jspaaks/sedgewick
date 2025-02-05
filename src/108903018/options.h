#ifndef OPTIONS_H
#define OPTIONS_H
#include "kwargs/kwargs.h"
#include <stdint.h>
#include <stdlib.h>

const KwargsClass * options_get_classes (void);
uint16_t options_get_maxint (const Kwargs * kwargs);
size_t options_get_nclasses (void);
uint16_t options_get_ncolsmax (const Kwargs * kwargs);
bool options_get_no_distribution (const Kwargs * kwargs);
bool options_get_no_outcomes (const Kwargs * kwargs);
size_t options_get_ntrials (const Kwargs * kwargs);
unsigned int options_get_seed(const Kwargs * kwargs);
void options_show_usage (void);

#endif
