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
}

namespace Bond {
    struct Agent {
        double ohseven = .007;

        auto f() {
            return [this] {
                return [*this] {
                    return ohseven;
                };
            }();
        }
    };
}
