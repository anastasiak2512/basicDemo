//
// Created by AK on 30/10/16.
//

#include "DFAchecks.h"

//==========================================================

void Sample1(int num, int num2) {
    int x, y;

    if (num)
        x = 2, y = 3;
    else
        x = 4, y = 5;

    if (num2) {
        if (x == 2 || y == 5) {
            //...
        }
    }
}

//==========================================================

typedef enum class Color {
    Red,
    Blue,
    Green,
    Yellow
} color;

void Sample2(int flag) {
    Color c;

    switch (flag) {
        case 0:
            c = Color::Red;
            break;
        case 1:
            c = Color::Blue;
            break;
//        default:
//            c = Color::Green;
//            break;
    }

    switch (c) {
        case Color::Red:
            break;
        case Color::Blue:
            break;
        case Color::Green:
            break;
        case Color::Yellow:
            break;
        default:
            break;
    }

}

//==========================================================

enum class States {
    Started, Stopped, Waiting
};

void Sample3(States current) {
    current = States::Started;

    if (current == States::Stopped) {
        //...
    }

    //...
}

//==========================================================

enum SystemLevels {
    SystemLevelBoot,
    SystemLevelDown,
    SystemLevelUp
};
const unsigned int sys_flags = SystemLevelUp | SystemLevelDown;

void Sample4() {
    if (sys_flags & SystemLevelBoot) {
        //...
    }

    //...
}