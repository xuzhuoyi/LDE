#include <QApplication>
#include "ldecc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ldecc w;
    w.show();
    
    return a.exec();
}
