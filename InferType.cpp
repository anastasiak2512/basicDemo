//
// Created by AK on 30/10/16.
//

#include "InferType.h"

template<typename T, typename U>
auto doOperation(T t, U u) -> decltype(t + u) {
    return t + u;
}

//Ask quick documentation for the type
void fun_type() {
    auto q = doOperation(3.0, 3);
    //...
}