#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) : QDialog(parent){
    setLayout(new QVBoxLayout());
    QHBoxLayout *input = new QHBoxLayout();
    QHBoxLayout *buttons = new QHBoxLayout();
    m_name = new QLineEdit(this);
    m_btnOk = new QPushButton("OK", this);
    m_btnExit = new QPushButton("Exit", this);

    input->addWidget(new QLabel("Name", this));
    input->addWidget(m_name);
    buttons->addWidget(m_btnOk);
    buttons->addWidget(m_btnExit);

    layout()->addItem(input);
    layout()->addItem(buttons);
    connect(m_btnOk, SIGNAL(clicked()), this, SLOT(sayHello()));
    connect(m_btnExit, SIGNAL(clicked()), this, SLOT(close()));
}

void Dialog::sayHello(){
    QMessageBox::information(this, "hello", "HELLO " + m_name->text());
}
