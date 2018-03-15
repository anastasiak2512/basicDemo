//To simplify complicated code with lots of nested statements, unwrap/remove code block
//can be used. Use Code -> Unwrap/Remove… action (Ctrl+Shift+Delete on Linux/Windows, ⌘⇧⌦ on macOS)
//
// In CLion for C and C++ you can now unwrap the following control statements: if, else, while,
// do...while, for, try...catch, or just remove the enclosing statement (for example, when you’d
// like to extract a part of a ternary operator expression).

#include <iostream>

void unwrap_ternary_sample(int a, int b) {
    auto x = (a < b) ? (b*b) : (-b)*a;
}

void unwrap_cond_sample(int n) {
    if (n > 0) {
        std::cout << "Hello!\n";
    }
    std::cout << "Unwrap the condition\n";
}
