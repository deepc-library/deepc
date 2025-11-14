#include <deepc/layer.h>
#include <deepc/float.h>
#include <deepc/activations.h>
#include <cassert>

const float epsilon = 1e-6f;

int main()
{
    float weights[] = 
    {
        1.0f, -2.0f, 2.0f, 
        -3.0f, 3.0f, -4.0f
    };

    float biases[] = {2.0f, -3.0f};

    size_t input_size = 3;
    size_t output_size = 2;

    deepc_layer layer;
    deepc_dense_layer_initialize(&layer, weights, biases, input_size, 
        output_size, deepc_relu, deepc_relu_derivative);
}
