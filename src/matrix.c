#include "deepc/matrix.h"

void deepc_mat_sum(float* rslt, const float* lhs, const float* rhs, size_t n) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = lhs[i] + rhs[i];
    }
}

void deepc_mat_sub(float* rslt, const float* lhs, const float* rhs, size_t n) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = lhs[i] - rhs[i];
    }
}

void deepc_mat_scale(float* rslt, const float* m, size_t n, float scalar) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = m[i] * scalar;
    }
}

void deepc_mat_hprod(float* rslt, const float* lhs, const float* rhs, size_t n)
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = lhs[i] * rhs[i];
    }
}

void deepc_mat_mul(float* rslt, const float* lhs, const float* rhs, size_t m, 
    size_t n, size_t p)
{
    for (size_t i = 0; i < m; ++i) 
    {
        for (size_t j = 0; j < p; ++j) 
        {
            rslt[i * p + j] = 0.0f;

            for (size_t k = 0; k < n; ++k) 
            {
                rslt[i * p + j] += lhs[i * n + k] * rhs[k * p + j]; 
            }
        }
    }
}

void deepc_mat_vec_mul(float* rslt, const float* lhs, const float* rhs, 
    size_t m, size_t n)
{
    for (size_t i = 0; i < m; ++i)
    {
        rslt[i] = 0.0f;

        for (size_t j = 0; j < n; ++j) 
        {
            rslt[i] += lhs[i * n + j] * rhs[j];
        }
    }
}

void deepc_mat_transpose(float* rslt, const float* m, size_t nr, size_t nc) 
{
    for (size_t i = 0; i < nr; ++i) 
    {
        for (size_t j = 0; j < nc; ++j) 
        {
            rslt[j * nr + i] = m[i * nc + j];
        }
    }
}
