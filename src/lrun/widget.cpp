#include "widget.h"
#include "ui_widget.h"
#include <QProcess>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    qApp->quit();
}

void Widget::on_pushButton_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start(ui->lineEdit->text(),NULL);
    qApp->quit();
}
