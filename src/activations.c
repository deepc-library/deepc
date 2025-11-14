#include <deepc/activations.h>
#include <math.h>

float deepc_sigmoid(float x)
{
    return 1.0f / (1 + expf(-x));
}

float deepc_sigmoid_derivative(float x)
{
    return deepc_sigmoid(x) * (1.0f - deepc_sigmoid(x));
}

float deepc_relu(float x)
{
    return fmaxf(0, x);
}

float deepc_relu_derivative(float x)
{
    return x > 0.0f ? 1.0f : 0.0f;
}

float deepc_tanh(float x)
{
    return tanhf(x);
}

float deepc_tanh_derivative(float x)
{
    return 1 - tanhf(x) * tanhf(x);
}
