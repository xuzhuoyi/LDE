#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork/QFtp>
#include <QtGui>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    QFtp *ftp;
    QHash<QString,bool> isDirectory;
    QString currentPath;
    QFile *file;

private slots:
    void ftpCommandStarted(int);
    void ftpCommandFinished(int,bool);
    void on_downloadButton_clicked();
    void on_cdToParentButton_clicked();
    void on_connectButton_clicked();
    void updateDataTransferProgress(qint64,qint64);
    void addToList(const QUrlInfo &urlInfo);
    void processItem(QTreeWidgetItem*,int);

};

#endif // WIDGET_H
