#pragma clang diagnostic push
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-0-4"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-c-arrays"
//
// Created by AK on 31.05.2022.
//

// Easy sample

#include <iostream>

constexpr int foo() {
    if (std::is_constant_evaluated()) {
        return 100;
    } else {
        return 200;
    }
}

int main() {
    constexpr int f = foo();
    std::cout << "f is " << f;
    return f;
}


#include <cstring>

// Constants

#define MAX_ARR_SIZE 200

const size_t MAGIC_NUM = 7;

struct MySpecialType {
    int size;
    float value;
    char arr[MAX_ARR_SIZE];
};

constexpr auto magic = (sizeof(MySpecialType) * MAGIC_NUM);


// Consteval

#include <algorithm>
#include <array>
#include <numeric>

template <class T, std::size_t N>
constexpr T sumArray(const std::array<T, N> &arr) {
    T sum = 0;
    for (const auto &elem : arr) {
        sum += elem;
    }
    return sum;
}

int calc_sum() {
    constexpr std::array<int, 5> arr{1, 2, 3, 4, 5};
    constexpr auto sum = sumArray(arr);
    return sum;
}


// Template magic


template <int n> struct fibonacci {
    static constexpr int value =
            fibonacci<n - 1>::value + fibonacci<n - 2>::value;
};

template <> struct fibonacci<0> {
    static constexpr int value = 0;
};

template <> struct fibonacci<1> {
    static constexpr int value = 1;
};

int fib_calc() {
    constexpr auto value = fibonacci<10>::value;
    return value;
}

#pragma clang diagnostic pop