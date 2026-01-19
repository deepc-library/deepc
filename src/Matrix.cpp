#include <deepc/Matrix.hpp>
#include <deepc/float.hpp>
#include <algorithm>
#include <cassert>
#include <cmath>

namespace deepc {

Matrix::Matrix(std::size_t rows, std::size_t cols) 
    : rows_(rows), cols_(cols), data_(new float[rows * cols]) {}

Matrix::Matrix(const Matrix& other) 
    : rows_(other.rows_), cols_(other.cols_)
    , data_(new float[other.rows_ * other.cols_]) {
    std::copy(other.data_, other.data_ + rows_ * cols_, data_);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data_;

        rows_ = other.rows_;
        cols_ = other.cols_;

        data_ = new float[rows_, cols_];
        std::copy(other.data_, other.data_ + rows_ * cols_, data_);
    }

    return *this;
}

Matrix::Matrix(Matrix&& other) noexcept 
    : rows_(other.rows_), cols_(other.cols_), data_(other.data_) {
    other.rows_ = 0;
    other.cols_ = 0;
    other.data_ = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        
        rows_ = other.rows_;
        other.rows_ = 0;

        cols_ = other.cols_;
        other.cols_ = 0;

        data_ = other.data_;
        other.data_ = nullptr;
    }

    return *this;
}

Matrix::~Matrix() { delete[] data_; }

float* Matrix::operator[](std::size_t row) {
    assert(row < rows_);
    return data_ + row * cols_;
}

const float* Matrix::operator[](std::size_t row) const {
    assert(row < rows_);
    return data_ + row * cols_;
}

bool Matrix::operator==(const Matrix& other) const noexcept {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }

    for (std::size_t i = 0; i < rows_ * cols_; ++i) {
        if (std::abs(data_[i] - other.data_[i]) > detail::EPSILON) {
            return false;
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const noexcept {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return true;
    }

    for (size_t i = 0; i < rows_ * cols_; ++i) {
        if (abs(data_[i] - other.data_[i]) > detail::EPSILON) {
            return true;
        }
    }

    return false;
}

} // namespace deepc