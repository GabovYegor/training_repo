#include "widget.h"

/*
    НЕОБХОДИМЫЕ ИЗМЕНЕНИЯ:
1)  регулировать радиусы и плотность вершин на радиусе
    взависимости от удаленности
2)  уменьшить ребра проходящие через центр
*/

void Widget::printEllipseGraph(){
    int currentR = 300;        // необходимо регулировать эти параметры
    int nodesDistance = 270;   // взависимости от кол-во вершин и ребер
    // чем дальше от центра тем больше плотность
    for(int i = 0; i < count_nodes; ++i){
        int n = 2 * PI * currentR / nodesDistance;
        int j = 0;
        for(; j < n && i < count_nodes; ++j, ++i){
            masNodes[i].setX(-radius + currentR * std::cos(PI * 2 * j / n  + 10));
            masNodes[i].setY(-radius + currentR * std::sin(PI * 2 * j / n  + 10));
            scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2, QPen(), QBrush(Qt::black));
            scene->addEllipse(-currentR, -currentR, currentR * 2, currentR * 2, QPen(Qt::blue));
            int currentNum = masNodes[i].getNode_num();
            if(currentNum < 10){
                QGraphicsTextItem *text = scene->addText(QString(masNodes[i].getNode_num() + '0'), QFont("Times", 12));
                text->setPos(masNodes[i].getX() + radius * 3, masNodes[i].getY() - radius * 3);
            }
            if(currentNum >= 10){
                QGraphicsTextItem *text = scene->addText(QString(masNodes[i].getNode_num() / 10 + '0') +
                                                         QString(masNodes[i].getNode_num() % 10 + '0'), QFont("Times", 12));
                text->setPos(masNodes[i].getX() + radius * 3, masNodes[i].getY() - radius * 3);
            }
        }
        currentR += 80;      // регулировать взависимости от кол_ва вершин
        nodesDistance -= 10; //
        --i;
    }
    for(int i = 0; i < count_nodes; ++i){
        for(int j = 0; j < count_nodes; ++j){
            if(connection_matrix[masNodes[i].getNode_num()][masNodes[j].getNode_num()] == 1)
                scene->addLine(masNodes[i].getX() + radius, masNodes[i].getY() + radius,
                               masNodes[j].getX() + radius, masNodes[j].getY() + radius);
        }
    }
}

Widget::Widget(QWidget *parent, bool** connection_matrix, int count_nodes) : QWidget(parent){
    this->connection_matrix = connection_matrix;
    this->count_nodes = count_nodes;
    initMasNodes();
    btn_close = new QPushButton("close", this);
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->addWidget(view);
    vlayout->addWidget(btn_close);
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
    //printRandomGraph();
    printEllipseGraph();
}

Widget::~Widget(){
    for(int i = 0; i < count_nodes; ++i)
        delete[] connection_matrix[i];
    delete[] connection_matrix;
}

int compare(const void* a, const void* b){
    return ((class Node*)b)->getDegree() - ((class Node*)a)->getDegree();
}

void Widget::initMasNodes(){
    masNodes = new Node[count_nodes];
    for(int i = 0; i < count_nodes; ++i){
        masNodes[i].setNode_num(i);
        int current_degree = 0;
        for(int j = 0; j < count_nodes; ++j){
            if(connection_matrix[i][j])
                ++current_degree;
        }
        masNodes[i].setDegree(current_degree);
    }
    std::qsort(masNodes, count_nodes, sizeof(class Node), compare);
    for(int i = 0; i < count_nodes; ++i)
        qDebug() << masNodes[i].getNode_num() << " " << masNodes[i].getDegree();
}

void Widget::printRandomGraph(){
    for(int i = 0; i < count_nodes; ++i){
        masNodes[i].setX(rand() % 500);
        masNodes[i].setY(rand() % 500);
        scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2);
        QGraphicsTextItem *text = scene->addText(QString(i + '0'), QFont("Times", 12));
        text->setPos(masNodes[i].getX() + radius * 3, masNodes[i].getY() - radius * 3);
    }
    for(int i = 0; i < count_nodes; ++i){
        for(int j = 0; j < count_nodes; ++j){
            if(connection_matrix[i][j] == 1)
                scene->addLine(masNodes[i].getX() + radius, masNodes[i].getY() + radius,
                               masNodes[j].getX() + radius, masNodes[j].getY() + radius);
        }
    }
}

