#include "widget.h"

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
    QHBoxLayout* hlayout = new QHBoxLayout;
    btnChangeCoordinate = new QPushButton("change coordinate", this);
    lePoint1X = new QLineEdit(this);
    lePoint2X = new QLineEdit(this);
    lePoint3X = new QLineEdit(this);
    lePoint1Y = new QLineEdit(this);
    lePoint2Y = new QLineEdit(this);
    lePoint3Y = new QLineEdit(this);
    lblX1 = new QLabel("x1", this);
    lblX2 = new QLabel("x2", this);
    lblX3 = new QLabel("x3", this);
    lblY1 = new QLabel("y1", this);
    lblY2 = new QLabel("y2", this);
    lblY3 = new QLabel("y3", this);
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
    vlayoutY->addWidget(lePoint3Y);
    HPoints->addItem(vlayoutLblX);
    HPoints->addItem(vlayoutX);
    HPoints->addItem(vlayoutLblY);
    HPoints->addItem(vlayoutY);
    HPoints->addWidget(btnChangeCoordinate);
    btnClose = new QPushButton("CLOSE", this);
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
    layout()->addWidget(view);
    layout()->addItem(HPoints);
    layout()->addWidget(btnClose);
    layout()->addItem(hlayout);
}

//void Parallelogram::print(Widget& w){
//    w.scene->clear();
//    QGraphicsTextItem *text;
//    for(unsigned i = 0; i < points.size(); ++i){
//        w.scene->addEllipse(points[i].x, points[i].y, Widget::radius, Widget::radius, QPen(), QBrush(Qt::black));
//        text = w.scene->addText(QString(i + '0'));
//        text->setPos(points[i].x + 3, points[i].y);
//    }
//    w.scene->addLine(points[0].x + Widget::radius/2, points[0].y + Widget::radius/2,
//                     points[points.size() - 1].x + Widget::radius/2, points[points.size() -1].y + Widget::radius/2);
//    for(unsigned i = 1; i < points.size(); ++i){
//        w.scene->addLine(points[i - 1].x + Widget::radius/2, points[i - 1].y + Widget::radius/2,
//                        points[i].x + Widget::radius/2, points[i].y + Widget::radius/2);
//    }
//}

//void Ellipse::print(Widget& w){
//    w.scene->clear();
//    QGraphicsTextItem *text;
//    for(unsigned i = 0; i < points.size(); ++i){
//        w.scene->addEllipse(points[i].x, points[i].y, Widget::radius, Widget::radius, QPen(), QBrush(Qt::black));
//        text = w.scene->addText(QString(i + '0'));
//        text->setPos(points[i].x + 3, points[i].y);
//    }
//    w.scene->addLine(points[1].x + Widget::radius/2, points[1].y + Widget::radius/2,
//                     points[points.size() - 1].x + Widget::radius/2, points[points.size() -1].y + Widget::radius/2);
//    for(unsigned i = 2; i < points.size(); ++i){
//        w.scene->addLine(points[i - 1].x + Widget::radius/2, points[i - 1].y + Widget::radius/2,
//                        points[i].x + Widget::radius/2, points[i].y + Widget::radius/2);
//    }
//}

Widget::~Widget(){

}
