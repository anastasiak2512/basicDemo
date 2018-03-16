#include "Brick.h"
#include <QPainter>

Brick::Brick(const QPointF &pos, double width, double height) :
        GameObject(pos, QPointF()), width_(width), height_(height) {}

void Brick::draw(QPainter &p) const {
    p.fillRect(getRect(), Qt::blue);
}

QRectF Brick::getRect() const {
    return QRectF(getPos() - QPointF(width_, height_) / 2, QSizeF(width_, height_));
}

QRectF Brick::aabb() const {
    return getRect();
}
