#ifndef DEEPC_MATRIX_H
#define DEEPC_MATRIX_H

#include "deepc/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

void deepc_mat_sum(float* rslt, const float* lhs, const float* rhs, size_t n);
void deepc_mat_sub(float* rslt, const float* lhs, const float* rhs, size_t n);
void deepc_mat_scale(float* rslt, const float* m, size_t n, float scalar);
void deepc_mat_hprod(float* rslt, const float* lhs, const float* rhs, size_t n);
void deepc_mat_vec_mul(float* rslt, const float* lhs, const float* rhs, 
    size_t m, size_t n);
void deepc_mat_mul(float* rslt, const float* lhs, const float* rhs, size_t m, 
    size_t n, size_t p);
void deepc_mat_transpose(float* rslt, const float* m, size_t nr, size_t nc);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_MATRIX_H
