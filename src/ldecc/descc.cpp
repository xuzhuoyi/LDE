#include "descc.h"
#include "ui_descc.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QProcess>

Descc::Descc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Descc)
{
    ui->setupUi(this);
}

Descc::~Descc()
{
    delete ui;
}

void Descc::on_pushButton_clicked()
{
    qApp->quit();
}

void Descc::on_pushButton_2_clicked()
{
    emit back();
    this->close();
}

void Descc::on_pushButton_3_clicked()
{

    fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/",
                                                      tr("Image Files (*.png *.jpg *.bmp)"));
    //qDebug() << QDir::homePath() + "/.LDE/lderc.ini";
    ui->lineEdit->setText(fileName);
    ui->label_4->setPixmap(QPixmap(fileName));
    ui->pushButton_4->setEnabled(true);

}

void Descc::on_pushButton_4_clicked()
{
    QString fileRc = QDir::homePath() + "/.LDE/lderc.ini";
    QSettings set(fileRc, QSettings::IniFormat);
    set.setValue("wallPapers/source", fileName);
    set.sync();

    QProcess *wallpaperCon = new QProcess;
    QStringList runArgsList;
    QString wpSource = set.value("wallPapers/source").toString();

    runArgsList << "--bg-scale" << wpSource;
    wallpaperCon->start("feh", runArgsList);

    ui->pushButton_4->setEnabled(false);
}
