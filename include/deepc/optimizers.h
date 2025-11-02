#ifndef DEEPC_OPTIMIZERS_H
#define DEEPC_OPTIMIZERS_H

#include "deepc/matrix.h"
#include "deepc/layers.h"

typedef enum {
    DEEPC_SGD,
    DEEPC_ADAM
} deepc_optimizer;

typedef struct {
    deepc_optimizer type;

    float learning_rate;
    int timestep;
    
    float beta1, beta2, epsilon;

    deepc_matrix** m_weights, **v_weights;
    deepc_matrix** m_biases, **v_biases;

    size_t max_layers_size;
} deepc_optimizer_state;

deepc_optimizer_state deepc_create_optimizer_state(deepc_optimizer optimizer, 
    float learning_rate);

void deepc_destroy_optimizer_state(
    const deepc_optimizer_state* optimizer_state);

void deepc_update_weights(deepc_layer* layer, 
    deepc_optimizer_state* optimizer_state, size_t layer_pos);

#endif // DEEPC_OPTIMIZERS_H
