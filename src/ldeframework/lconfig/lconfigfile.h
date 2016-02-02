#ifndef LCONFIGFILE_H
#define LCONFIGFILE_H

#include <QFile>
#include "lconfig_global.h"

class LCONFIGSHARED_EXPORT LConfigFile : public QFile
{
    Q_OBJECT
public:
    explicit LConfigFile(QString fileName, QObject *parent = 0);

signals:

public slots:


};

#endif // LCONFIGFILE_H
