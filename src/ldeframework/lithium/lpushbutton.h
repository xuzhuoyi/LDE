#ifndef LPUSHBUTTON_H
#define LPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class LPushButton : public QPushButton
{
    Q_OBJECT
public:
    LPushButton(QWidget *parent = 0);
    LPushButton(QString const &text, QWidget *parent = 0);
};

#endif // LPUSHBUTTON_H
