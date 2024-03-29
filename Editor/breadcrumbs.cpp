#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-concat-nested-namespaces"
#pragma ide diagnostic ignored "clion-misra-cpp2008-11-0-1"
//Keep track of your location in C and C++ code with the breadcrumbs –
// small markers at the bottom of the editor that help you navigate around your code.
// CLion shows namespaces, classes, structures, functions, and lambdas there.

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

void lambda_sample()
{
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << '\n';

    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';

    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';

    auto wstr = std::to_wstring(2137LL);

}

template<class T>
void foo(typename T::iterator Iter) {
    auto X = Iter;
}

namespace Person {
    namespace Agent {
        struct Bond {
            double ohseven = .007;

            auto seven() {
                return [this] {
                    return [*this] {
                        return ohseven;
                    };
                }();
            }
        };
    }  // namespace Agent
} // namespace Person

#pragma clang diagnostic pop