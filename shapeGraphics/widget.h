#ifndef WIDGET_H
#define WIDGET_H

#include "shape.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QLineEdit>
#include <QLabel>
#include <QVector>
#include <QRect>

class Widget : public QWidget{
    Q_OBJECT
    static const int radius = 5;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QPushButton* btnClose;
    QPushButton* btnRotate;
    QPushButton* btnChangeCoordinate;
    QPushButton* btnMultiplication;
    QPushButton* btnSetColor;
    QLineEdit* lePoint1X;
    QLineEdit* lePoint2X;
    QLineEdit* lePoint3X;
    QLineEdit* lePoint1Y;
    QLineEdit* lePoint2Y;
    QLineEdit* lePoint3Y;
    QLineEdit* leRotate;
    QLineEdit* leMultiplication;
    QLineEdit* leColor;
    QLineEdit* leId;
    QLabel* lblX1;
    QLabel* lblX2;
    QLabel* lblX3;
    QLabel* lblY1;
    QLabel* lblY2;
    QLabel* lblY3;
    QLabel* lblColor;
    QLabel* lblId;
    QVector<class Shape*> shapes;
    class Shape* shape;
public:
    void changeCoordinate(std::vector <class Point>);
    void multiplicateCoordinate(unsigned);
    void rotate(double);
    void setShape(class Shape* shape){this->shape = shape;}
    Widget(QWidget *parent = 0);
    void printShape();
    ~Widget();
public slots:
    void changeCoordinate();
    void multiplicateCoordinate();
    void rotate();
    void setColor();
};

#endif // WIDGET_H
