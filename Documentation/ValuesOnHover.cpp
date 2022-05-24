// Quick Documentation is now capable of evaluating certain values through clangd and DFA.
// See the examples below and hover over symbols near the comments.

#include <random>
#include <memory>
#include <stdint.h>

enum class Color {
    Red,
    Blue,
    Green
};

constexpr int factorial(int n) {
    return n > 0 ? n * factorial(n - 1) : 1;
}

int test(int x) {
    auto col = Color::Red; // hover on 'Red'
    auto col2 = col; // hover on 'col', tracked by DFA through assignments

    if (x >= 10)
        if (x <= 20) {
            return x; // Value range: DFA evaluated a range of possible values for a given variable
        }

    auto a = factorial(5); // evaluates consteval / constexpr function calls

    int b;
    if (random())
        b = 1;
    else
        b = 2;

    return b; // Possible values: DFA evaluated a set of possible values for a given variable
}

struct Resource {};

struct Foo { // Classes/Structs: Shows size (in bytes) and whether they are copy/move-constructible or -assignable. If not listed, the operation is disabled.
    std::unique_ptr<Resource> resource;
};

struct Str {
    uint32_t value;
    uint8_t other; // Class members: Shows size (in bytes), offset and padding (if non-zero):
};