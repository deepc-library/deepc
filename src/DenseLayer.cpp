#include <deepc/DenseLayer.hpp>

namespace deepc {

DenseLayer::DenseLayer(std::size_t output_size, std::size_t input_size, 
    const Activation& activation, float learning_rate) 
    : Layer(learning_rate), weights_(output_size, input_size)
    , biases_(output_size), z_(output_size), activation_(activation) {}

Vector DenseLayer::forward(const Vector& input) {
    Vector output(weights_.rows());

    for (std::size_t i = 0; i < weights_.rows(); ++i) {
        z_[i] = biases_[i];
        for (std::size_t j = 0; j < weights_.cols(); ++j) {
            z_[i] += weights_[i][j] * input[j];
        }
        output[i] = activation_.function(z_[i]);
    }

    return output;
}

// This function is clearly const, should I change superclass's method
// declaration?
Vector DenseLayer::backward(const Vector& forward_delta) {
    // Should I implement a new Vector constructor to fill the vector with 
    // zeros? Update: Maybe a fill() method is better.
    Vector delta(weights_.cols());
    for (std::size_t j = 0; j < weights_.cols(); ++j) {
        delta[j] = 0.0f;
    }

    for (std::size_t i = 0; i < weights_.rows(); ++i) {
        for (std::size_t j = 0; j < weights_.cols(); ++j) {
            delta[j] += weights_[i][j] * forward_delta[i] * 
                activation_.derivative(z_[i]);
        }
    }

    return delta;
}

void DenseLayer::update(const Vector& input, const Vector& delta) {
    for (std::size_t i = 0; i < weights_.rows(); ++i) {
        for (std::size_t j = 0; j < weights_.cols(); ++j) {
            weights_[i][j] -= learning_rate_ * input[j] * delta[i];
        }

        biases_[i] -= learning_rate_ * delta[i];
    }
}

} // namespace deepc