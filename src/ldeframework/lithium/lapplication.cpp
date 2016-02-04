#include "lapplication.h"
#include "lthememanager.h"

LApplication::LApplication(int &argc, char **argv) :
    QApplication(argc, argv)
{

}

void LApplication::setTheme(const QString & theme)
{
    LThemeManager * themeManager = LThemeManager::instance();
    themeManager->setTheme(theme);
}

