#ifndef LANCC_H
#define LANCC_H

#include <QWidget>

namespace Ui {
class Lancc;
}

class Lancc : public QWidget
{
    Q_OBJECT
    
public:
    explicit Lancc(QWidget *parent = 0);
    ~Lancc();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Lancc *ui;

signals:
    void back();

};

#endif // LANCC_H
