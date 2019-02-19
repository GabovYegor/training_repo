#include "widget.h"

/**
    возможное улучшение - располагать соединенные вершины на уровне рядом
    но тогда может разрушиться основная идея
    Проблемы:
    1) мест на уровне не меньше чем на предыдущем
        если вершин меньше чем на предыдущем уровне - последний уровень - записать оставшиеся вершины
    2) правильно регулировать радиус
*/

void Widget::printEllipseGraph(){
    int lengthEllipseNodes = 150;
    masNodes[0].setNodeR(0);
    masNodes[0].setNodeAngle(0); // print centre node
    masNodes[0].setX(-radius + masNodes[0].getNodeR() * std::cos(masNodes[0].getNodeAngle()));
    masNodes[0].setY(-radius + masNodes[0].getNodeR() * std::sin(masNodes[0].getNodeAngle()));
    masNodes[0].isPrint = true;
    int countConnectZero = 0;
    for(int i = 0; i < count_nodes; ++i){
        if(connection_matrix[masNodes[0].getNode_num()][masNodes[i].getNode_num()])
            ++countConnectZero;
    }
    int currentR = countConnectZero * lengthEllipseNodes / 2 / PI;
    double currentAngle = 0;
    std::vector <class Node> printedNodes;
    printedNodes.push_back(masNodes[0]);
    for(int i = 0; i < count_nodes; ++i){
        if(connection_matrix[masNodes[0].getNode_num()][masNodes[i].getNode_num()]){
            currentAngle += 2 * PI / countConnectZero;
            masNodes[i].setNodeR(currentR);
            masNodes[i].setNodeAngle(currentAngle);
            masNodes[i].setX(-radius + masNodes[i].getNodeR() * std::cos(masNodes[i].getNodeAngle()));
            masNodes[i].setY(-radius + masNodes[i].getNodeR() * std::sin(masNodes[i].getNodeAngle()));
            masNodes[i].isPrint = true;
            printedNodes.push_back(masNodes[i]);
        }
    }
    bool isEnd = false;
    while(!isEnd){ // добавить вершины с нулевыми связями?
        std::vector <class Node> readyToPrint;
        for(int i = 0; i < count_nodes; ++i){
            bool isContinue = false;
            for(size_t k = 0; k < printedNodes.size(); ++k)
                if(masNodes[i].getNode_num() == printedNodes[k].getNode_num())
                    isContinue = true;
            if(isContinue)
                continue;
            for(size_t j = 0; j < printedNodes.size(); ++j){
                isContinue = false;
                for(size_t k = 0; k < readyToPrint.size(); ++k)
                    if(readyToPrint[k].getNode_num() == masNodes[i].getNode_num())
                        isContinue = true;
                if(isContinue)
                    continue;
                if(connection_matrix[printedNodes[j].getNode_num()][masNodes[i].getNode_num()])
                    readyToPrint.push_back(masNodes[i]);
            }
        }
        if(!readyToPrint.size())
            isEnd = true;
        std::vector <bool> placeNodes(readyToPrint.size());
        if(currentR * 2 < 400)
            currentR *= 2;
        else
            currentR += 400;
        for(size_t i = 0; i < readyToPrint.size(); ++i)
            placeNodes[i] = false;
        for(size_t i = 0; i < readyToPrint.size(); ++i){
            int minLengthPath = 2147483647;
            double minAngle = 0;
            int minJ = 0;
            readyToPrint[i].setNodeR(currentR);
            for(size_t j = 0; j < readyToPrint.size(); ++j){
                if(placeNodes[j])
                    continue;
                int currentMinLengthPath = 0;
                readyToPrint[i].setNodeAngle(2 * PI * j / readyToPrint.size());
                readyToPrint[i].setX(-radius + readyToPrint[i].getNodeR() * std::cos(readyToPrint[i].getNodeAngle()));
                readyToPrint[i].setY(-radius + readyToPrint[i].getNodeR() * std::sin(readyToPrint[i].getNodeAngle()));
                for(size_t k = 0; k < printedNodes.size(); ++k){
                    if(connection_matrix[printedNodes[k].getNode_num()][readyToPrint[i].getNode_num()])
                        currentMinLengthPath += sqrt(pow((readyToPrint[i].getX() - printedNodes[i].getX()), 2) +
                                                     pow((readyToPrint[i].getY() - printedNodes[i].getY()), 2));
                }
                if(currentMinLengthPath < minLengthPath){
                    minLengthPath = currentMinLengthPath;
                    minAngle = readyToPrint[i].getNodeAngle();
                    minJ = j;
                }
            }
            readyToPrint[i].setX(-radius + currentR * std::cos(minAngle));
            readyToPrint[i].setY(-radius + currentR * std::sin(minAngle));
            placeNodes[minJ] = true;
            for(int q = 0; q < count_nodes; ++q)
                if(masNodes[q].getNode_num() == readyToPrint[i].getNode_num()){
                    masNodes[q].setX(readyToPrint[i].getX());
                    masNodes[q].setY(readyToPrint[i].getY());
                    masNodes[q].isPrint = true;
                }
        }
        for(size_t i = 0; i < readyToPrint.size(); ++i){
            printedNodes.push_back(readyToPrint[i]);
        }
    }
    printEllipseNodes();
    printEllipseLines();
}

void Widget::printEllipseNodes(){
    for(int i = 0; i < count_nodes; ++i){
        if(masNodes[i].isPrint){
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
}

void Widget::printEllipseLines(){
    for(int i = 0; i < count_nodes; ++i){
        for(int j = 0; j < count_nodes; ++j){
            pen.setColor(Qt::GlobalColor(rand() % 10 + 1));
            if(connection_matrix[masNodes[i].getNode_num()][masNodes[j].getNode_num()] == 1
                    && masNodes[i].isPrint && masNodes[j].isPrint)
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
        masNodes[i].setY(1000 + i * 10);
        masNodes[i].setX(-1000);
        masNodes[i].isPrint = false;
    }
    btn_close = new QPushButton("close", this);
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->addWidget(view);
    vlayout->addWidget(btn_close);
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
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
