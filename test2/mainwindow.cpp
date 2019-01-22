#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "stepic.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    QString login = ui->login->text();
    QString password = ui->password->text();
    Stepic step_win;
    ui->statusBar->showMessage("HELLO!!!");
    if(login == "egor" && password == "10012000" || login == "toma" && password == "12345"){
        step_win.setModal(true);
        step_win.exec();
    }
}
