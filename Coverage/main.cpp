#include <string>
#include <iostream>
#include <utility>

class Foo {
    std::string str;
public:
    explicit Foo(std::string str) : str(std::move(str)) {
        std::cout << "Run Foo(std::string str)" << std::endl;
    }

    Foo(Foo &f) {
        std::cout << "Run Foo(Foo &f)" << std::endl;
    }

    Foo(Foo const &foo) {
        std::cout << "Run Foo(Foo const &foo)" << std::endl;
    }

    [[nodiscard]] const std::string &getStr() const {
        std::cout << "Run getStr()" << std::endl;
        return str;
    }

    void setStr(const std::string &basicString) {
        std::cout << "Run setStr(...)" << std::endl;
        Foo::str = basicString;
    }

    virtual ~Foo() {
        std::cout << "Run ~Foo()" << std::endl;
    };


};

void bar(Foo &f) {
    Foo &f1 = f;
    std::cout << "in bar(Foo &f)" << std::endl;
}
void baz(Foo f) {
    Foo f1 = f;
    std::cout << "in baz(Foo f)" << std::endl;
}

int main() {
    Foo f("Hello Coverage!");
    const auto &p = f.getStr();
    bar(f);
    baz(f);
    return 0;
}
