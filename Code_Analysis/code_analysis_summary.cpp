// Code Analysis Summary
// - General cases
// - Type casts
// - DFA
// - Clang-Tidy: modernize
// - Clang-Tidy: google

#include <string>
#include <functional>
#include <vector>
#include <iostream>

namespace analysis_sum {

    int *escapeLocalScope() {
        int lv = 100;
        return &lv;
    }

//==========================================================

    void wrongFormatSpecifiers(int x, char *y) {
        printf("Input param: %s, %d", x, y);
    }

//==========================================================

    void checkParam(std::string name) {
        std::string name;

        name.append("Test");
    }

//==========================================================

    enum class Num {
        ONE = 1, TWO, THREE
    };

    struct Base {
        virtual ~Base() {}
    };

    struct Derived : Base {
        virtual void name() {}
    };

    int answer() { return 42; }

    void static_cast_sample() {
        Num n = Num::TWO;
        int one = n;
    }

    void dynamic_cast_sample() {
        Base *b = new Base;
        if (Derived *d = b) {
            d->name();
        }
    }

    void reinterpret_cast_sample() {
        void (*fun_pointer)() = answer;
    }

    void const_cast_sample() {
        const int j = 42;
        int *pj = &j;
    }

//==========================================================

    enum class Color {
        Red, Blue, Green, Yellow, White
    };

    void dfa_sample(int shadow) {
        Color cl1, cl2;
        Color res = Color::White;

        if (shadow)
            cl1 = Color::Red, cl2 = Color::Blue;
        else
            cl1 = Color::Green, cl2 = Color::Yellow;

        if (cl1 == Color::Red || cl2 == Color::Yellow)
            res = Color::Blue;
        else
            res = Color::Green;

        switch (res) {
            case Color::Red:
                break;
            case Color::Blue:
                break;
            case Color::Green:
                break;
            case Color::Yellow:
                break;
            case Color::White:
                break;
        }
    }

//==========================================================

    struct User {
        int64_t user_id;
        int64_t company_id;
        std::string user_name;
    };

    const User *get_User(int64_t company_id, int64_t user_id) {
        return new User{company_id, user_id, "foo"};
    }

    void call_User(int64_t company_id, int64_t user_id) {
        const User *user = get_User(user_id, company_id);
        //...
    }

//==========================================================

    int add(int x, int y) { return x + y; }

    void bind_to_lambda(int num) {
        int x = 2;
        auto clj = std::bind(add, x, num);
    }

    void loop_convert(const std::vector<int> &vec) {
        for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
            std::cout << *iter;
        }
    }

    class MyClass {
    public:
        MyClass(const std::string &Copied,
                const std::string &ReadOnly)
                : Copied(Copied), ReadOnly(ReadOnly) {}

    private:
        std::string Copied;
        const std::string &ReadOnly;
    };

    class BaseCalculation {
    public:
        virtual int someMethod(const int x, const int factor = 1) const {
            return 42 * x * x * factor;
        }
    };

    class DerivedCalculation : public BaseCalculation {
    public:
        int someMethod(const int x, const int factor = 0) const override {
            return x * x * factor;
        }
    };
}  // namespace analysis_sum