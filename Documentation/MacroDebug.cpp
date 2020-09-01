//- Call Quick Doc (Ctrl+Q on Windows/Linux, F1 on macOS) for CLASS_DEF usage. See the macro replacement.
//- Inline (Ctrl+Alt+N on Windows/Linux, ⌥⌘N) CLASS_DEF, one or all usages

// Sample 1
#define MAGIC 100
#define CALL_DEF(val, class_name) int call_##class_name() { return val; }

#define CLASS_DEF(class_name) class class_##class_name { \
                              public: \
                                  int count_##class_name; \
                                  CALL_DEF(MAGIC, class_name) \
                              };

CLASS_DEF(A)
CLASS_DEF(B)
CLASS_DEF(C)

// Sample 2
// See ../Boost_tests/boost_demo_tests.cpp for the Boost sample

// Sample 3
static int v;

#define __NEW_VAR(name, num) static void *__v_##num = (void *)&name;
#define _NEW_VAR(name, num) __NEW_VAR(name, num)
#define NEW_VAR(name) _NEW_VAR(name, __COUNTER__)

void counter_macro_sample() {
    NEW_VAR(v)
    NEW_VAR(v)
    NEW_VAR(v)
}