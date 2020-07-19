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

struct Data
{
    void activity();
    static int num;
};

Data CreateData() { return Data(); }

void ActivateData()
{
    CreateData().activity();
}

int Data::num = 1;

void Data::activity()
{
    num = 42;
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
//Unused type aliases

using myGlobalIntType = int;

void foo() {
    using myLocalIntType = int;
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
