// Core Dump Debug:
// 1. Uncomment the code in main
// 2. Build the app
// 3. In terminal do:
//      sudo su
//      ulimit -c unlimited
// 4. Run the app from the terminal session
// 5. Debug with core

#include <iostream>
#include <vector>

struct Demo {
    int dOne;
    int dTwo;
};

class Deref {
    int* foo() {
        return nullptr;
    }

public:
    void bar() {
        int* buffer = foo();
        buffer[1] = 0;
    }
};

int main() {
    Deref drf;
    drf.bar();

    const char *str = "let's find what's inside!";
    Demo singleDemo{10, 15};
    Demo *pdemo = &singleDemo;

    float pi = 3.14;
    float *fp = &pi;


    for (int i = 0; i < 64; i += 4) {
        pdemo->dOne = 0xBADD << i;
        pdemo->dTwo = 0xCAFE << i;
    }

    long lnumber = 100001L;
    long *ln = &lnumber;

     return 0;
}

