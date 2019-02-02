#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QString>

bool** createConnectionMatrix(QString file_name, int& count_nodes){
    QString str;
    bool** connection_matrix;
    QFile in_file(file_name); // лежит в директории сборки
    in_file.open(QIODevice::ReadOnly);
    str = in_file.readLine();
    count_nodes = str.toInt();
    connection_matrix = new bool*[count_nodes];
    for(int i = 0; i < count_nodes; ++i){
        str = in_file.readLine();
        qDebug() << str;
        connection_matrix[i] = new bool[i+1]; // треугольный массив - выигрыш в памяти в 2 раза - диагональ
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
    return connection_matrix;
}
/* силовой алгоритм: аналог заряда
 * чем больше связей, тем ближе к центру
 */

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    srand(time(nullptr));
    bool** connection_matrix;
    int count_nodes = 0;
    connection_matrix = createConnectionMatrix("test1.txt", count_nodes);
    Widget w(nullptr, connection_matrix, count_nodes);
    w.show();
    return a.exec();
}
