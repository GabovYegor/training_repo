#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Widget w;
    w.setMinimumSize(300, 200);
    w.show();
    return a.exec();
}
