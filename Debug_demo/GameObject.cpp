#include <QVector2D>
#include "Ball.h"
#include "GameObject.h"

GameObject::GameObject(const QPointF& pos, const QPointF& speed) :
        pos_(pos), speed_(speed) {}

const QPointF& GameObject::getPos() const {
    return pos_.getValue();
}

const QPointF& GameObject::getSpeed() const {
    return speed_.getValue();
}

//FIXME: check const
void GameObject::calc(int msec) {
    speed_.calculate(msec);
    pos_.calculate(msec);
    pos_.setValue(pos_.getValue() + speed_.getValue() * (msec / 1000.));

    if (QVector2D(speed_.getValue()).length() < 0.03) {
        speed_.setDelta(std::nullopt);
    }
}

void GameObject::setPos(const QPointF& pos) {
    pos_.setValue(pos);
}

void GameObject::setSpeed(const QPointF& speed) {
    speed_.setValue(speed);
}
