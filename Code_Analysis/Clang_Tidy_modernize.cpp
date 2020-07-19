//
// Created by AK on 14/09/2017.
//

// To enable only Modernize checks in Clang-Tidy
// go to Settings/Preferences | Editor | Inspections | C/C++ | Clang-Tidy
// and provide: -*,modernize-* in options

#include <functional>
#include <vector>
#include <iostream>

int add(int x, int y) { return x + y; }

void bind_to_lambda(int num) {
    int x = 2;
    auto clj = std::bind(add, x, num);
}

void loop_convert(const std::vector<int>& vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter;
    }
}

class myClass {
public:
    myClass(const std::string &Copied,
            const std::string &ReadOnly)
            : Copied(Copied), ReadOnly(ReadOnly) {}

private:
    std::string Copied;
    const std::string &ReadOnly;
};

typedef void (myClass::* MyPtrType)() const;


