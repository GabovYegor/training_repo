#include "widget.h"
#include <string>
#include <cstdlib>

Widget::Widget(QWidget *parent) : QWidget(parent){
    Parallelogram parallelogram;
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    setLayout(new QVBoxLayout());
    QVBoxLayout* vlayoutX = new QVBoxLayout;
    QVBoxLayout* vlayoutY = new QVBoxLayout;
    QVBoxLayout* vlayoutLblX = new QVBoxLayout;
    QVBoxLayout* vlayoutLblY = new QVBoxLayout;
    QHBoxLayout* HPoints = new QHBoxLayout;
    QHBoxLayout* HRotate = new QHBoxLayout;
    QHBoxLayout* HMultiplication = new QHBoxLayout;
    QHBoxLayout* HInfo = new QHBoxLayout;
    btnSetColor = new QPushButton("set color", this);
    btnChangeCoordinate = new QPushButton("change coordinate", this);
    btnRotate = new QPushButton("rotate", this);
    btnMultiplication = new QPushButton("multiplication", this);
    btnClose = new QPushButton("CLOSE", this);
    btnSetColor->setMinimumWidth(150);
    btnChangeCoordinate->setMinimumWidth(150);
    btnChangeCoordinate->setMaximumHeight(100);
    btnRotate->setMinimumWidth(150);
    btnMultiplication->setMinimumWidth(150);
    lePoint1X = new QLineEdit(this);
    lePoint2X = new QLineEdit(this);
    lePoint3X = new QLineEdit(this);
    lePoint1Y = new QLineEdit(this);
    lePoint2Y = new QLineEdit(this);
    lePoint3Y = new QLineEdit(this);
    leRotate = new QLineEdit(this);
    leColor = new QLineEdit(this);
    leId = new QLineEdit(this);
    leMultiplication = new QLineEdit(this);
    lblX1 = new QLabel("x1", this);
    lblX2 = new QLabel("x2", this);
    lblX3 = new QLabel("x3", this);
    lblY1 = new QLabel("y1", this);
    lblY2 = new QLabel("y2", this);
    lblY3 = new QLabel("y3", this);
    lblColor = new QLabel("color", this);
    lblId = new QLabel("id", this);
    vlayoutLblX->addWidget(lblX1);
    vlayoutLblX->addWidget(lblX2);
    vlayoutLblX->addWidget(lblX3);
    vlayoutLblY->addWidget(lblY1);
    vlayoutLblY->addWidget(lblY2);
    vlayoutLblY->addWidget(lblY3);
    vlayoutX->addWidget(lePoint1X);
    vlayoutX->addWidget(lePoint2X);
    vlayoutX->addWidget(lePoint3X);
    vlayoutY->addWidget(lePoint1Y);
    vlayoutY->addWidget(lePoint2Y);
    vlayoutY->addWidget(lePoint3Y);connect(btnSetColor, SIGNAL(clicked()), this, SLOT(setColor()));
    HPoints->addItem(vlayoutLblX);
    HPoints->addItem(vlayoutX);
    HPoints->addItem(vlayoutLblY);
    HPoints->addItem(vlayoutY);
    HPoints->addWidget(btnChangeCoordinate);
    HRotate->addWidget(leRotate);
    HRotate->addWidget(btnRotate);
    HMultiplication->addWidget(leMultiplication);
    HMultiplication->addWidget(btnMultiplication);
    HInfo->addWidget(lblId);
    HInfo->addWidget(leId);
    HInfo->addWidget(lblColor);
    HInfo->addWidget(leColor);
    HInfo->addWidget(btnSetColor);
    connect(btnSetColor, SIGNAL(clicked()), this, SLOT(setColor()));
    connect(btnChangeCoordinate, SIGNAL(clicked()), this, SLOT(changeCoordinate()));
    connect(btnRotate, SIGNAL(clicked()), this, SLOT(rotate()));
    connect(btnMultiplication, SIGNAL(clicked()), this, SLOT(multiplicateCoordinate()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
    layout()->addWidget(view);
    layout()->addItem(HInfo);
    layout()->addItem(HPoints);
    layout()->addItem(HRotate);
    layout()->addItem(HMultiplication);
    layout()->addWidget(btnClose);
}

void Widget::printShape(){
    scene->clear();
    leColor->setText(shape->color);
    QString s =  QString::number(shape->id);
    leId->setText(s);
    QGraphicsTextItem *text;
    for(unsigned i = 0; i < shape->points.size(); ++i){
        scene->addEllipse(shape->points[i].x, shape->points[i].y, Widget::radius, Widget::radius, QPen(), QBrush(Qt::black));
        text = scene->addText(QString(i + '0'));
        text->setPos(shape->points[i].x + 3, shape->points[i].y);
    }
    scene->addLine(shape->points[0].x + Widget::radius/2, shape->points[0].y + Widget::radius/2,
                     shape->points[shape->points.size() - 1].x + Widget::radius/2, shape->points[shape->points.size() -1].y + Widget::radius/2);
    for(unsigned i = 1; i < shape->points.size(); ++i){
        scene->addLine(shape->points[i - 1].x + Widget::radius/2, shape->points[i - 1].y + Widget::radius/2,
                        shape->points[i].x + Widget::radius/2, shape->points[i].y + Widget::radius/2);
    }
}

void Widget::changeCoordinate(std::vector <class Point> newCoordinates){
    shape->changeCoordinate(newCoordinates);
}

void Widget::changeCoordinate(){
    std::vector <class Point> newCoordinates;
    newCoordinates.push_back(Point(lePoint1X->text().toInt(), lePoint1Y->text().toInt()));
    newCoordinates.push_back(Point(lePoint2X->text().toInt(), lePoint2Y->text().toInt()));
    newCoordinates.push_back(Point(lePoint3X->text().toInt(), lePoint3Y->text().toInt()));
    shape->changeCoordinate(newCoordinates);
    printShape();
}

void Widget::rotate(){
    shape->rotate(leRotate->text().toDouble());
    printShape();
}

void Widget::multiplicateCoordinate(){
    shape->multiplicateCoordinate(leMultiplication->text().toDouble());
    printShape();
}

void Widget::setColor(){
    shape->setColor(leColor->text());
}

Widget::~Widget(){
}
