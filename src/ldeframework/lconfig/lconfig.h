#ifndef LCONFIG_H
#define LCONFIG_H

#include <QSettings>
#include "lconfigfile.h"

class LConfig : public QSettings
{

public:
    LConfig(LConfigFile *confFile, QObject *parent = 0);
    static QString homePath();
};

#endif // LCONFIG_H
