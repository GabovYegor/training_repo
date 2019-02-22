#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QString>

bool createConnectionMatrix(QString file_name, int& count_nodes, bool**& connection_matrix){
    QString str;
    QFile in_file(file_name); // лежит в директории сборки
    if(!in_file.exists(file_name))
        return false;
    in_file.open(QIODevice::ReadOnly);
    if(!in_file.isOpen())
        return false;
    str = in_file.readLine();
    count_nodes = str.toInt();
    connection_matrix = new bool*[count_nodes];
    for(int i = 0; i < count_nodes; ++i){
        str = in_file.readLine();
        connection_matrix[i] = new bool[count_nodes];
        for(int j = 0, k = 0; j < str.length(); ++j){
            if(str[j] == "1"){
                connection_matrix[i][k] = true;
                ++k;
            }
            if(str[j] == "0"){
                connection_matrix[i][k] = false;
                ++k;
            }
        }
    }
    in_file.close();
    return true;
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    srand(time(nullptr));
    bool** connection_matrix;
    int count_nodes = 0;
    if(argc == 2){
        if(!createConnectionMatrix(argv[1], count_nodes, connection_matrix)){
            qDebug() << "error with createConnectionMatrix";
            return 1;
        }
    }
    else
        if(!createConnectionMatrix("100nodes.txt", count_nodes, connection_matrix)){
            qDebug() << "error with createConnectionMatrix";
            return 1;
        }

    Widget w(nullptr, connection_matrix, count_nodes);
    w.show();
    return a.exec();
}
