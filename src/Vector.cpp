#include <deepc/Vector.hpp>
#include <deepc/float.hpp>
#include <algorithm>
#include <cassert>
#include <cmath>

namespace deepc {

Vector::Vector(std::size_t size) : size_(size), data_(new float[size]) {}

Vector::Vector(const Vector& other)
    : size_(other.size_), data_(new float[other.size_]) {
    std::copy(other.data_, other.data_ + size_, data_);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;

        size_ = other.size_;
        data_ = new float[size_];

        std::copy(other.data_, other.data_ + size_, data_);
    }

    return *this;
}

Vector::Vector(Vector&& other) noexcept 
    : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data_;

        size_ = other.size_;
        other.size_ = 0;

        data_ = other.data_;
        other.data_ = nullptr;
    }

    return *this;
}

Vector::~Vector() { delete[] data_; }

float& Vector::operator[](std::size_t pos) {
    assert(pos < size_);
    return data_[pos];
}

float Vector::operator[](std::size_t pos) const {
    assert(pos < size_);
    return data_[pos];
}

bool Vector::operator==(const Vector& other) const {
    assert(size_ == other.size_);
    
    for (std::size_t i = 0; i < size_; ++i) {
        if (std::abs(data_[i] - other.data_[i]) > EPSILON) {
            return false;
        }
    }

    return true;
}

bool Vector::operator!=(const Vector& other) const {
    assert(size_ == other.size_);

    for (std::size_t i = 0; i < size_; ++i) {
        if (std::abs(data_[i] - other.data_[i]) > EPSILON) {
            return true;
        }
    }

    return false;
}

Vector& Vector::operator+=(const Vector& other) {
    assert(size_ == other.size_);

    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] += other.data_[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    assert(size_ == other.size_);

    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] -= other.data_[i];
    }

    return *this;
}

Vector& Vector::operator*=(float scalar) noexcept {
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] *= scalar;
    }

    return *this;
}

Vector& Vector::operator/=(float scalar) noexcept {
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] /= scalar;
    }

    return *this;
}

Vector Vector::operator+(const Vector& other) const {
    Vector rslt(*this);
    rslt += other;
    return rslt;
}

Vector Vector::operator-(const Vector& other) const {
    Vector rslt(*this);
    rslt -= other;
    return rslt;
}

Vector Vector::operator*(float scalar) const {
    Vector rslt(*this);
    rslt *= scalar;
    return rslt;
}

Vector Vector::operator/(float scalar) const {
    Vector rslt(*this);
    rslt /= scalar;
    return rslt;
}

float Vector::operator*(const Vector& other) const {
    assert(size_ == other.size_);

    float rslt = 0.0f;
    for (std::size_t i = 0; i < size_; ++i) {
        rslt += data_[i] * other.data_[i];
    }

    return rslt;
}

Vector operator*(float scalar, const Vector& v) { 
    return v * scalar; 
}

} // namespace deepc