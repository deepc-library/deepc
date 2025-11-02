#ifndef DEEPC_LAYERS_H
#define DEEPC_LAYERS_H

#include "deepc/matrix.h"

#ifdef __cpluscplus
extern "C" {
#endif

typedef enum {
    DEEPC_LINEAR,
    DEEPC_SIGMOID,
    DEEPC_RELU,
    DEEPC_TANH,
    DEEPC_SOFTMAX
} deepc_activation;

typedef struct deepc_layer {
    char* name;
    deepc_activation activation;

    size_t input_size, output_size;
    struct deepc_layer* next;
    
    deepc_matrix weights, biases;
    deepc_matrix dweights, dbiases;

    deepc_matrix input, output, z;
} deepc_layer;

void deepc_initialize_dense_layer(deepc_layer* layer, size_t units, 
    deepc_activation activation, size_t input_size);

void deepc_deinitialize_layer(const deepc_layer* layer);

deepc_matrix deepc_forward_pass(const deepc_layer* layer, deepc_matrix input);
deepc_matrix deepc_backward_pass(const deepc_layer* layer, 
    deepc_matrix gradient);

deepc_matrix deepc_apply_activation(deepc_matrix input, 
    deepc_activation activation);

deepc_matrix deepc_apply_activation_derivative(deepc_matrix input, 
    deepc_activation activation);

void deepc_initialize_weights_xavier(deepc_matrix* weights, size_t input_size);

int deepc_matrix_has_nan(deepc_matrix mat);

void deepc_save_layer(const deepc_layer* layer, const char* filename);
deepc_layer deepc_load_layer(const char* filename);

#ifdef __cpluscplus
}
#endif

#endif // DEEPC_LAYERS_H
