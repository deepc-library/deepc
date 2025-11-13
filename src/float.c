#include <deepc/float.h>
#include <math.h>

bool deepc_floats_equal(float x, float y, float epsilon)
{
    return fabsf(x - y) < epsilon;
}

bool deepc_float_arrays_equal(const float* v1, const float* v2, size_t n,
    float epsilon)
{
    for (size_t i = 0; i < n; ++i) 
    {
        if (fabsf(v1[i] - v2[i]) >= epsilon)
        {
            return false;
        }
    }

    return true;
}
