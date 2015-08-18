#include <QApplication>
#include <QDebug>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include "widget.h"
#include "laboutwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLineOption opName("n");
    opName.setValueName("name");
    QCommandLineOption opVer("v");
    opVer.setValueName("version");
    QCommandLineParser parser;
    parser.addOption(opName);
    parser.addOption(opVer);
    parser.process(a);
    Widget w;
    LAboutWidget *aw;
    if(!parser.isSet(opName) && !parser.isSet(opVer))
    {
        w.show();
    }
    else
    {
        aw = new LAboutWidget(parser.value(opName), parser.value(opVer));
        aw->show();
    }

    return a.exec();
}
