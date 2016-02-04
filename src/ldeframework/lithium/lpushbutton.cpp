#include "lpushbutton.h"
#include "lithium_global.h"

LPushButton::LPushButton(QWidget *parent) :
    QPushButton(parent)
{
    L_THEME_INIT_WIDGET(LPushButton);
}

LPushButton::LPushButton(QString const &text, QWidget *parent) :
    QPushButton(text, parent)
{
    L_THEME_INIT_WIDGET(LPushButton);
}

