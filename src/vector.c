#include "deepc/vector.h"

void deepc_vec_sum(float* rslt, const float* lhs, const float* rhs, size_t n) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = lhs[i] + rhs[i];
    }
}

void deepc_vec_sub(float* rslt, const float* lhs, const float* rhs, size_t n) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = lhs[i] - rhs[i];
    }
}

void deepc_vec_scale(float* rslt, const float* v, size_t n, float scalar) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        rslt[i] = v[i] * scalar;
    }
}

float deepc_vec_dot(float* rslt, const float* lhs, const float* rhs, size_t n) 
{
    float rslt = 0.0f;

    for (size_t i = 0; i < n; ++i) 
    {
        rslt += lhs[i] * rhs[i];
    }   

    return rslt;
}
