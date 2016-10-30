//
// Created by AK on 30/10/16.
//

#include "MacroCompletion.h"

#define CLASS_DEF(class_name) class class_##class_name { public: int count_##class_name; };

CLASS_DEF(one)
CLASS_DEF(two)

void foo(int c) {
//    class_two cl;
}