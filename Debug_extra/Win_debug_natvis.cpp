#include <iostream>
#include <vector>

class MyPoint {
    int x;
    int y;

public:
    MyPoint(int x, int y) : x(x), y(y) {}
};

int main() {
    MyPoint mypoint_{1,2};
    MyPoint mypoint_zero{0,0};

    std::vector<MyPoint> vector_of_points = {{1,1}};

    return 0;
}

