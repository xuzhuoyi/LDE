#ifndef LTEXTBUTTON_H
#define LTEXTBUTTON_H

#include <QObject>
#include <QWidget>
#include <lpushbutton.h>

class LTextButton : public LPushButton
{
public:
    LTextButton(const QString &text, QWidget *parent = 0);
};

#endif // LTEXTBUTTON_H
