#pragma once


#include "GameObject.h"

struct Brick : GameObject {
    Brick(const QPointF& pos, double width, double height);

    void draw(QPainter& p) const override;

    QRectF aabb() const override;

private:
    QRectF getRect() const;

private:
    double width_;
    double height_;

};

