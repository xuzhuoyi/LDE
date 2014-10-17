#include "widget.h"
#include "ui_widget.h"
#include "locationbar.h"
#include <QTextEdit>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    bar = new LocationBar(this);
    QHBoxLayout *downLayout = new QHBoxLayout;
    downLayout->addWidget(ui->pushButBkmrk);
    downLayout->addWidget(ui->pushButton);
    downLayout->addStretch();
    downLayout->addWidget(ui->buttonAbout);
    downLayout->addWidget(ui->buttonDevTools);

    //QWebView *webView = new QWebView;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(bar);
    layout->addWidget(ui->webView);
    layout->addLayout(downLayout);


    this->setLayout(layout);




    refreshUrl();
    clickLink();
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    readData();	//读取数据
    createActions();		//创建浏览器按钮动作
    createMenuBar();
    ui->pushButBkmrk->setMenu(pFavorite);



    QSettings a ("a.ini",QSettings::IniFormat);
    a.beginGroup("a");
    //a.setValue("a","a");
    //a.setValue("b","b");
    a.endGroup();

    connect(ui->buttonDevTools,SIGNAL(clicked()),this,SLOT(viewSource()));

}

Widget::~Widget()
{
    saveData();
    delete ui;
}




void Widget::loadUrl()
{
    QString str = bar->getLineEditText();
    if (str.size() > 3 && str[0] == 'w' && str[1] == 'w' && str[2] == 'w')
        {
            str = "http://" + str;
        }
    ui->webView->load(QUrl(str));

}

void Widget::refreshUrl()
{
    connect(ui->webView,SIGNAL(loadProgress(int)),bar,SLOT(refreshlineEditAddr()));
}





void Widget::clickLink()
{
    connect(ui->webView,SIGNAL(linkClicked(QUrl)),this,SLOT(loadLink(QUrl)));
}

void Widget::loadLink(const QUrl &url)
{
    ui->webView->load(url);
}



void Widget::addFavorites()
{
    int num = FavoritePage.size();
    FavoritePage.insert(ui->webView->title(), ui->webView->url().toString());

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
    QMapIterator<QString , QString> iter(FavoritePage);
        //输出所有元素
        while(iter.hasNext())
        {
            iter.next();
            qDebug() << iter.key() << " " <<iter.value();
        }  ;
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
        bar->refreshlineEditAddr();
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
    pCollectAction = new QAction("添加到书签",this);
    pCollectAction->setShortcut(tr("Ctrl+D"));
    connect(pCollectAction, SIGNAL(triggered()), this, SLOT(addFavorites()));
}









Widget* Widget::newWindow()
{
    //保存数据
    //if (!m_mainWindows.isEmpty())
        //mainWindow()->m_autoSaver->saveIfNeccessary();
    Widget *browser = new Widget();
    browser->show();
    return browser;
}

void Widget::load()
{
    loadUrl();
}

void Widget::addMenu()
{
    ui->pushButBkmrk->setMenu(pFavorite);
}




void Widget::goBack()
{
    ui->webView->back();
}

void Widget::webReload()
{
    ui->webView->reload();
}

QString Widget::getWebkitAddress()
{
    return ui->webView->url().toString();
}

void Widget::on_pushButton_clicked()
{
    this->newWindow();
}

void Widget::viewSource()
{
    QNetworkAccessManager* accessManager = ui->webView->page()->networkAccessManager();
    QNetworkRequest request(ui->webView->url());
    QNetworkReply* reply = accessManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(slotSourceDownloaded()));
}

void Widget::slotSourceDownloaded()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(const_cast<QObject*>(sender()));
    QTextEdit* textEdit = new QTextEdit(NULL);
    textEdit->setAttribute(Qt::WA_DeleteOnClose);
    textEdit->show();
    textEdit->setPlainText(reply->readAll());
    reply->deleteLater();
}


void Widget::on_buttonAbout_clicked()
{
    QMessageBox::information(NULL, "关于 Looplorer", "Looplorer 0.4.9", QMessageBox::Yes, QMessageBox::Yes);

}
