#pragma once


#include <QPointF>
#include <QRectF>
struct QPainter;

struct GameObject {

    GameObject(const QPointF& pos, const QPointF& speed);

    const QPointF& getPos() const;

    const QPointF& getSpeed() const;

    void setPos(const QPointF& pos);

    void setSpeed(const QPointF& speed);

    void calc(int msec);

    virtual void draw(QPainter& p) const = 0;

    virtual QRectF aabb() const = 0;

private:
    QPointF pos_;
    QPointF speed_;
};

