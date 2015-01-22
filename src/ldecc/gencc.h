#ifndef GENCC_H
#define GENCC_H

#include <QWidget>

namespace Ui {
class Gencc;
}

class Gencc : public QWidget
{
    Q_OBJECT
    
public:
    explicit Gencc(QWidget *parent = 0);
    ~Gencc();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Gencc *ui;

signals:
    void back();

};

#endif // GENCC_H
