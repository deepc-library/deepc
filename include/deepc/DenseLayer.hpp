#ifndef DEEPC_DENSE_LAYER_HPP
#define DEEPC_DENSE_LAYER_HPP

#include <deepc/Layer.hpp>
#include <deepc/Activation.hpp>
#include <deepc/Matrix.hpp>

namespace deepc {

class DenseLayer : public Layer {
public:
    DenseLayer(std::size_t output_size, std::size_t input_size, 
        const Activation& activation, float learning_rate);

    Activation activation() { return activation_; }
    Matrix weights() { return weights_; }
    Vector biases() { return biases_; }

    virtual Vector forward(const Vector& input) override;
    virtual Vector backward(const Vector& forward_delta) override;
    virtual void update(const Vector& input, const Vector& delta) override;
private:
    Matrix weights_;
    Vector biases_;

    Vector z_;
    Activation activation_;
};

} // namespace deepc

#endif // DEEPC_DENSE_LAYER_HPP