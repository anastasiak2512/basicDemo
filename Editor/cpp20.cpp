#include <iostream>
#include <vector>

// Explicit(bool)
#define LEVEL_NUM 100

constexpr bool abc(int num) {
    return (num > LEVEL_NUM);
}

class Foo {
public:
    explicit(abc(1)) Foo(){ abc(1);}
};

// Range-based for loop with initializer
void test() {
    std::vector<int> vec = {1, 3, 5, 7, 9};

    for (auto sz = vec.size(); auto item : vec) {
        std::cout << --sz + item << ' ';
    }
}

// Designated initializer
struct Person
{
    std::string name{};
    std::string surname{};
    unsigned age{};
};

struct Employee : public Person
{
    unsigned salary{10000};
};

int main() {
    Employee emp { {.name="John", .surname="Wick", .age=40}, 5000};

    std::cout << emp.name << " " << emp.surname << ": age "
              << emp.age << ", " << emp.salary << "\n";

    return 0;
}