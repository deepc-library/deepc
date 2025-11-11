#ifndef DEEPC_VECTOR_H
#define DEEPC_VECTOR_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void deepc_vec_sum(float* rslt, const float* lhs, const float* rhs, size_t n);
void deepc_vec_sub(float* rslt, const float* lhs, const float* rhs, size_t n);
void deepc_vec_scale(float* rslt, const float* v, size_t n, float scalar);
void deepc_vec_dot(float* rslt, const float* lhs, const float* rhs, size_t n);

#ifdef __cplusplus
}
#endif

#endif
