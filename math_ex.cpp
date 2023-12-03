#include <iostream>
#include <exception>
#include <string>

class MathException : public std::exception {
private:
    std::string message;

public:
    MathException() : message("Math error occurred") {}

    explicit MathException(const std::string& errorMessage) : message(errorMessage) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class DivideByZeroException : public MathException {
public:
    DivideByZeroException() : MathException("Division by zero error occurred") {}

    explicit DivideByZeroException(const std::string& errorMessage) : MathException(errorMessage) {}
};

int divide(int x, int y) {
    if (y == 0) throw DivideByZeroException();
    return x / y;
}

int main() {
    try {
        int result = divide(8, 0);
    } catch (const MathException& e) {
        std::cout << "Math error occurred: " << e.what() << std::endl;
    }

    return 0;
}
