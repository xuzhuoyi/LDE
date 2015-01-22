#ifndef SAFCC_H
#define SAFCC_H

#include <QWidget>

namespace Ui {
class Safcc;
}

class Safcc : public QWidget
{
    Q_OBJECT

public:
    explicit Safcc(QWidget *parent = 0);
    ~Safcc();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Safcc *ui;

signals:
    void back();

};

#endif // SAFCC_H
