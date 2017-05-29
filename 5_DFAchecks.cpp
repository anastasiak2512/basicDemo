//
// Created by AK on 30/10/16.
//

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
        default:
            c = Color::Green;
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

enum CollisionType {
    None, Left, Right, Top, Bottom
};


class Ball {
public:
    int getSpeedX() { return 0; }
    int getSpeedY() { return 0; }
};

bool Sample4(Ball& ball, CollisionType type) {
    int mulX = 1, mulY = 1;

    switch (type)
    {
        case Left:
            if (ball.getSpeedX() < 0) mulX = -1;
            break;
        case Right:
            if (ball.getSpeedX() > 0) mulX = -1;
            break;
        case Top:
            if (ball.getSpeedY() < 0) mulY = -1;
            break;
        case Bottom:
            if (ball.getSpeedY() > 0) mulY = -1;
            break;
        case None:break;
    }

    if (mulX == -1 && mulY == -1)
    {
        //do smth:...
        return true;
    } else
    {
        return false;
    }
}