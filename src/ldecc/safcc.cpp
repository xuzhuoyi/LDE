#include "safcc.h"
#include "ui_safcc.h"

Safcc::Safcc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Safcc)
{
    ui->setupUi(this);
}

Safcc::~Safcc()
{
    delete ui;
}

void Safcc::on_pushButton_3_clicked()
{
    qApp->quit();
}

void Safcc::on_pushButton_4_clicked()
{
    emit back();
    this->close();
}
