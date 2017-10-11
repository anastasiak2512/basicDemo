//
// Check completion for the code declared via macros
//

#define CLASS_DEF(class_name) class class_##class_name { public: int count_##class_name; };

CLASS_DEF(one)
CLASS_DEF(two)

#define X(a) a,
enum E {
#include "xmacro.txt"
};
#undef X

void foo(int c) {
//    E::
    
//    class_one cl;
//    cl.count_one;
}