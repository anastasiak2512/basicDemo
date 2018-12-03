// C++17 deduction guides are parsed. Type info is calculated.
// Call Parameter info at c.insert() to get the type inferred correctly.

#include <vector>

template <class T>
struct container {
    template <class Iter> container(Iter, Iter);
    void insert(T arg);
    //...
};

template <class Iter>
container (Iter, Iter)
-> container<typename std::iterator_traits<Iter>::value_type>;

void check_dg(std::vector<int> v) {
    container c(v.begin(), v.end());
    c.insert(100);
}

