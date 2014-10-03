#include "gencc.h"
#include "ui_gencc.h"

Gencc::Gencc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gencc)
{
    ui->setupUi(this);
}

Gencc::~Gencc()
{
    delete ui;
}

void Gencc::on_pushButton_clicked()
{
    qApp->quit();
}

void Gencc::on_pushButton_2_clicked()
{
    emit back();
    this->close();
}
