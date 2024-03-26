#pragma once

#include <optional>
#include <QPointF>
#include <QRectF>
class QPainter;

struct Motion {
    explicit Motion(const QPointF& value) : value_(value) {}

    const QPointF& getValue() const {
        return value_;
    }

    void setValue(const QPointF& value) {
        value_ = value;
    }

    void setDelta(const std::optional<QPointF>& delta){
        delta_ = delta;
    }

    void calculate(int msec) {
        if (delta_) {
            value_ += *delta_ * (msec / 1000.);
        }
    }

private:
    QPointF value_;
    std::optional<QPointF> delta_;
};

struct GameObject {

    GameObject(const QPointF& pos, const QPointF& speed);

    const QPointF& getPos() const;

    const QPointF& getSpeed() const;

    Motion& getSpeedMotion() {
        return speed_;
    }

    void setPos(const QPointF& pos);

    void setSpeed(const QPointF& speed);

    void calc(int msec);

    virtual void draw(QPainter& p) const = 0;

    virtual QRectF aabb() const = 0;

private:
    Motion pos_;
    Motion speed_;
};

