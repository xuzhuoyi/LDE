#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork/QtNetwork>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void startRequest(QUrl url);

protected:
//    void changeEvent (QEvent *e);
    
private slots:
    void on_pushButton_clicked();
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);

private:
    Ui::Widget *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QUrl url;
    QFile *file;
};

#endif // WIDGET_H
