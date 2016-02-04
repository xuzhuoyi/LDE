#ifndef LAPPLICATION_H
#define LAPPLICATION_H

#include <QObject>
#include <QWidget>
#include <QApplication>

class LApplication : public QApplication
{
public:
    LApplication(int &argc, char **argv);
    void setTheme(const QString & theme);
};

#endif // LAPPLICATION_H
