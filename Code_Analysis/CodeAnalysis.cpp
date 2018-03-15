//Check the built-in code analysis checks.
//Quick-fixes are available for many cases.
//Uncomment the file.

#include <string>

//==========================================================

void checkParam(std::string name) {
    //Press Alt+Enter for a quick-fix
    std::string name;

    name.append("Test");
}

//==========================================================

class Ball {
public:
    void play(int time) { /*...*/ }
};
class BlinkingBall : public Ball {
public:
    //Press Alt+Enter for a quick-fix
    void play(int time) {
        //...
    }
};

//==========================================================

void formatSpec(int x, char * y) {
    printf("Input param: %s, %d", x, y);
}

//==========================================================

void eqCheck(int& a, int& b) {
    if (a = b) {
        //...
    }
}

//==========================================================

int * escapeScope() {
    int c = 100;
    return &c;
}

//==========================================================
