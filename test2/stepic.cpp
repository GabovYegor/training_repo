#include "stepic.h"
#include "ui_stepic.h"
#include <iostream>

Stepic::Stepic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stepic)
{
    ui->setupUi(this);
}

Stepic::~Stepic()
{
    delete ui;
}


void Stepic::on_pushButton_clicked(){
    if(ui->que1->isChecked() && ui->que2->isChecked())
        ui->result->setText("beautiful!!!");
    else
        ui->result->setText("it is WRONG!!!");
}
