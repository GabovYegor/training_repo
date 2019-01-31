#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMessageBox>

class Widget : public QWidget{
    Q_OBJECT
    const int radius = 8;
    const int node_count = 100;
    int* mas_X;
    int* mas_Y;
    int current_node;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QVBoxLayout* vlayout;
    QHBoxLayout* hlayout;
    QLineEdit* line_x;
    QLineEdit* line_y;
    QPushButton* btn_close;
    QPushButton* btn_add_Node;
    QPen pen;
    QBrush brush;
    void printLines();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void addNode();
};

#endif // WIDGET_H
