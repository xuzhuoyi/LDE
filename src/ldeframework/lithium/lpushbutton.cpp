#include "lpushbutton.h"
#include "lithium_global.h"

LPushButton::LPushButton(QWidget *parent) :
    QPushButton(parent)
{
    D_THEME_INIT_WIDGET(LPushButton);
}

