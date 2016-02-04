#include "ltextbutton.h"
#include "lithium_global.h"

LTextButton::LTextButton(const QString & text, QWidget * parent) :
    LPushButton(text, parent)
{
    L_THEME_INIT_WIDGET(DTextButton);
}

