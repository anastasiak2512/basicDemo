#include <iostream>
#include <numeric>
#include <vector>

void print_vec(const std::vector<int> &vec, const std::string &label);

void print_vec(const std::vector<int> &vec, const std::string &label) {
    auto str = std::accumulate(vec.cbegin(), vec.cend(), label,
                               [] (auto accum, auto item) {
                                   return std::move(accum) + " " + std::to_string(item); });
    std::cout << str << "\n";
}

void sort_vec_iter(std::vector<int> &myvec) {
    for (auto it = myvec.begin(); it < myvec.end(); ++it) {
        for (auto jit = it + 1; jit < myvec.end(); ++jit) {
            if (*it < *jit) { // Extract Lambda
                std::iter_swap(it, jit);
            }
        }
    }
}

void sort_vec_loop(const size_t len, std::vector<int> &myvec) {
    for (int i = 0; i < len; ++i) {
       for (int j = i + 1; j < len; ++j) {
            auto x = myvec[i];
            auto y = myvec[j];
            if (x < y) { //Extract Lambda
               myvec[i] = y;
               myvec[j] = x;
           }
       }
    }
}

int extract_demo() {
    const size_t len = 5;
    std::vector<int> myvec(len);
    std::generate(myvec.begin(), myvec.end(), []{ return rand() % 100; });

    print_vec(myvec, std::string{"Let's start with: "});

    sort_vec_iter(myvec);
    print_vec(myvec, std::string{"Let's start with: "});
    sort_vec_loop(len, myvec);
    print_vec(myvec, std::string{"Let's start with: "});
}

