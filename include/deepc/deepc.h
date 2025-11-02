#ifndef DEEPC_DEEPC_H
#define DEEPC_DEEPC_H

#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #include <time.h>
// #include <ctype.h>

#define DEEPC_CHECK(condition, msg) do { \
    if (!(condition)) { \
        fprintf(stderr, "DeepC Error: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

#include "deepc/matrix.h"
#include "deepc/layers.h"
#include "deepc/models.h"
#include "deepc/losses.h"
#include "deepc/optimizers.h"
#include "deepc/data_processing.h"

#endif // DEEPC_DEEPC_H
