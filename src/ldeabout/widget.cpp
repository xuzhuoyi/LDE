#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_6->setWordWrap(true);
    ui->label_9->setWordWrap(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qApp->quit();
}

void Widget::on_pushButton_2_clicked()
{
    qApp->aboutQt();
}
