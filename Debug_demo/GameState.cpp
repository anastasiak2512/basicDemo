#include "GameState.h"

#include "Collisions.h"

GameState::GameState(int fieldWidth, int fieldHeight)
        : field_(0, 0, fieldWidth, fieldHeight),
          ball_(QPointF(field_.width() / 2, field_.height() - 30), QPointF(200, -200)),
          paddle_(QPointF(field_.width() / 2, field_.height() - 10), 60, 20),
          score_(0) {

    int ROWS = 4, COLS = 5;
    int SPACING = 10;
    int BRICK_WIDTH = (field_.width() - SPACING) /
                          COLS - SPACING, BRICK_HEIGHT = 30;

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int x = BRICK_WIDTH / 2 +
                (BRICK_WIDTH + SPACING) * col +
                SPACING;
            int y = BRICK_HEIGHT / 2 +
                (BRICK_HEIGHT + SPACING) * row +
                SPACING;

            bricks_.push_back(
                Brick(QPointF(x, y), BRICK_WIDTH, BRICK_HEIGHT));
        }
    }

}

void GameState::calc(int ms) {
    processCollisions();
    ball_.calc(ms);
    for (auto &&brick : bricks_) {
        brick.calc(ms);
    }
    paddle_.calc(ms);
}

void GameState::movePaddle(int dx) {
    paddle_.setPos(paddle_.getPos() + QPoint(dx, 0));
}

void GameState::processCollisions() {
    if (applyCollision(ball_, getCollisionWithWalls(ball_, getField()))) return;

    for (auto iter = bricks_.begin(); iter != bricks_.end(); ++iter) {
        if (applyCollision(ball_, getCollisionWithBrick(ball_, iter->aabb()))) {
            bricks_.erase(iter);
            score_ += 1;
            return;
        }
    }

    if (applyCollision(ball_, getCollisionWithBrick(ball_, paddle_.aabb()))) return;
}

QRect GameState::getField() const {
    return field_;
}

int GameState::getScore() const {
    return score_;
}

void GameState::draw(QPainter &painter) const {
    ball_.draw(painter);
    for (auto &&brick : bricks_) {
        brick.draw(painter);
    }
    paddle_.draw(painter);
}
