#include <deepc/activations.h>
#include <deepc/float.h>
#include <cmath>
#include <cassert>

const float epsilon = 1e-6f;

void test_sigmoid()
{
    float x = 2.0f;
    float expected_value = deepc_sigmoid(x);

    float true_value = 1.0f / (1 + expf(-x));
    assert(deepc_floats_equal(expected_value, true_value, epsilon));
}

void test_sigmoid_derivative()
{
    float x = 2.0f;
    float expected_value = deepc_sigmoid_derivative(x);

    float true_value = deepc_sigmoid(x) * (1.0f - deepc_sigmoid(x));
    assert(deepc_floats_equal(expected_value, true_value, epsilon));
}

void test_relu()
{
    float x1 = 2.0f;
    float expected_value1 = deepc_relu(x1);

    float true_value1 = 2.0f;
    assert(deepc_floats_equal(expected_value1, true_value1, epsilon));

    float x2 = -2.0f;
    float expected_value2 = deepc_relu(x2);

    float true_value2 = 0.0f;
    assert(deepc_floats_equal(expected_value2, true_value2, epsilon));
}

void test_relu_derivative()
{
    float x1 = 2.0f;
    float expected_value1 = deepc_relu_derivative(x1);

    float true_value1 = 1.0f;
    assert(deepc_floats_equal(expected_value1, true_value1, epsilon));

    float x2 = -2.0f;
    float expected_value2 = deepc_relu_derivative(x2);

    float true_value2 = 0.0f;
    assert(deepc_floats_equal(expected_value2, true_value2, epsilon));
}

void test_tanh()
{
    float x = 2.0f;
    float expected_value = deepc_tanh(x);

    float true_value = tanhf(x);
    assert(deepc_floats_equal(expected_value, true_value, epsilon));
}

void test_tanh_derivative()
{
    float x = 2.0f;
    float expected_value = deepc_tanh_derivative(x);

    float true_value = 1 - tanhf(x) * tanhf(x);
    assert(deepc_floats_equal(expected_value, true_value, epsilon));
}

int main()
{
    test_sigmoid();
    test_sigmoid_derivative();
    test_relu();
    test_relu_derivative();
    test_tanh();
    test_tanh_derivative();
}
