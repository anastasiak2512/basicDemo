
#include <QApplication>
#include <QWidget>
#include "GameWidget.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GameWidget w(nullptr);

    w.show();
    app.exec();

    return 0;
}