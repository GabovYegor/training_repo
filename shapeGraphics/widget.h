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

class Widget : public QWidget{
    Q_OBJECT
    static const int radius = 5;
public:
    Widget(QWidget *parent = 0);
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
    friend class Parallelogram;
    ~Widget();
};

#endif // WIDGET_H
