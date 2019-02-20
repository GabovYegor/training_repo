#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Widget w;
    Parallelogram parallelogram(Point(1, 1), Point(3, 3), Point(4, 4), "white");
    Ellipse ellipse(Point(2, 3), Point(4, 8), Point(8, 2), "blue");
    parallelogram.multiplicateCoordinate(4);
    w.show();
    return a.exec();
}
