#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Widget w;
    //Parallelogram parallelogram(Point(0, 0), Point(100, 0), Point(70, 40), "white");
    //Ellipse ellipse(Point(0, -80), Point(80, 0), Point(0, 80), "blue");
    EllipseSector ellipseSector(Point(0, 0), Point(50, 0), Point(0, 50), "blue");
    std::vector <class Point> newCoordinates;
    newCoordinates.push_back(Point(0, 0));
    newCoordinates.push_back(Point(200, 0));
    newCoordinates.push_back(Point(140, 80));
    w.setShape(&ellipseSector);
    w.printShape();
    w.show();
    return a.exec();
}
