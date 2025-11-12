#include "deepc/vector.h"
#include "deepc/float.h"
#include <assert.h>

const float epsilon = 1e-6f;

void test_vector_length()
{
    float v[] = {3.0f, 4.0f};
    float length = deepc_vector_length(v, 2);
    assert(deepc_are_floats_equal(length, 5.0f, epsilon));
}

void test_vector_normalize()
{
    float v[] = {3.0f, 4.0f};
    float v_normalized_true[] = {3.0f / 5.0f, 4.0f / 5.0f};

    float v_normalized_expected[2];
    deepc_vector_normalize(v_normalized_expected, v, 2);

    assert(deepc_are_float_arrays_equal(v_normalized_true, 
        v_normalized_expected, 2, epsilon));

}

void test_vector_sum()
{
    float v1[] = {1.0f, 2.0f};
    float v2[] = {3.0f, 4.0f};
    float true_sum[] = {4.0f, 6.0f};

    float expected_sum[2];
    deepc_vector_sum(expected_sum, v1, v2, 2);

    assert(deepc_are_float_arrays_equal(true_sum, expected_sum, 2, epsilon));
}

void test_vector_subtract()
{
    float v1[] = {1.0f, 2.0f};
    float v2[] = {3.0f, 4.0f};
    float true_diff[] = {-2.0f, -2.0f};

    float expected_diff[2];
    deepc_vector_subtract(expected_diff, v1, v2, 2);

    assert(deepc_are_float_arrays_equal(true_diff, expected_diff, 2, epsilon));
}

void test_vector_scale()
{
    float v[] = {2.0f, 3.0f};
    float scalar = 2.0f;
    float true_scaled_v[] = {4.0f, 6.0f};

    float expected_scaled_v[2];
    deepc_vector_scale(expected_scaled_v, v, 2, scalar);

    assert(deepc_are_float_arrays_equal(true_scaled_v, expected_scaled_v, 2, 
        epsilon));
}

int main()
{
    test_vector_length();
    test_vector_normalize();
    test_vector_sum();
    test_vector_subtract();
    test_vector_scale();
}
