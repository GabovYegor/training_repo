#include "widget.h"

void Widget::printEllipseGraph2(){
    int lengthEllipseNodes = 70;
    masNodes[0].setNodeR(0);
    masNodes[0].setNodeAngle(0); // print centre node
    int countConnectZero = 0;
    for(int i = 0; i < count_nodes; ++i){
        if(connection_matrix[masNodes[0].getNode_num()][masNodes[i].getNode_num()])
            ++countConnectZero;
    }
    int currentR = 0;
    double currentAngle = 0;
    std::vector <class Node> printedNodes;
    printedNodes.push_back(masNodes[0]);
    for(int i = 0; i < count_nodes; ++i){  // print second level
        if(connection_matrix[masNodes[0].getNode_num()][masNodes[i].getNode_num()]){
            currentAngle += 2 * PI / countConnectZero;
            masNodes[i].isPrint = true;
            currentR = countConnectZero * lengthEllipseNodes / 2 / PI;
            masNodes[i].setNodeR(currentR);
            masNodes[i].setNodeAngle(currentAngle);
            masNodes[i].setX(-radius + masNodes[i].getNodeR() * std::cos(masNodes[i].getNodeAngle()));
            masNodes[i].setY(-radius + masNodes[i].getNodeR() * std::sin(masNodes[i].getNodeAngle()));
            //scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2, QPen(), QBrush(Qt::black));
            printedNodes.push_back(masNodes[i]);
        }
    }
    scene->addEllipse(-currentR, -currentR, currentR * 2, currentR * 2, QPen(Qt::blue));
    currentR *= 2; // ?
    scene->addEllipse(-currentR, -currentR, currentR * 2, currentR * 2, QPen(Qt::blue));

    int countNodesLevel = 2 * PI * currentR / lengthEllipseNodes;
    bool masEllipsePlace[countNodesLevel];
    for(int i = 0; i < countNodesLevel; ++i)
        masEllipsePlace[i] = false;
    bool full = false;
    for(int k = 0; k < count_nodes && !full; ++k){
        int minLength = 32767;
        int minJ = 0;
        int currentMinLength = 0;
        double minAngle = 0;
        bool isPrint = false;
        for(int i = 0; i < printedNodes.size(); ++i)
            if(printedNodes[i].getNode_num() == masNodes[k].getNode_num())
                isPrint = true;
        if(isPrint)
            continue;
        for(int j = 0; j < countNodesLevel; ++j){
            currentMinLength = 0;
            if(masEllipsePlace[j])
                continue;
            masNodes[k].setNodeR(currentR);
            masNodes[k].setNodeAngle(2 * PI * j / countNodesLevel);
            masNodes[k].setX(-radius + masNodes[k].getNodeR() * std::cos(masNodes[k].getNodeAngle()));
            masNodes[k].setY(-radius + masNodes[k].getNodeR() * std::sin(masNodes[k].getNodeAngle()));
            bool isConnect = false;
            for(int i = 0; i < printedNodes.size(); ++i){
                if(connection_matrix[printedNodes[i].getNode_num()][masNodes[k].getNode_num()]){
                    currentMinLength += sqrt(pow(printedNodes[i].getX() - masNodes[k].getX(), 2) +
                                             pow(printedNodes[i].getY() - masNodes[k].getY(), 2));
                    isConnect = true;
                }
            }
            if(!isConnect){
                continue;
            }

            if(currentMinLength < minLength){
                minLength = currentMinLength;
                minAngle = 2 * PI * j / countNodesLevel;
                minJ = j;
            }
        }
        full = true;
        for(int i = 0; i < countNodesLevel; ++i){
            if(!masEllipsePlace[i])
                full = false;
        }
        masNodes[k].setNodeAngle(minAngle);
        masEllipsePlace[minJ] = true;
    }
    printEllipseNodes();
    printEllipseLines();
}

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
        currentR += 200;
        --i;
    }
    printEllipseNodes();
    printEllipseLines();
}

void Widget::printEllipseNodes(){        //scene->addEllipse(-currentR, -currentR, currentR * 2, currentR * 2, QPen(Qt::blue));
    for(int i = 0; i < count_nodes; ++i){
        masNodes[i].setX(-radius + masNodes[i].getNodeR() * std::cos(masNodes[i].getNodeAngle()));
        masNodes[i].setY(-radius + masNodes[i].getNodeR() * std::sin(masNodes[i].getNodeAngle()));
        scene->addEllipse(masNodes[i].getX(), masNodes[i].getY(), radius * 2, radius * 2, QPen(), QBrush(Qt::black));
        QGraphicsTextItem *text;
        int currentNum = masNodes[i].getNode_num();
        int countDigit = 0;
        int tempCurrentNum = currentNum;
        for(;tempCurrentNum; ++countDigit){
            tempCurrentNum /= 10;
        }
        if(!countDigit){
            text = scene->addText(QString("0"));
            text->setPos(masNodes[i].getX() + radius * 3 + 7, masNodes[i].getY() - radius * 3);
        }
        for(int k = countDigit; k > 0; --k, currentNum /= 10){
            text = scene->addText(QString(currentNum % 10 + '0'));
            text->setPos(masNodes[i].getX() + radius * 3 + k * 7, masNodes[i].getY() - radius * 3);
        }
    }
}

void Widget::printEllipseLines(){
    for(int i = 0; i < count_nodes; ++i){
        for(int j = 0; j < count_nodes; ++j){
            pen.setColor(Qt::GlobalColor(rand() % 10 + 1));
            if(connection_matrix[masNodes[i].getNode_num()][masNodes[j].getNode_num()] == 1)
                scene->addLine(masNodes[i].getX() + radius, masNodes[i].getY() + radius,
                               masNodes[j].getX() + radius, masNodes[j].getY() + radius, pen);
        }
    }
}

Widget::Widget(QWidget *parent, bool** connection_matrix, int count_nodes) : QWidget(parent){
    this->connection_matrix = connection_matrix;
    this->count_nodes = count_nodes;
    initMasNodes();
    for(int i = 0; i < count_nodes; i++){
        masNodes[i].setNodeAngle(0);
        masNodes[i].setNodeR(1000);
    }
    btn_close = new QPushButton("close", this);
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->addWidget(view);
    vlayout->addWidget(btn_close);
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
    printEllipseGraph2();
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
