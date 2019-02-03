#include "widget.h"

/*
    n = 2*pi*R/80 - кол-во на уровне;
*/

void Widget::printEllipseGraph(){
    /*
    int R1 = 60, R2 = 2 * R1;
    int x = -radius;
    int y = -radius;
    double angle = 144;
    int num_nodes = 10;
    scene->addEllipse(x, y, radius * 2, radius * 2);
    scene->addEllipse(-R1, -R1, R1 * 2, R1 * 2, QPen(Qt::blue));
    scene->addEllipse(x + R1 * std::cos(-PI/180 * angle), y + R1 * std::sin(-PI/180 * angle),radius*2, radius * 2);
    scene->addEllipse(-R2, -R2, R2 * 2, R2 * 2, QPen(Qt::blue));
    for(int i = 0; i < num_nodes; ++i){
        scene->addEllipse(x + R2 * std::cos(-PI * 2 * i / num_nodes), y + R2 * std::sin(-PI * 2 * i / num_nodes), radius * 2, radius * 2);
    }
    */
    int currentR = 80;
    int i = 0;
    int nodesDistance = 80;
    for(; i < count_nodes; ++i){
        int n = 2 * PI * currentR / nodesDistance;
        int j = 0;
        for(; j < n && i < count_nodes; ++j, ++i){
            masNodes[i].setX(-radius + currentR * std::cos(PI * 2 * j / n));
            masNodes[i].setY(-radius + currentR * std::sin(PI * 2 * j / n));
            scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2);
            scene->addEllipse(-currentR, -currentR, currentR * 2, currentR * 2, QPen(Qt::blue));
            QGraphicsTextItem *text = scene->addText(QString(masNodes[i].getNode_num() + '0'), QFont("Times", 12));
            text->setPos(masNodes[i].getX() + radius * 3, masNodes[i].getY() - radius * 3);
        }
        currentR += 60;
        --i;
    }
    i = 0;
    for(; i < count_nodes; ++i){
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
        masNodes[i].setX(rand() % 300);
        masNodes[i].setY(rand() % 300);
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

