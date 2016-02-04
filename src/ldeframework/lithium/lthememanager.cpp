#include "lthememanager.h"
#include <QIODevice>
#include <QFile>


class LThemeManagerPrivate : public LThemeManager
{

};

Q_GLOBAL_STATIC(LThemeManagerPrivate, LThemeManagerStatic)

LThemeManager * LThemeManager::instance()
{
    return LThemeManagerStatic;
}

LThemeManager::LThemeManager(QObject *parent) : QObject(parent)
{

}

QString LThemeManager::getQssForWidget(QString className)
{
    QString qss;

    QFile themeFile(QString(":/themes/%1/%2.theme").arg(m_theme).arg(className));

    if (themeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qss = themeFile.readAll();

        themeFile.close();
    }

    return qss;
}

void LThemeManager::setTheme(const QString theme)
{
    if (m_theme != theme) {
        m_theme = theme;

        emit themeChanged(theme);
    }
}

