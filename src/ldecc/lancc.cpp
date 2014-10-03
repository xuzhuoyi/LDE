#include "lancc.h"
#include "ui_lancc.h"

Lancc::Lancc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lancc)
{
    ui->setupUi(this);
}

Lancc::~Lancc()
{
    delete ui;
}

void Lancc::on_pushButton_clicked()
{
    qApp->quit();
}

void Lancc::on_pushButton_2_clicked()
{
    emit back();
    this->close();
}
