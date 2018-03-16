#include <gtest/gtest.h>
#include "Collisions.h"


TEST(Collisions, Right) {
    ASSERT_EQ(getCollisionWithBrick(Ball(QPointF(), QPointF()), QRectF(2, -2, 20, 20)), Right);
}

TEST(Collisions, Left) {
    ASSERT_EQ(getCollisionWithBrick(Ball(QPointF(), QPointF()), QRectF(-20, -2, 20, 20)), Left);
}

TEST(Collisions, Apply) {
    Ball b{QPointF(), QPointF(1, 1)};
    applyCollision(b, Right);
    ASSERT_EQ(b.getSpeed(), QPointF(-1, 1));
}