#ifndef DEEPC_LOSSES_H
#define DEEPC_LOSSES_H

#include "deepc/matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DEEPC_MEAN_SQUARED_ERROR,
    DEEPC_BINARY_CROSSENTROPY,
    DEEPC_CATEGORICAL_CROSSENTROPY
} deepc_loss_function;

float deepc_compute_loss(deepc_matrix y_true, deepc_matrix y_pred, 
    deepc_loss_function loss_func);

deepc_matrix deepc_compute_loss_gradient(deepc_matrix y_true, 
    deepc_matrix y_pred, deepc_loss_function loss_func);

float deepc_mse_loss(deepc_matrix y_true, deepc_matrix y_pred);
deepc_matrix deepc_mse_gradient(deepc_matrix y_true, deepc_matrix y_pred);

float deepc_binary_crossentropy_loss(deepc_matrix y_true, deepc_matrix y_pred);
deepc_matrix deepc_binary_crossentropy_gradient(deepc_matrix y_true, 
    deepc_matrix y_pred);

float deepc_categorical_crossentropy_loss(deepc_matrix y_true, 
    deepc_matrix y_pred);

deepc_matrix deepc_categorical_crossentropy_gradient(deepc_matrix y_true, 
    deepc_matrix y_pred);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_LOSSES_H
