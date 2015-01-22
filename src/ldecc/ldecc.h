#ifndef LDECC_H
#define LDECC_H

#include <QWidget>
#include "gencc.h"
#include "lancc.h"
#include "safcc.h"

namespace Ui {
class ldecc;
}

class ldecc : public QWidget
{
    Q_OBJECT
    
public:
    explicit ldecc(QWidget *parent = 0);
    ~ldecc();
    
private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::ldecc *ui;
    Gencc g;
    Lancc l;
    Safcc s;
};

#endif // LDECC_H
