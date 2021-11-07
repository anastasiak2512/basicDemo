// To enable MISRA Check
// go to Settings/Preferences | Editor | Inspections | C/C++ | General | MISRA Checks
// note that clang-tidy is built one and calngd via clang-tidy is enabled
// MISRA checks: https://confluence.jetbrains.com/display/CLION/MISRA+checks+supported+in+CLion

#include <cstdint>


template<typename T> void f(T);
template<> void f<uint16_t>(uint16_t);
template <> void f<int16_t>(int16_t);
void b() {
    uint16_t u16a = 0U;
    f(u16a);
    u16a = u16a + 0x8000;
    f(u16a);
}


#define SHIFT_8 8

unsigned char func(unsigned char num) {
    return num;
}

void discarded(unsigned char counter) {
    int32_t code[5];
    code[0] = 109;
    code[1] = 100;
    code[2] = 052;
    code[3] = 071;
    code[4] = '\100';

    unsigned char foo = 1;
    foo <<= SHIFT_8;

    func(counter * foo);
}

struct S {
    signed int a : 1;
    signed int : 1;
    signed int : 0;
    signed int b : 2;
    signed int : 2;
};

void process_ptr(int32_t *int_ptr) {}

void operate() {
    process_ptr(0);
}

class OpClass {
public:
    OpClass *operator&() {};
};

class MySingleCLass {
public:
    MySingleCLass(int32_t a) {}
};

int inc_func() { return 100; }

void check_loop() {
    for (int x = 0; x < 10; x += inc_func()) {}

    int y = 0;
    for (int x = 0; x < y; x = y++) {}


}

bool modify(int32_t *pX) {
    *pX++;
    return *pX < 10;
}

void check_modify_loop() {
    for (int x = 0; modify(&x);) {}
}

