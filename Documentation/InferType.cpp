//Call Quick Doc (Ctrl+Q on Windows/Linux, F1 on macOS) on op variable to see its type.
//Change the call arguments, check that the type is updated.

template<typename T, typename U>
auto doOperation(T t, U u) -> decltype(t + u) {
    return t + u;
}

void fun_type() {
    auto op = doOperation(3.0, 0);
}