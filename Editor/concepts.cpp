// Main simple case

template<class T>
concept Foo = true;

Foo auto func() { return true; }

int main() {
    auto f = func(); // warn here to add constraint 'Foo': Foo auto f = func();
    Foo auto f1 = func();
    auto f2 = f1;  // warn here to add constraint 'Foo'
    return 0;
}

// Additional cases
template<typename T>
concept MyConcept = requires(T t){ static_cast<bool>(t); };

// 1) Member function in templated struct
template<MyConcept MC>
struct S {
    MC func() { return 1; }
};

S<bool> s;
auto s_val = s.func(); // here

// 2) Templated member function
struct S2 {
    MyConcept auto func() { return 1; }
};

S2 s2;
auto res = s.func(); // here

// 3) Function pointer (with and without trailing return type)
MyConcept auto (*p)() = func;

auto (*q)() -> auto = p; // here
auto (*r)() = p; // here

// 4) Templated free functions
template<MyConcept MC>
MC func() { return 0; }

auto res2 = func<bool>(); // here


// 5) Concept with several template arguments coming from different places, e.g.:

template<class T, class U, class V>
concept Bar = true;

template<class T>
struct S3 {
    template<class U>
    Bar<T, U> auto func() { return 1; }
};

S3<int> s3;
auto x = s3.func<char>(); // here

