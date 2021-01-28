//Call Quick Doc (Ctrl+Q on Windows/Linux, F1 on macOS) on foo variable to see its type.
//Find Usages on the first foo declaration to get the different between text and context searches.
#include <iostream>

// Sample 1 - highlight overloads at caret
template <class T> int foo(T & t)   { return 1; }
template <class T> int foo(T && t)  { return 2; }
int foo(signed char t)              { return 3; }
int foo(unsigned char t)            { return 4; }
int foo(int)                        { return 5; }

int main() {
    auto C = 'C';
    std::cout << foo(C) << foo('C')
              << foo('C++') << foo("C++");
}

// Sample 2 -
template <typename T>
auto get_value(T t) {
    if constexpr (std::is_pointer<T>::value)
        return *t;
    else
        return t;
}

void test()
{
    auto pi = std::make_unique<int>(9);
    int i = 9;

    std::cout << get_value(pi.get()) << "\n";
    std::cout << get_value(i) << "\n";
}