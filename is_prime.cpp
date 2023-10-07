#include <iostream>

template <int N, int Divisor = 2>
struct is_prime {
    static constexpr bool value = (N % Divisor != 0) && is_prime<N, Divisor + 1>::value;
};


template <int N>
struct is_prime<N, N> {
    static constexpr bool value = (N % N == 0);
};

template <>
struct is_prime<1, 2> {
    static constexpr bool value = false;
};

template <>
struct is_prime<2, 2> {
    static constexpr bool value = true;
};

int main() {
    constexpr int num = 11;

    std::cout << num << " is " << (is_prime<num>::value ? "prime." : "not prime.") << "\n";

    return 0;
}
