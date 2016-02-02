#include "lconfigfile.h"

LConfigFile::LConfigFile(QString fileName, QObject *parent = 0) :
    QFile(fileName, parent)
{

}
