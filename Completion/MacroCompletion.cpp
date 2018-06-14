//
// Check completion for the code declared via macros
//


#define CLASS_DEF(class_name) class class_##class_name \
                              { public: int count_##class_name; };

CLASS_DEF(one)
CLASS_DEF(two)

//FIXME: ugly preprocessor code, reimplement

#define X(a) myVal_##a,
enum myShinyEnum {
#include "xmacro.txt"
};
#undef X

void foo(myShinyEnum en) {
    switch (en) {
        case myVal_a:break;
        case myVal_b:break;
        case myVal_c:break;
        case myVal_d:break;
    }

//    class_one cl{};
//    cl.count_one;
}