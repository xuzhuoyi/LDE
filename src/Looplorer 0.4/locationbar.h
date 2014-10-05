#ifndef LOCATIONBAR_H
#define LOCATIONBAR_H

#include <QWidget>

#include "widget.h"

namespace Ui {
class LocationBar;
}

class LocationBar : public QWidget
{
    Q_OBJECT

public:
    explicit LocationBar(Widget *parent = 0);
    ~LocationBar();

    QString getLineEditText();
    void setLineEditText();

private slots:
    void on_pushButBack_clicked();

    void on_pushButGoto_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public slots:
    void refreshlineEditAddr();

private:
    Ui::LocationBar *ui;
    Widget *parentWindow;
};

#endif // LOCATIONBAR_H
