#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-init-variables"

#include <numeric>
#include <array>
#include <vector>

#include <iomanip>
#include <memory>

#include <filesystem>

namespace fs = std::filesystem;

bool is_file(fs::path const &fl) {
    return is_regular_file(fl) ||
           is_block_file(fl) || is_character_file(fl);
}


//is_regular_file(fl) || is_block_file(fl) || is_character_file(fl);
void process() {
    int versions[] = {1, 2, 3};
    for (const auto &item : versions) {

    }

}

template<class T>
void perfectSet(T &&t) {
    set(std::forward<T>(t));
}


int compl_literals() {
    int a;
    //..
//    a+1.
}


#pragma clang diagnostic pop