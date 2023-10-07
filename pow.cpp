#include <iostream>

template <int Base, int Exp>
struct Power {
    static constexpr int value = Base * Power<Base, Exp - 1>::value;
};

template <int Base>
struct Power<Base, 0> {
    static constexpr int value = 1;
};

template <int Base>
struct Power<Base, 1> {
    static constexpr int value = Base;
};

template <int Base, int Exp>
constexpr int pow() {
    return Power<Base, Exp>::value;
}

int main() {
    constexpr int base = 2;
    constexpr int exponent = 5;

    constexpr int result = pow<base, exponent>();

    std::cout << base << " to the power of " << exponent << " = " << result << "\n";

    return 0;
}
