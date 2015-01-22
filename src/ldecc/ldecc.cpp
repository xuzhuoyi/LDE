#include "ldecc.h"
#include "ui_ldecc.h"

ldecc::ldecc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ldecc)
{
    ui->setupUi(this);

    connect(&g,SIGNAL(back()),this,SLOT(show()));
    connect(&l,SIGNAL(back()),this,SLOT(show()));
    connect(&s,SIGNAL(back()),this,SLOT(show()));
}

ldecc::~ldecc()
{
    delete ui;
}

void ldecc::on_pushButton_clicked()
{
    qApp->quit();
}

void ldecc::on_toolButton_clicked()
{
    g.show();
    this->hide();

}

void ldecc::on_toolButton_2_clicked()
{
    l.show();
    this->hide();
}

void ldecc::on_toolButton_10_clicked()
{
    qApp->aboutQt();
}

void ldecc::on_toolButton_9_clicked()
{

}

void ldecc::on_toolButton_3_clicked()
{
    s.show();
    this->hide();
}
