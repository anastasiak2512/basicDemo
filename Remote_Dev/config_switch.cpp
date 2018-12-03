// Configure Linux and macOS toolchains, get corresponding resolve configurations.
// Switch between the configurations and get different branch highlighted.

#include <iostream>

void config_switch() {
    std::cout << "My system: ";

#ifdef __linux__
    std::cout << "Linux\n";
#elif __APPLE__
    std::cout << "Mac\n";
#endif
}

