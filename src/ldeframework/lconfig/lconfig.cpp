#include "lconfig.h"
#include <QDir>


LConfig::LConfig(LConfigFile *confFile, QObject * parent) : QSettings(confFile->fileName(), QSettings::IniFormat, parent)
{

}

QString LConfig::homePath()
{
    return QDir::homePath();
}
