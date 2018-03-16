#include "Ball.h"
#include "GameObject.h"

GameObject::GameObject(const QPointF& pos, const QPointF& speed) :
        pos_(pos), speed_(speed) {}

const QPointF& GameObject::getPos() const {
    return pos_;
}

const QPointF& GameObject::getSpeed() const {
    return speed_;
}

//FIXME: check const
void GameObject::calc(int msec) {
    pos_ += speed_ * (msec / 1000.);
}

void GameObject::setPos(const QPointF& pos) {
    pos_ = pos;
}

void GameObject::setSpeed(const QPointF& speed) {
    speed_ = speed;
}
