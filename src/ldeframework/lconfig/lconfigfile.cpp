#include "lconfigfile.h"

LConfigFile::LConfigFile(QString fileName, QObject *parent) :
    QFile(fileName, parent)
{

}
