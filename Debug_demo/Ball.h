#pragma once


#include "GameObject.h"

struct Ball : public GameObject {
    Ball(const QPointF& pos, const QPointF& speed);

    void draw(QPainter& p) const override;

    QRectF aabb() const override;
};

