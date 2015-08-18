#ifndef LABOUTWIDGET_H
#define LABOUTWIDGET_H

#include <QWidget>

class QVBoxLayout;
class QLabel;
class QPushButton;
class QTabWidget;

class LAboutWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LAboutWidget(QString name, QString version, QString info = "", QWidget *parent = 0);

signals:

public slots:

private:
    QVBoxLayout *m_pVBoxLayoutMain;
    QVBoxLayout *m_pVBoxLayoutTitle;
    QLabel *m_pLabelName;
    QLabel *m_pLabelVersion;
    QLabel *m_pLabelLDEVersion;
    QTabWidget *m_pTabWidgetContent;
    QLabel *m_pLabelAbout;
    QVBoxLayout *m_pVBoxLayoutAbout;
};

#endif // LABOUTWIDGET_H
