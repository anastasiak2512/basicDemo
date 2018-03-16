#pragma once

#include <QRectF>
#include "Ball.h"

enum CollisionType {
    None, Left, Right, Top, Bottom
};

CollisionType getCollisionWithWalls(const Ball& b, const QRectF& bounding);

CollisionType getCollisionWithBrick(const Ball& b, const QRectF& brick);

/// Applies collision to a ball
/// \param b ball
/// \param type collision
/// \return true is there was any collision
bool applyCollision(Ball& b, CollisionType type);