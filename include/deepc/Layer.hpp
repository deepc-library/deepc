#ifndef DEEPC_LAYER_HPP
#define DEEPC_LAYER_HPP

#include <deepc/Vector.hpp>

namespace deepc {

class Layer {
public:
    explicit Layer(float learning_rate);

    virtual Vector forward(const Vector& input) = 0;
    virtual Vector backward(const Vector& forward_delta) = 0;
    virtual void update(const Vector& input, const Vector& delta) = 0;

    float learning_rate() noexcept { return learning_rate_; }
protected:
    // Is it better to store learning_rate as a class member, or pass it to 
    // update()?
    float learning_rate_;
};

} // namespace deepc

#endif // DEEPC_LAYER_HPP