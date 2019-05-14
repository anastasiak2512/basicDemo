#include <iostream>
#include <vector>

struct Demo {
    int dOne;
    int dTwo;
};

int main() {
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

