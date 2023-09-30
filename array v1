#include <iostream>
#include <string>

template <typename T>
class Array
{
public:
    explicit Array(size_t size, const T& value)
        : size_(size), data_(new T[size])
    {
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = value;
        }
    }

    Array(const Array& other)
        : size_(other.size_), data_(new T[other.size_])
    {
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    Array(const Array&& other)
        : size_(other.size_), data_(other.data_)
    {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    ~Array()
    {
        delete[] data_;
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    Array& operator=(Array&& other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    size_t size() const
    {
        return size_;
    }

    T& operator[](size_t idx)
    {
        return data_[idx];
    }

    const T& operator[](size_t idx) const
    {
        return data_[idx];
    }

private:
    size_t size_;
    T* data_;
};

int main()
{
    Array<int> intArray(5, 0);
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        intArray[i] = i + 1;
    }

    std::cout << "Int Array: ";
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    Array<std::string> stringArray(3, "Hello");
    stringArray[2] = "World";
    std::cout << "String Array: ";
    for (size_t i = 0; i < stringArray.size(); ++i)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
