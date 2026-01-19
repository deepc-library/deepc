#include <deepc/Activation.hpp>
#include <cmath>
#include <algorithm>

namespace deepc {

const Activation SIGMOID = { detail::sigmoid, detail::sigmoid_derivative };
const Activation RELU = { detail::relu, detail::relu_derivative };
const Activation TANH = { detail::tanh, detail::tanh_derivative };

} // namespace deepc

namespace deepc {
namespace detail {

float sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(x));
}

float sigmoid_derivative(float x) {
    return sigmoid(x) * (1.0f - sigmoid(x));
}

float relu(float x) {
    return std::max(0.0f, x);
}

float relu_derivative(float x) {
    return x > 0.0f ? 1.0f : 0.0f;
}

float tanh(float x) {
    return std::tanh(x);
}

float tanh_derivative(float x) {
    return 1.0f - std::tanh(x) * std::tanh(x);
}

} // namespace detail
} // namespace deepc