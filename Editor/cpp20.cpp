#include <iostream>

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

#define LEVEL_NUM 100

constexpr bool abc(int num) {
    return (num > LEVEL_NUM);
}

class Foo {
public:
    explicit(abc(1)) Foo(){ abc(1);}
};

void printThisInteger(int) {}

int main() {
    Employee emp { {.name="John", .surname="Wick", .age=40}, 5000};

    std::cout << emp.name << " " << emp.surname << ": age "
              << emp.age << ", " << emp.salary << "\n";

    printThisInteger(10);
    return 0;
}