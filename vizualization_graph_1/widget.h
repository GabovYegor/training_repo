#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QPen>
#include <QBrush>
#include <QVBoxLayout>
#include <QGraphicsTextItem>
#include <QDebug>

class Widget : public QWidget{
    Q_OBJECT
    int count_of_nodes;
    bool** connection_matrix;
    const int radius = 8;
    int* mas_X;
    int* mas_Y;
    int current_node;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QPen pen;
    QBrush brush;
    QPushButton* btn_close;
public:
    Widget(QWidget *parent, bool**, int);
    ~Widget();
};

#endif // WIDGET_H
