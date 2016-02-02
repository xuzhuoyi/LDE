#ifndef LCONFIG_H
#define LCONFIG_H

#include <QSettings>
#include "lconfig_global.h"
#include "lconfigfile.h"

class LCONFIGSHARED_EXPORT LConfig : public QSettings
{

public:
    LConfig(LConfigFile confFile, QObject *parent = 0);
    static QString homePath();
};

#endif // LCONFIG_H
