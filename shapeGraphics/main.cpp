#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Parallelogram p(Point(0, 0), Point(100, 0), Point(70, 40), "blue");
    Widget w;
    std::vector<class Point> points;
    points.push_back(Point(100, 100));
    points.push_back(Point(300, 100));
    points.push_back(Point(250, 400));
    points.push_back(Point(50, 400));
    //p.changeCoordinate(points);
    //p.multiplicateCoordinate(2);

    p.rotate(120);
    p.print(w);
    w.resize(400, 300);
    w.show();
    return a.exec();
}
