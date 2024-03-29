//Call Quick Doc (Ctrl+Q on Windows/Linux, F1 on macOS) on op variable to see its type.
//Change the call arguments, check that the type is updated.
#include <iostream>

template<typename T, typename U>
auto doOperation(T t, U u) -> decltype(t + u) {
    return t + u;
}

void fun_type() {
    auto op = doOperation(3, 0);
    auto op1 = doOperation(3L, 0);
    auto op2 = doOperation(3.0, 0);

    std::cout << op << " " << op1 << " " << op2;
}