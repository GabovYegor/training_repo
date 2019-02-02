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

class Node{
    int x;
    int y;
    //int count_graph_edge;
public:
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    int getX(){return x;}
    int getY(){return y;}
};

class Widget : public QWidget{
    Q_OBJECT
    int count_nodes;
    bool** connection_matrix;
    const int radius = 8;
    class Node* masNodes;
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
