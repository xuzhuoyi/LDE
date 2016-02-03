#ifndef LCONFIGFILE_H
#define LCONFIGFILE_H

#include <QFile>

class LConfigFile : public QFile
{
    Q_OBJECT
public:
    explicit LConfigFile(QString fileName, QObject *parent = 0);

signals:

public slots:


};

#endif // LCONFIGFILE_H
