#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pressReturn();
    refreshUrl();
    clickLink();
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    readData();	//读取数据
    createActions();		//创建浏览器按钮动作
    createMenuBar();
    ui->pushButBkmrk->setMenu(pFavorite);
}

Widget::~Widget()
{
    saveData();
    delete ui;
}

void Widget::on_pushButGoto_clicked()
{
    loadUrl();
}

void Widget::pressReturn()
{
    connect(ui->lineEditAddr,SIGNAL(returnPressed()),this,SLOT(loadUrl()));

}

void Widget::loadUrl()
{
    QString str = ui->lineEditAddr->text();
    if (str.size() > 3 && str[0] == 'w' && str[1] == 'w' && str[2] == 'w')
        {
            str = "http://" + str;
        }
    ui->webView->load(QUrl(str));

}

void Widget::refreshUrl()
{
    connect(ui->webView,SIGNAL(loadProgress(int)),this,SLOT(refreshlineEditAddr()));
}

void Widget::refreshlineEditAddr()
{
    ui->lineEditAddr->setText(ui->webView->url().toString());
}

void Widget::on_pushButton_clicked()
{
    ui->webView->reload();
}

void Widget::clickLink()
{
    connect(ui->webView,SIGNAL(linkClicked(QUrl)),this,SLOT(loadLink(QUrl)));
}

void Widget::loadLink(const QUrl &url)
{
    ui->webView->load(url);
}

void Widget::on_pushButBack_clicked()
{
    ui->webView->back();
}

void Widget::addFavorites()
{
    int num = FavoritePage.size();
    FavoritePage.insert(ui->webView->title(), ui->lineEditAddr->text());

    /*
     * 添加后，收藏夹内网址个数没有增多时，即需要收藏的网页已经存在
     * 只需要更新网址，不需要增加对应的菜单按钮
     */
    if (num >= FavoritePage.size())
    {
        return;
    }

    QAction* pAction = new QAction(ui->webView->title(), this);
    connect(pAction, SIGNAL(triggered()), this, SLOT(openFavorite()));

    pFavoriteAction.push_back(pAction);
    pFavorite->addAction(pAction);
}

//打开收藏夹中的网页
void Widget::openFavorite()
{
    QAction *action = qobject_cast<QAction *>(sender());	//获取信号发送按钮指针
    QString str = action->text();		//获取该按钮的标题
    QMap<QString, QString>::const_iterator iterator = FavoritePage.find(str);	//获取该网址的迭代器

    //如果迭代器存在，则加载指定网页
    if (iterator != FavoritePage.constEnd())
    {
        ui->webView->load(QUrl(iterator.value()));
        refreshlineEditAddr();
        return;
    }
}

void Widget::readData()
{
    QSettings settings("Record.ini", QSettings::IniFormat);
    QString urlStr;
    QString keyStr;
    QString urlPath;
    QString keyPath;

    //读取收藏夹
    urlPath = "Favorite/Page";
    keyPath = "Favorite/Name";
    int index = 0;
    while (true)
    {
        urlStr = settings.value(urlPath + QString::number(index, 10)).toString();
        keyStr = settings.value(keyPath + QString::number(index, 10)).toString();
        if (urlStr.isEmpty() || keyStr.isEmpty())
        {
            break;
        }
        FavoritePage.insert(keyStr, urlStr);
        index++;
    }
}

//保存历史记录和收藏夹数据
void Widget::saveData()
{
    int i;
    QMap<QString, QString>::const_iterator iterator;
    QSettings settings("Record.ini", QSettings::IniFormat);
    settings.clear();

    //保存收藏夹
    settings.beginGroup("Favorite");
    i = 0;
    for (iterator = FavoritePage.constBegin(); iterator != FavoritePage.constEnd(); iterator++)
    {
        settings.setValue("Page" + QString::number(i, 10), iterator.value());
        settings.setValue("Name" + QString::number(i, 10), iterator.key());
        i++;
    }
    settings.endGroup();
}

void Widget::createMenuBar()
{
    menuBar = new QMenu();
    pFavorite = menuBar->addMenu("&Favorite");	//菜单栏Favorite按钮
    pFavorite->addAction(pCollectAction);
    for (int i = 0; i < pFavoriteAction.length(); i++)
    {
        pFavorite->addAction(pFavoriteAction[i]);
    }
}

void Widget::createActions()
{
    //收藏夹中每个网址对应的按钮动作，处理函数为openFavorite()
    QMap<QString, QString>::const_iterator iterator;
    for (iterator = FavoritePage.constBegin(); iterator != FavoritePage.constEnd(); iterator++)
    {
        QAction* pAction = new QAction(iterator.key(), this);
        connect(pAction, SIGNAL(triggered()), this, SLOT(openFavorite()));
        pFavoriteAction.push_back(pAction);
    }

    //收藏按钮，快捷键为Ctrl+D， 处理函数为addFavorites()
    pCollectAction = new QAction("Add to Favorites",this);
    pCollectAction->setShortcut(tr("Ctrl+D"));
    connect(pCollectAction, SIGNAL(triggered()), this, SLOT(addFavorites()));
}






void Widget::on_pushButton_2_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("/usr/bin/ldeabout",NULL);
}
