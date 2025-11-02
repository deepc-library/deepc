#ifndef DEEPC_MODELS_H
#define DEEPC_MODELS_H

#include "deepc/matrix.h"
#include "deepc/layers.h"
#include "deepc/losses.h"
#include "deepc/optimizers.h"

typedef struct {
    char* name;

    deepc_layer input_layer, output_layer;
    size_t layers_size;
    
    float learning_rate;
    deepc_loss_function loss_function;

    deepc_optimizer optimizer;
    deepc_optimizer_state optimizer_state;

    bool is_compiled;
} deepc_sequential_model;

int deepc_initialize_sequential_model(deepc_sequential_model* model, 
    const char* name);

void deepc_deinitialize_sequential_model(deepc_sequential_model* model);

void deepc_add_layer(deepc_sequential_model* model, const deepc_layer* layer);

void deepc_compile(const deepc_sequential_model* model, 
    deepc_optimizer optimizer, deepc_loss_function loss, float learning_rate);

deepc_matrix deepc_predict(const deepc_sequential_module* model,
    deepc_matrix input);

void deepc_fit(deepc_sequential_model* model, deepc_matrix x, deepc_matrix y, 
    int epochs, int batch_size, int verbose);

float deepc_evaluate(const deepc_sequential_mode* model, deepc_matrix x, 
    deepc_matrix y);

void deepc_print_model_summary(const deepc_sequential_model* model);

void deepc_save_model(const deepc_sequential_model* model, 
    const char* filename);

void deepc_load_model(const char* filename);
void deepc_save_weights(deepc_sequential_model* model, const char* filename);
void deepc_load_weights(deepc_sequential_model* model, const char* filename);

#endif // DEEPC_MODELS_H
