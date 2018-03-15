//Switch the context in the bottom right corner of the editor:
//resolve_context_no_flag <-> resolve_context_flag and see how the highlighting is changed.

#include <iostream>

void check_context() {
    int count;

#ifdef SpecialFlag
#if SpecialFlag
    std::cout << "Running with Special Flag" << std::endl;
    count = 1000;
#else
    std::cout << "Running without Special Flag" << std::endl;
    count = 1;
#endif
#endif

    for (int i = 0; i < count; i++) {
        //...
    }
}
