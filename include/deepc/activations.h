#ifndef DEEPC_ACTIVATIONS_H
#define DEEPC_ACTIVATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

float deepc_sigmoid(float x);
float deepc_relu(float x);
float deepc_tanh(float x);

float deepc_sigmoid_derivative(float x);
float deepc_relu_derivative(float x);
float deepc_tanh_derivative(float x);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_ACTIVATIONS_H
