#ifndef DESCC_H
#define DESCC_H

#include <QWidget>

namespace Ui {
class Descc;
}

class Descc : public QWidget
{
    Q_OBJECT

public:
    explicit Descc(QWidget *parent = 0);
    ~Descc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Descc *ui;
    QString fileName;

signals:
    void back();
};

#endif // DESCC_H
