//Apply cast expression quick-fixes via Alt_Enter in the cases bellow.
//Check that CLion generates a proper C++ style cast in each case.

enum class Num { ONE = 1, TWO, THREE };

struct Base {
    virtual ~Base() {}
};

struct Derived: Base {
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
    int* pj = &j;
}






