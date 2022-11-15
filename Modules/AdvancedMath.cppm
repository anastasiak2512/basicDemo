export module AdvancedMath;

export namespace AdvancedMath {
    auto plus(auto x, auto y) -> decltype(x+y) {
        return x + y;
    }
    auto minus(auto x, auto y) -> decltype(x-y) {
        return x - y;
    }
    auto complex_add(auto x, auto y, auto z) -> decltype(x + y + z) {
        return x + y + z;
    }
}
void this_function_will_not_be_exported() {}