#ifndef DEEPC_FLOAT_GENERATOR_HPP
#define DEEPC_FLOAT_GENERATOR_HPP

namespace deepc {

struct FloatGenerator {
    virtual float generate() = 0;
};

} // namespace deepc

#endif // DEEPC_FLOAT_GENERATOR_HPP