#ifndef LAPPLICATION_H
#define LAPPLICATION_H

#include <QObject>
#include <QWidget>
#include <QApplication>

class LApplication : public QApplication
{
public:
    LApplication(int &argc, char **argv);
};

#endif // LAPPLICATION_H
