#include "widget.h"

void Widget::printEllipseGraph(){ // вершина определяется в полярных координатах
    int currentR = 200;
    int nodesDistance = 100;
    for(int i = 0; i < count_nodes; ++i){
        int n = 2 * PI * currentR / nodesDistance;
        int j = 0;
        for(; j < n && i < count_nodes; ++j, ++i){
            double currentAngle = PI * 2 * j / n + currentAngle / 100; // последнее слагаемое - чтобы не стояли на одной линии
            masNodes[i].setNodeAngle(currentAngle);                      // а немного закручивались по спирали
            masNodes[i].setNodeR(currentR);
        }
        currentR *= 1.5;
        --i;
    }
    printEllipseNodes();
    printEllipseLines();
}

void Widget::printEllipseNodes(){        //scene->addEllipse(-currentR, -currentR, currentR * 2, currentR * 2, QPen(Qt::blue));
    for(int i =0; i < count_nodes; ++i){
        masNodes[i].setX(-radius + masNodes[i].getNodeR() * std::cos(masNodes[i].getNodeAngle()));
        masNodes[i].setY(-radius + masNodes[i].getNodeR() * std::sin(masNodes[i].getNodeAngle()));
        scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2, QPen(), QBrush(Qt::black));
        int currentNum = masNodes[i].getNode_num();
        int countDigit = 0;
        int tempCurrentNum = currentNum;
        for(;tempCurrentNum; ++countDigit){
            tempCurrentNum /= 10;
        }
        for(int k = countDigit; k > 0; --k, currentNum /= 10){
            QGraphicsTextItem *text = scene->addText(QString(currentNum % 10 + '0'));
            text->setPos(masNodes[i].getX() + radius * 3 + k * 7, masNodes[i].getY() - radius * 3);
        }
    }
}

void Widget::printEllipseLines(){
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
        masNodes[i].setX(rand() % 1000);
        masNodes[i].setY(rand() % 1000);
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

