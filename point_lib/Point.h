#ifndef POINTLIB_POINT_H
#define POINTLIB_POINT_H

enum class Color {
    Red,
    Green,
    Blue,
    Black = 0,
    White = 100
};

class Point
{
private:
    int   x;
    int   y;
    Color pc{Color::Black};

public:
    Point(int _x, int _y): x(_x), y(_y) {}
    void move_point(int dx);
    void change_color(Color c);
};

void Point::move_point(int dx) {
    this->x += dx;
}

void Point::change_color(Color c) {
    this->pc = c;
}

#endif // POINTLIB_POINT_H
