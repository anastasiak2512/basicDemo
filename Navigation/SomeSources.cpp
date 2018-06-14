// 0. Go to File / Class / Symbol
// 1. Imports Hierarchy (Shift+Alt+H) on this file
// 2. Call Hierarchy (Ctrl+Alt+H) on colorBallCall
// 3. Type Hierarchy (Ctrl+H) on colorBall

#include "Ball.h"
#include <vector>

void doSmth() {
    std::vector<colorBall> v;
    for (auto &&item : v) {
        item.colorBallCall();
    }
}