
int callf(int n) { return (n + 10); }

#define CALL(v) callf(v)

#ifdef __CLION_IDE__
#define MY_HUGE_MACRO(v) 100
#else
#define MY_HUGE_MACRO(v) CALL(CALL(CALL(v)))
#endif

void check_macro(int n) {
    int x = MY_HUGE_MACRO(n);
}

