#include <iostream>
#ifdef __clang__
#include <experimental/coroutine>
#else
#include <coroutine>
#endif
#include <memory>

template<typename T>
struct foo {
    std::shared_ptr<T> value;

    foo(std::shared_ptr<T> p)
            : value(p) {
        std::cout << "Created a sync object" << std::endl;
    }

    foo(const foo &s)
            : value(s.value) {
        std::cout << "Copied a sync object" << std::endl;
    }

    ~foo() {
        std::cout << "Sync gone" << std::endl;
    }

    T get() {
        std::cout << "We got asked for the return value..." << std::endl;
        return *value;
    }

    struct promise_type {
        std::shared_ptr<T> ptr;

        promise_type()
                : ptr(std::make_shared<T>()) {
            std::cout << "Promise created" << std::endl;
        }

        ~promise_type() {
            std::cout << "Promise died" << std::endl;
        }

        auto get_return_object() {
            std::cout << "Send back a sync" << std::endl;
            return ptr;
        }

        auto initial_suspend() {
            std::cout << "Started the coroutine, don't stop now!" << std::endl;
            #ifdef __clang__
            return std::experimental::suspend_never{};
            #else
            return std::suspend_never{};
            #endif

        }

        auto return_value(T v) {
            std::cout << "Got an answer of " << v << std::endl;
            *ptr = v;
            #ifdef __clang__
            return std::experimental::suspend_never{};
            #else
            return std::suspend_never{};
            #endif
        }

        auto yield_value(T value) {
            std::cout << "Yielded " << value << std::endl;
            #ifdef __clang__
            return std::experimental::suspend_always{};
            #else
            return std::suspend_always{};
            #endif
        }

        auto final_suspend() noexcept {
            std::cout << "Finished the coro" << std::endl;
            #ifdef __clang__
            return std::experimental::suspend_never{};
            #else
            return std::suspend_never{};
            #endif
        }

        void unhandled_exception() {
            std::exit(1);
        }
    };
};

foo<int> iota(int n = 0) {
    while (n>5)
        co_yield n++;
}