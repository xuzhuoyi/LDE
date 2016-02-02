#include "lconfig.h"
#include <QDir>


LConfig::LConfig(LConfigFile confFile, QObject * parent = 0) : QSettings(confFile.fileName(), QSettings::IniFormat, parent)
{

}

QString LConfig::homePath()
{
    return QDir::homePath();
}
