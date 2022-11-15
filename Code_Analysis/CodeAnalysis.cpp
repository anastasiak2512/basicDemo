#pragma clang diagnostic push
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-3-1"
#pragma ide diagnostic ignored "modernize-use-auto"
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-2-4"
//Check the built-in code analysis checks.
//Quick-fixes are available for many cases.
//Uncomment the file.

#include <string>

#include <mutex>

class NeedsLock {
    std::lock_guard<std::mutex> _lock;

public:
    explicit NeedsLock(std::mutex& mtx) : _lock(mtx) {}
};

int main() {
    std::mutex mtx;
    std::unique_lock lock(mtx);
    NeedsLock needs_lock(mtx);
}

void narrow_cast(int64_t p_num) {
    int32_t num = (int32_t) p_num;
    if (num == p_num) {
        //...
    }
}

void EmitVBR64(uint64_t Val, unsigned NumBits) {
    assert(NumBits <= 32 && "Too many bits to emit!");
    if ((uint32_t) Val == Val) {
        //...
    }
}

int myIntSize(const char *const str) {
    if (*str == '\0') {
        return -1;  // Empty str
    }

    errno = 0;

    char *end;
    const long value = strtol(str, &end, 10);

    if (*end != '\0') {
        return -1;  // Isn't a number
    } else if (errno == ERANGE) {
        return -1;  // Overflow
    } else if (value == ((long) ((int8_t) value))) {
        return 1;
    } else if (value == ((long) ((int16_t) value))) {
        return 2;
    } else if (value == ((long) ((int32_t) value))) {
        return 4;
    } else {
        return -1;  // More than 32 bit
    }
}

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


#pragma clang diagnostic pop