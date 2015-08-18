#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QList>

class QListWidget;
class QGridLayout;

class History : public QWidget
{
    Q_OBJECT
public:
    explicit History(QWidget *parent = 0);
    QList<double> *listHistory();
    void refreshList();
    //void setListHistory();

signals:

public slots:

private:
    QList<double> *m_pListHistory;
    QListWidget *m_pListWidget;
    QGridLayout *m_pGridLayout;

};

#endif // HISTORY_H
