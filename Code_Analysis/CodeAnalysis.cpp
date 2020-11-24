//Check the built-in code analysis checks.
//Quick-fixes are available for many cases.
//Uncomment the file.

#include <string>

//==========================================================

void checkParam(std::string name) {
    //Press Alt+Enter for a quick-fix
    std::string name;

    name.append("Test");
}

//==========================================================

class Ball {
public:
    void play(int time) { /*...*/ }
};
class BlinkingBall : public Ball {
public:
    //Press Alt+Enter for a quick-fix
    void play(int time) {
        //...
    }
};

//==========================================================

void formatSpec(int x, char * y) {
    printf("Input param: %s, %d", x, y);
}

//==========================================================

void eqCheck(int& a, int& b) {
    if (a = b) {
        //...
    }
}

//==========================================================

int * escapeScope() {
    int c = 100;
    return &c;
}

//==========================================================

template<typename T>
void Foo(T, typename T::inner_type * = nullptr);

template<typename T>
decltype(T().Method()) Bar(T);

struct X {
    using inner_type = void;
    static void Method() {}
};

struct Y {};

void CallFooBar(X x, Y y) {
    Foo(x);
    Foo(y);
    Bar(x);
    Bar(y);
}

//==========================================================
//Simplify statement

template<int N>
struct Smpl {
    static constexpr bool value = false;
};
template<>
struct Smpl<0> {
    static constexpr bool value = true;
};
template <int N>
void foo() {
    static constexpr bool value = Smpl<N>::value && Smpl<0>::value;
}
//==========================================================
//Constrain a function result

template<typename T>
concept MyConcept = requires(T t){ static_cast<bool>(t); };

template<class T>
struct Strc {
    template<class U>
    MyConcept auto func() { return 2020; }
};

void test() {
    Strc<int> strc;
    auto x = strc.func<char>();
}

template<class T, class U, class V>
concept MyComplexConcepts = true;

template<class T>
struct S3 {
    template<class U>
    MyComplexConcepts<T, U> auto func() { return 1; }
};

void test2() {
    S3<int> s3;
    auto x = s3.func<char>();
}

//========================================================
// MISRA checks: https://confluence.jetbrains.com/display/CLION/MISRA+checks+supported+in+CLion

template<typename T> void f(T);
template<> void f<uint16_t>(uint16_t);
template <> void f<int16_t>(int16_t);
void b() {
    uint16_t u16a = 0U;
    f(u16a);
    u16a = u16a + 0x8000;
    f(u16a);
}


#define SHIFT_8 8

unsigned char func(unsigned char num) {
    return num;
}

void discarded(unsigned char counter) {
    int32_t code[5];
    code[0] = 109;
    code[1] = 100;
    code[2] = 052;
    code[3] = 071;
    code[4] = '\100';

    unsigned char foo = 1;
    foo <<= SHIFT_8;

    func(counter * foo);
}


