//
// Created by AK on 30/10/16.
//


template<typename T, typename U>
auto doOperation(T t, U u) -> decltype(t + u) {
    return t + u;
}

//Ask quick documentation for the type (Ctrl+Q on Linux/Windows, F1 on macOS)
void fun_type() {
    auto q = doOperation(3.0, 0);
    //...
}