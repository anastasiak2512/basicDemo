//modernize-use-nullptr check converts the usage of null pointer constants (eg. NULL, 0)
//to use the new C++11 nullptr keyword. By default, only 0 and NULL are converted.
//To convert your custom NULL values, use check's option:
//In Settings/Preferences | Editor | Inspections | C/C++ | General | Clang-Tidy
//configure modernize-use-nullptr.NullMacros = "MY_NULL, NULL, 0"


#include <cstddef>

void assignment() {
    char *var1 = NULL;
    char *var2 = 0;
    char var3 = 0;
}

int *ret_ptr() {
    //...

    return 0;
}

#define MY_NULL (void*)0

void assignment_custom() {
    void *pc = MY_NULL;
}