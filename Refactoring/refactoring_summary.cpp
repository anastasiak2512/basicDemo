// Refactorings summary:
// - rename, change signature
// - pull members up
// - extracts

#include <string>
#include <iostream>

namespace refactoring_sum {

    class A {
    public:
        virtual void check_int(int v, int v2) = 0;
    };

    class B : public A {
        void check_int(int v, int v2) override {
            if (v < v2)
                check_int(v, v2 - v);

            //do smth
        }
    };

    //Change signature: rename and update parameters
    class C : public A {
        void check_int(int v, int v2) override {
            if (v <= v2)
                check_int(v, v2 - v);

            //do smth
        }
    };

//==========================================================

    class Base {
    public:
        void some_basic_func() {};
    };

    class Derived : public Base {
    private:
        int base_id;
        int x, y;
    public:
        int print_smth_general() { return 10; }

        void calculation() {}

        //Pull member up
        int preview() {
            return (print_smth_general() + base_id);
        }
    };

//==========================================================

class Calculations {
private:
    int result{};
public:
    int calculate_expr(int p) {
        return p * p;
    }

    // Extract variable: 2 * x + y
    // Extract parameter: (1 - 0.5f)
    void calculate_table(int x, int y) {
        float sum = calculate_expr(2 * x + y + 5) * (1 - 0.5f) +
                  calculate_expr(2 * x + y + 10) * (1 - 0.5f) +
                  calculate_expr(2 * x + y) * (1 - 0.5f);
        //...
    }

    void check_calculation() {
        calculate_table(100, 200);
    }
};

}  // namespace refactoring_sum