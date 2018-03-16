#pragma once

#include <QWidget>
#include <memory>

struct GameState;
struct CanvasWidget;
struct QLabel;

//TODO: Document class
struct GameWidget : public QWidget {
    GameWidget(QWidget* parent);
    ~GameWidget();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
        void resetState();

private:
    std::unique_ptr<GameState> state_;

    friend struct CanvasWidget;
    CanvasWidget *canvas_;
};

