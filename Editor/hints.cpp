#include <iostream>
#include <functional>

// More for lambdas in TypeDebug.cpp
// And in ExtractLambda.cpp

std::function<int(int)> F(int count)
{
    return [](int m) { return 0; };
}

//Go to type navigation via Ctrl/Cmd + Click

class Foo {

};
template<typename T>
class Bar {};
void func(const Bar<Foo>& c) {
    auto f = c;
}
//=====================

int main() {
    int a = 1, b = 2;
    const auto&[x, y] = std::tie(a, b);

    const auto tuple = std::make_tuple(1, 'a', 2.3);
    const auto& [i, c, d] = tuple;
}

