#ifndef LTHEMEMANAGER_H
#define LTHEMEMANAGER_H

#include <QObject>

class LThemeManager : public QObject
{
    Q_OBJECT
public:
    explicit LThemeManager(QObject *parent = 0);

    static LThemeManager * instance();
    QString getQssForWidget(QString className);
    void setTheme(const QString theme);
signals:
    void themeChanged(QString theme);

public slots:

protected:
    QString m_theme;
};

#endif // LTHEMEMANAGER_H
