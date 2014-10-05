#include "locationbar.h"
#include "ui_locationbar.h"


LocationBar::LocationBar(Widget *parent) :
    QWidget(parent),
    ui(new Ui::LocationBar)
{
    ui->setupUi(this);
    parentWindow = parent;

    connect(ui->lineEditAddr,SIGNAL(returnPressed()),parentWindow,SLOT(loadUrl()));

}

LocationBar::~LocationBar()
{
    delete ui;
}

void LocationBar::on_pushButBack_clicked()
{
    parentWindow->goBack();
}

void LocationBar::on_pushButGoto_clicked()
{

    parentWindow->load();
}



QString LocationBar::getLineEditText()
{
    return ui->lineEditAddr->text();
}

void LocationBar::on_pushButton_clicked()
{
    parentWindow->webReload();
}

void LocationBar::on_pushButton_2_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("/usr/bin/ldeabout",NULL);
}

void LocationBar::refreshlineEditAddr()
{
    ui->lineEditAddr->setText(parentWindow->getWebkitAddress());
}
