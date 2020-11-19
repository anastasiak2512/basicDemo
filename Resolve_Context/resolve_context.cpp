//Switch the context in the bottom right corner of the editor:
//resolve_context_no_flag <-> resolve_context_flag and see how the highlighting is changed.

#include <iostream>

namespace MYNAMESPACE {
    class MyClass {
    public:
        void foo() {};
    };
}

void check_context() {
    MYNAMESPACE::MyClass cl;

#ifdef SpecialFlag
#if SpecialFlag
    std::cout << "Running with Special Flag" << std::endl;
    int count = 1000;
    TEST::MyClass ifcl;
#else
    std::cout << "Running without Special Flag" << std::endl;
    int count = 1;
    TEST2::MyClass ifcl;
#endif
#endif

    for (int i = 0; i < count; i++) {
        //...
    }
}
