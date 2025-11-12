#include "deepc/vector.h"
#include "deepc/float.h"
#include <assert.h>

const float epsilon = 1e-6f;

void test_vector_length()
{
    float v[] = {3.0f, 4.0f};

    float expected_value = deepc_vector_length(v, 2);
    float true_value = 5.0f;

    assert(deepc_are_floats_equal(expected_value, true_value, epsilon));
}

void test_vector_normalize()
{
    float v[] = {3.0f, 4.0f};

    float expected_value[2];
    deepc_vector_normalize(expected_value, v, 2);

    float true_value[] = {3.0f / 5.0f, 4.0f / 5.0f};

    assert(deepc_are_float_arrays_equal(expected_value, true_value, 2, 
        epsilon));

}

void test_vector_sum()
{
    float v1[] = {1.0f, 2.0f};
    float v2[] = {3.0f, 4.0f};

    float expected_value[2];
    deepc_vector_sum(expected_value, v1, v2, 2);

    float true_value[] = {4.0f, 6.0f};

    assert(deepc_are_float_arrays_equal(expected_value, true_value, 2, 
        epsilon));
}

void test_vector_subtract()
{
    float v1[] = {1.0f, 2.0f};
    float v2[] = {3.0f, 4.0f};

    float expected_value[2];
    deepc_vector_subtract(expected_value, v1, v2, 2);

    float true_value[] = {-2.0f, -2.0f};

    assert(deepc_are_float_arrays_equal(expected_value, true_value, 2, 
        epsilon));
}

void test_vector_scale()
{
    float v[] = {2.0f, 3.0f};
    float scalar = 2.0f;

    float expected_value[2];
    deepc_vector_scale(expected_value, v, 2, scalar);

    float true_value[] = {4.0f, 6.0f};

    assert(deepc_are_float_arrays_equal(expected_value, true_value, 2, 
        epsilon));
}

void test_vector_dot_product()
{
    float v1[] = {2.0f, 3.0f};
    float v2[] = {3.0f, 4.0f}; 

    float expected_value = deepc_vector_dot_product(v1, v2, 2); 
    float true_value = 18.0f;

    assert(deepc_are_floats_equal(expected_value, true_value, 2));
}

int main()
{
    test_vector_length();
    test_vector_normalize();
    test_vector_sum();
    test_vector_subtract();
    test_vector_scale();
    test_vector_dot_product();
}
