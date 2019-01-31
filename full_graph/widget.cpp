#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent){
    current_node = 0;
    mas_X = new int(node_count);
    mas_Y = new int(node_count);
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    vlayout = new QVBoxLayout(this);
    hlayout = new QHBoxLayout;
    line_x = new QLineEdit(this);
    line_y = new QLineEdit(this);
    btn_close = new QPushButton("close", this);
    btn_add_Node = new QPushButton("add_Node", this);
    pen = QPen(Qt::yellow);
    pen.setWidth(2);
    brush = QBrush(Qt::black);
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
    connect(btn_add_Node, SIGNAL(clicked()), this, SLOT(addNode()));
    hlayout->addWidget(line_x);
    hlayout->addWidget(line_y);
    hlayout->addWidget(btn_close);
    hlayout->addWidget(btn_add_Node);
    vlayout->addWidget(view);
    vlayout->addItem(hlayout);
    scene->setBackgroundBrush(Qt::blue);
}

void Widget::addNode(){
    QMessageBox::information(this, "information", "add new Node with coordination: x = "
                             + line_x->text() + " y = " + line_y->text());
    mas_X[current_node] = line_x->text().toInt();
    mas_Y[current_node]= line_y->text().toInt();
    scene->addEllipse(line_x->text().toInt(), line_y->text().toInt(), radius * 2, radius * 2, pen, brush);
    printLines();
}

void Widget::printLines(){
    for(int i = 0 ; i < current_node; i++)
        scene->addLine(line_x->text().toInt() + radius, line_y->text().toInt() + radius,
                       mas_X[i] + radius, mas_Y[i] + radius, pen);

    ++current_node;
}

Widget::~Widget(){
    delete mas_X;
    delete mas_Y;
}
