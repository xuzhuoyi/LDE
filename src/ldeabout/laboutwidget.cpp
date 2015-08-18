#include "laboutwidget.h"
#include "widget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QDebug>

LAboutWidget::LAboutWidget(QString name, QString version, QString info, QWidget *parent) : QWidget(parent)
{
    m_pVBoxLayoutMain = new QVBoxLayout;
    m_pVBoxLayoutTitle = new QVBoxLayout;
    m_pLabelName = new QLabel(name);
    m_pLabelVersion = new QLabel(tr("版本") + " " + version);
    m_pLabelLDEVersion = new QLabel(tr("LDE 版本") + " " + LDE_VERSION);
    m_pVBoxLayoutTitle->addWidget(m_pLabelName);
    m_pVBoxLayoutTitle->addWidget(m_pLabelVersion);
    m_pVBoxLayoutTitle->addWidget(m_pLabelLDEVersion);
    m_pTabWidgetContent = new QTabWidget;
    m_pLabelAbout = new QLabel(info);
    m_pTabWidgetContent->addTab(m_pLabelAbout, tr("关于"));
    m_pVBoxLayoutMain->addLayout(m_pVBoxLayoutTitle);
    m_pVBoxLayoutMain->addWidget(m_pTabWidgetContent);
    setLayout(m_pVBoxLayoutMain);
}

