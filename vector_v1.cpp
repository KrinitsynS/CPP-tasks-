template<typename T>
T* safe_copy(const T* src, size_t srcsize, size_t dstsize) {
    T* newarr = new T[dstsize];
    try {
        for (size_t idx = 0; idx < srcsize; ++idx)
            newarr[idx] = src[idx];
    } catch (...) {
        delete[] newarr;
        throw;
    }
    return newarr;
}
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class MyVector {
    T* arr_ = nullptr;
    size_t size_ = 0, used_ = 0;

public:
    explicit MyVector(size_t sz = 0) : size_(sz), arr_(new T[sz]) {}

    MyVector(const MyVector& rhs) : size_(rhs.size_), used_(rhs.used_), arr_(safe_copy(rhs.arr_, rhs.used_, rhs.size_)) {}

    MyVector(MyVector&& rhs) noexcept : arr_(rhs.arr_), size_(rhs.size_), used_(rhs.used_) {
        rhs.arr_ = nullptr;
        rhs.size_ = 0;
        rhs.used_ = 0;
    }

    MyVector& operator=(MyVector&& rhs) noexcept {
        delete[] arr_;
        arr_ = rhs.arr_;
        size_ = rhs.size_;
        used_ = rhs.used_;
        rhs.arr_ = nullptr;
        rhs.size_ = 0;
        rhs.used_ = 0;
        return *this;
    }

    MyVector& operator=(const MyVector& rhs) {
        if (this != &rhs) {
            T* newArr = safe_copy(rhs.arr_, rhs.used_, rhs.size_);
            delete[] arr_;
            arr_ = newArr;
            size_ = rhs.size_;
            used_ = rhs.used_;
        }
        return *this;
    }

    ~MyVector() {
        delete[] arr_;
    }

    void pop() {
        if (used_ == 0)
            throw std::runtime_error("Vector is empty");
        --used_;
    }

    T& top() {
        if (used_ == 0)
            throw std::runtime_error("Vector is empty");
        return arr_[used_ - 1];
    }

    void push(const T& t) {
        if (used_ == size_) {
            std::cout << "Realloc\n";
            size_t newCapacity = (size_ == 0) ? 1 : size_ * 2;
            T* newArr = safe_copy(arr_, used_, newCapacity);
            delete[] arr_;
            arr_ = newArr;
            size_ = newCapacity;
        }
        arr_[used_++] = t;
    }

    T& at(size_t idx) {
        if (idx >= used_)
            throw std::out_of_range("Index out of range");
        return arr_[idx];
    }

    T& operator[](size_t idx) {
        return arr_[idx];
    }

    size_t size() const {
        return used_;
    }

    size_t capacity() const {
        return size_;
    }
};
