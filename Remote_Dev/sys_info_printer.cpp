#include <iostream>
#include <sys/utsname.h>

int main()  {
    struct utsname name{};
    if(uname(&name))
        exit(-1);

    auto sys = name.sysname;
    auto rel = name.release;

    //...

    std::cout << "Hello! Your computer's OS is "
              << sys << " "
              << rel << "\n";

    return 0;

}

