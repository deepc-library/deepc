#ifndef DEEPC_FLOAT_H
#define DEEPC_FLOAT_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

bool deepc_floats_equal(float x, float y, float epsilon);

bool deepc_float_arrays_equal(const float* v1, const float* v2, size_t n, 
    float epsilon);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_FLOAT_H
