#ifndef DEEPC_ZERO_GENERATOR_HPP
#define DEEPC_ZERO_GENERATOR_HPP

#include <deepc/FloatGenerator.hpp>

namespace deepc {

struct ZeroGenerator : public FloatGenerator {
    explicit ZeroGenerator() = default;
    virtual float generate() override { return 0.0f; }
};

} // namespace deepc

#endif // DEEPC_ZERO_GENERATOR_HPP