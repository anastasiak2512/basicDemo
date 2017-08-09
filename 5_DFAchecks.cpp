//
// Created by AK on 30/10/16.
//

//==========================================================

typedef enum class Color { Red, Blue, Green, Yellow };

void do_shadow_color(int shadow) {
    Color cl1, cl2;

    if (shadow)
        cl1 = Color::Red, cl2 = Color::Blue;
    else
        cl1 = Color::Green, cl2 = Color::Yellow;

    if (cl1 == Color::Red || cl2 == Color::Yellow) {

    }
}

//==========================================================

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