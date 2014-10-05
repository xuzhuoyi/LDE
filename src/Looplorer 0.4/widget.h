#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>
#include <QtGui/QMainWindow>
#include <QtNetwork/QtNetwork>
#include <QMenu>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

// #include "locationbar.h"

namespace Ui {
class Widget;
}

class LocationBar;
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Widget* newWindow();
    void load();
    void addMenu();

    void goBack();
    void webReload();

    QString getWebkitAddress();


    
private:
    Ui::Widget *ui;
    LocationBar *bar;

    void pressReturn();
    void refreshUrl();
    void clickLink();
    void readData();		//读取数据
    void saveData();
    void createMenuBar();
    void createActions();
    QMenu *pFavorite;
    QMap<QString, QString> FavoritePage;	//收藏夹中的网址和网页标题
    QList<QAction*> pFavoriteAction;
    QAction *pCollectAction;
    QMenu *menuBar;

private slots:
    void loadUrl();
    void loadLink(const QUrl &url);
    void addFavorites();	//收藏当前页面
    void openFavorite();
    void on_pushButton_clicked();
};

#endif // WIDGET_H
