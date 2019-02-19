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
#include <cmath>
#include <vector>

#define PI 3.14159

class Node{
private:
    int x;
    int y;
    int degree;
    int node_num;
    double nodeAngle;
    int nodeR;
public:
    bool isPrint;
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    void setDegree(int degree){this->degree = degree;}
    void setNode_num(int node_num){this->node_num = node_num;}
    void setNodeR(int nodeR){this->nodeR = nodeR;}
    void setNodeAngle(double nodeAngle){this->nodeAngle = nodeAngle;}
    int getX(){return x;}
    int getY(){return y;}
    int getDegree(){return degree;}
    int getNode_num(){return node_num;}
    int getNodeR(){return nodeR;}
    double getNodeAngle(){return nodeAngle;}
};

class Widget : public QWidget{
    Q_OBJECT
    int count_nodes;
    bool** connection_matrix;
    const int radius = 3;
    class Node* masNodes;
    int current_node;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QPen pen;
    QBrush brush;
    QPushButton* btn_close;
    void initMasNodes();
    void printEllipseGraph();
    void printEllipseNodes();
    void printEllipseLines();
public:
    Widget(QWidget *parent, bool**, int);
    ~Widget();
};

#endif // WIDGET_H
