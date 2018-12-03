#include <iostream>
#include <sys/utsname.h>

int main()  {
    struct utsname name{};
    if(uname(&name))
        exit(-1);

    std::cout << "Hello! Your computer's OS is "
              << name.sysname << " "
              << name.release << "\n";

    return 0;

}

