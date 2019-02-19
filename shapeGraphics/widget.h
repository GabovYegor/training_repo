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
    QLineEdit* lePoint1X;
    QLineEdit* lePoint2X;
    QLineEdit* lePoint3X;
    QLineEdit* lePoint1Y;
    QLineEdit* lePoint2Y;
    QLineEdit* lePoint3Y;
    QPushButton* btnChangeCoordinate;
    QLabel* lblX1;
    QLabel* lblX2;
    QLabel* lblX3;
    QLabel* lblY1;
    QLabel* lblY2;
    QLabel* lblY3;
    QVector<class Shape*> shapes;
public:
    Widget(QWidget *parent = 0); 
    friend class Parallelogram;
    friend class Ellipse;
    ~Widget();   
};

#endif // WIDGET_H
