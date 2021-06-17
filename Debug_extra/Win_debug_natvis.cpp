#include <iostream>
#include <vector>

class MyPoint {
    int x;
    int y;

public:
    MyPoint(int x, int y) : x(x), y(y) {}
};
enum class Color {
    Black, White, Yellow, Red, Blue, Green
};

class MyColoredPoint : public MyPoint {
    Color cl{Color::Black};
public:
    MyColoredPoint(Color c, int x, int y) : MyPoint(x, y), cl(c) {}
    explicit MyColoredPoint(MyPoint p): MyPoint(p) {}
};

int main() {
    MyPoint mypoint_{1,2};
    MyPoint mypoint_zero{0,0};
    MyColoredPoint cp_zero(mypoint_zero);
    MyColoredPoint cp_(Color::Blue, 4, 5);

    std::vector<MyPoint> vector_of_points = {{1,1}};

    return 0;
}

