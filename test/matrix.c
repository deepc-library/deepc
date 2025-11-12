#include <deepc/matrix.h>
#include <deepc/float.h>
#include <assert.h>

const float epsilon = 1e-6f;

void test_matrix_sum()
{
    float m1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float m2[] = {2.0f, 3.0f, 4.0f, 5.0f};

    float expected_value[4];
    deepc_matrix_sum(expected_value, m1, m2, 4);

    float true_value[] = {3.0f, 5.0f, 7.0f, 9.0f};
    assert(deepc_are_float_arrays_equal(expected_value, true_value, 4, 
        epsilon));
}

void test_matrix_subtract()
{
    float m1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float m2[] = {2.0f, 3.0f, 4.0f, 5.0f};

    float expected_value[4];
    deepc_matrix_subtract(expected_value, m1, m2, 4);

    float true_value[] = {-1.0f, -1.0f, -1.0f, -1.0f};
    assert(deepc_are_float_arrays_equal(expected_value, true_value, 4, 
        epsilon));
}

void test_matrix_scale()
{
    float m[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float scalar = 2.0f;

    float expected_value[4];
    deepc_matrix_scale(expected_value, m, 4, scalar);

    float true_value[] = {2.0f, 4.0f, 6.0f, 8.0f};
    assert(deepc_are_float_arrays_equal(expected_value, true_value, 4, 
        epsilon));
}

void test_matrix_hadamard_product()
{   
    float m1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float m2[] = {2.0f, 3.0f, 4.0f, 5.0f};

    float expected_value[4];
    deepc_matrix_hadamard_product(expected_value, m1, m2, 4);

    float true_value[] = {2.0f, 6.0f, 12.0f, 20.0f};
    assert(deepc_are_float_arrays_equal(expected_value, true_value, 4, 
        epsilon));
}

void test_matrix_vector_multiply()
{
    float m[] = 
    {
        1.0f, 2.0f, 
        3.0f, 4.0f, 
        5.0f, 6.0f
    };

    float v[] = {1.0f, 2.0f};

    float expected_value[3];
    deepc_matrix_vector_multiply(expected_value, m, v, 3, 2);

    float true_value[] = {5.0f, 11.0f, 17.0f};
    assert(deepc_are_float_arrays_equal(expected_value, true_value, 3, 
        epsilon));
}

void test_matrix_multiply()
{
    float m1[] = 
    {
        1.0f, 2.0f, 3.0f, 
        4.0f, 5.0f, 6.0f
    };

    float m2[] = 
    {
        2.0f, 3.0f, 
        4.0f, 5.0f, 
        6.0f, 7.0f
    };

    float expected_value[4];
    deepc_matrix_multiply(expected_value, m1, m2, 2, 3, 2);

    float true_value[] = 
    {
        2.0f + 8.0f + 18.0f, 3.0f + 10.0f + 21.0f,
        8.0f + 20.0f + 36.0f, 12.0f + 25.0f + 42.0f
    };

    assert(deepc_are_float_arrays_equal(expected_value, true_value, 4, 
        epsilon));
}

void test_matrix_transpose()
{
    float m[] = 
    {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    };

    float expected_value[6];
    deepc_matrix_transpose(expected_value, m, 2, 3);

    float true_value[] =
    {
        1.0f, 4.0f, 
        2.0f, 5.0f, 
        3.0f, 6.0f
    };

    assert(deepc_are_float_arrays_equal(expected_value, true_value, 6, 
        epsilon));
}

int main()
{
    test_matrix_sum();
    test_matrix_subtract();
    test_matrix_scale();
    test_matrix_hadamard_product();
    test_matrix_vector_multiply();
    test_matrix_transpose();
}
