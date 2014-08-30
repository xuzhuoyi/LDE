/*
 * Copyright (C) 2014  Zhuoyi Xu <xzy476386434@vip.qq.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */



#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    ui->progressBar->hide();
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    QString fullName;
    
    if (fileName.isEmpty()) fileName = "index.html";
    
    //存储路径为空存储在程序目录
    if (ui->lineEditSaveDir->text() == "") fullName = fileName;
    else fullName = ui->lineEditSaveDir->text() + "/" + fileName;
    file = new QFile(fullName);
    
    
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "file open error";
        delete file;
        file = 0;
        return;
    }
    
    startRequest(url);
    
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}


void Widget::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));
}


void Widget::httpReadyRead()
{
    if (file) file->write(reply->readAll());
}


void Widget::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}


void Widget::httpFinished()
{
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    
    reply = 0;
    delete file;
    file = 0;
}
