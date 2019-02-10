#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

    QPushButton *m_btnOk;
    QPushButton* m_btnExit;
    QLineEdit* m_name;

public:
    explicit Dialog(QWidget *parent = 0);
signals:

public slots:
    void sayHello();
};

#endif // DIALOG_H
