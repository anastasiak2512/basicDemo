#pragma once

#include "Ball.h"
#include "Brick.h"
#include <vector>

//TODO: include clock
struct GameState {
    GameState(int fieldWidth, int fieldHeight);

public:
    void calc(int ms);
    void movePaddle(int dx);

    QRect getField() const;

    void draw(QPainter& painter) const;

    int getScore() const;

private:
    void processCollisions();

private:
    QRect field_;

    Ball ball_;
    std::vector<Brick> bricks_;
    Brick paddle_;

    int score_;
};


