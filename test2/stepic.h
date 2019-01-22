#ifndef STEPIC_H
#define STEPIC_H

#include <QDialog>

namespace Ui {
class Stepic;
}

class Stepic : public QDialog
{
    Q_OBJECT

public:
    explicit Stepic(QWidget *parent = 0);
    ~Stepic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Stepic *ui;
};

#endif // STEPIC_H
