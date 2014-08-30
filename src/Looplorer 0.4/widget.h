#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>
#include <QtGui/QMainWindow>
#include <QtNetwork/QtNetwork>
#include <QMenu>

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
    void pressReturn();
    void refreshUrl();
    void clickLink();
    void readData();		//读取数据
    void saveData();
    void createMenuBar();
    void createActions();
    QMenu *pFavorite;		//收藏夹菜单栏
    QMap<QString, QString> FavoritePage;	//收藏夹中的网址和网页标题
    QList<QAction*> pFavoriteAction;
    QAction *pCollectAction;
    QMenu *menuBar;

private slots:
    void on_pushButGoto_clicked();
    void loadUrl();
    void refreshlineEditAddr();
    void on_pushButton_clicked();
    void loadLink(const QUrl &url);
    void addFavorites();	//收藏当前页面
    void openFavorite();
    void on_pushButBack_clicked();
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H
