#include "widget.h"

Widget::Widget(QWidget *parent, bool** connection_matrix, int count_of_nodes) : QWidget(parent){
    this->connection_matrix = connection_matrix;
    this->count_of_nodes = count_of_nodes;
    btn_close = new QPushButton("close", this);
    mas_X = new int[count_of_nodes];
    mas_Y = new int[count_of_nodes];
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    pen = QPen(Qt::yellow);
    pen.setWidth(2);
    brush = QBrush(Qt::black);
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->addWidget(view);
    vlayout->addWidget(btn_close);
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
    for(int i = 0; i < count_of_nodes; ++i){
        mas_X[i] = rand() % 300;
        mas_Y[i] = rand() % 300;
        scene->addEllipse(mas_X[i], mas_Y[i], radius * 2, radius * 2);
        QGraphicsTextItem *text = scene->addText(QString(i + '0'), QFont("Times", 12));
        text->setPos(mas_X[i] + radius * 3, mas_Y[i] - radius * 3);
    }
    for(int i = 0; i < count_of_nodes; ++i){
        for(int j = 0; j < count_of_nodes; ++j){
            if(connection_matrix[i][j] == 1)
                scene->addLine(mas_X[i] + radius, mas_Y[i] + radius, mas_X[j] + radius, mas_Y[j] + radius);
        }
    }
}

Widget::~Widget(){
    delete[] mas_X;
    delete[] mas_Y;
    for(int i = 0; i < count_of_nodes; ++i)
        delete[] connection_matrix[i];
    delete[] connection_matrix;
}
