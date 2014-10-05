#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   Widget w;
    //检查是否已经运行
    //if (!a.isRunning())
        //return 0;
    w.show();

    //MainWindow w;
    //w.show();
    return a.exec();
}
