#ifndef LCONFIGBASE_H
#define LCONFIGBASE_H

#include <QObject>

class LConfigBase : public QObject
{
    Q_OBJECT
public:
    explicit LConfigBase(QObject *parent = 0);

signals:

public slots:
};

#endif // LCONFIGBASE_H