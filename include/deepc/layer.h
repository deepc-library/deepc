#ifndef DEEPC_LAYERS_H
#define DEEPC_LAYERS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct deepc_layer deepc_layer;

struct deepc_layer 
{
    float (*activation)(float);
    float (*activation_derivative)(float);

    float* weights;
    float* biases;

    size_t input_size;
    size_t output_size;
};

void deepc_layer_forward(float* output, const deepc_layer* layer, 
    const float* input);

void deepc_layer_backward(float* input, const deepc_layer* layer, 
    const float* gradient, const float* output);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_LAYERS_H
