#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>

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

void Widget::on_pushButton_clicked()
{
    system("killall ldeinit");
}

void Widget::on_pushButton_4_clicked()
{
    qApp->quit();
}

void Widget::on_pushButton_2_clicked()
{
    system("reboot");
}

void Widget::on_pushButton_3_clicked()
{
    system("init 0");
}
