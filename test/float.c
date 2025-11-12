#include "deepc/float.h"
#include <assert.h>

const float epsilon = 1e-6f;

void test_are_floats_equal()
{
    assert(deepc_are_floats_equal(5.0f, 5.0f, epsilon));
}

void test_are_floats_unequal()
{
    assert(!deepc_are_floats_equal(5.0f, 4.0f, epsilon));
}

void test_are_float_arrays_equal()
{
    float v1[] = {2.0f, 3.0f};
    float v2[] = {2.0f, 3.0f};
    assert(deepc_are_float_arrays_equal(v1, v2, 2, epsilon));
}

void test_are_float_arrays_unequal()
{
    float v1[] = {2.0f, 3.0f};
    float v2[] = {2.0f, 4.0f};
    assert(!deepc_are_float_arrays_equal(v1, v2, 2, epsilon));
}

int main()
{
    test_are_floats_equal();
    test_are_floats_unequal();
    test_are_float_arrays_equal();
    test_are_float_arrays_unequal();
}
