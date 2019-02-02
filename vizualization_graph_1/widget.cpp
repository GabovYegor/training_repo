#include "widget.h"

Widget::Widget(QWidget *parent, bool** connection_matrix, int count_nodes) : QWidget(parent){
    this->connection_matrix = connection_matrix;
    this->count_nodes = count_nodes;
    btn_close = new QPushButton("close", this);
    masNodes = new Node[count_nodes];
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    pen = QPen(Qt::yellow);
    pen.setWidth(2);
    brush = QBrush(Qt::black);
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->addWidget(view);
    vlayout->addWidget(btn_close);
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
    for(int i = 0; i < count_nodes; ++i){
        masNodes[i].setX(rand() % 300);
        masNodes[i].setY(rand() % 300);
        scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2);
        QGraphicsTextItem *text = scene->addText(QString(i + '0'), QFont("Times", 12));
        text->setPos(masNodes[i].getX() + radius * 3, masNodes[i].getY() - radius * 3);
    }
    for(int i = 0; i < count_nodes; ++i){
        for(int j = 0; j < i+1; ++j){
            if(connection_matrix[i][j] == 1)
                scene->addLine(masNodes[i].getX() + radius, masNodes[i].getY() + radius,
                               masNodes[j].getX() + radius, masNodes[j].getY() + radius);
        }
    }
}

Widget::~Widget(){
    for(int i = 0; i < count_nodes; ++i)
        delete[] connection_matrix[i];
    delete[] connection_matrix;
}
