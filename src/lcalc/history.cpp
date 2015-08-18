#include "history.h"

#include <QListWidget>
#include <QGridLayout>

History::History(QWidget *parent) : QWidget(parent)
{
    m_pListWidget = new QListWidget;
    m_pGridLayout = new QGridLayout;
    m_pGridLayout->addWidget(m_pListWidget);
    m_pListHistory = new QList<double>;
    setLayout(m_pGridLayout);
}

QList<double> *History::listHistory()
{
    return m_pListHistory;
}

void History::refreshList()
{
    double d;
    m_pListWidget->clear();
    foreach(d, *m_pListHistory)
    {
        m_pListWidget->addItem(QString::number(d));
    }

}

