#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "clion-misra-cpp2008-0-1-7"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-magic-numbers"
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

    auto wstr = std::to_wstring(2137LL);
}

template<class T>
void foo(typename T::iterator Iter) {
    auto X = Iter;
}

#include <deque>

struct Point {
    Point(int x, int y) {}
};

void deg_handle() {
    std::deque<Point> deq;

    deq.emplace_front(1, 2);
    deq.emplace_back(1, 2);
    deq.emplace(deq.begin(), 1, 2);
}

#pragma clang diagnostic pop