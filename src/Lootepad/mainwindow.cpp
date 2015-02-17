#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QHBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textedittab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isSaved = false;
    curFile = tr("untitled.txt");
    formTitle = curFile + tr(" - Lootepad 0.9");
    setWindowTitle(formTitle);
    textEditTab = new TextEditTab(this);
    ui->gridLayout->addWidget(textEditTab);

    connect(this, SIGNAL(updateText(QString)), this, SLOT(on_second_statusLabel_updateText(QString)));
    init_statusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_New_triggered()
{
    textEditTab->currentTEditor->do_file_New();
}

void MainWindow::on_action_Save_triggered()
{
    textEditTab->currentTEditor->do_file_Save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    textEditTab->currentTEditor->do_file_SaveAs();
}

void MainWindow::on_action_Help_triggered()
{
    QMessageBox::information(this,tr("版本说明"),tr("lootepad 0.9.0"));
}



void MainWindow::on_action_Open_triggered()
{
    textEditTab->currentTEditor->do_file_Open();
}

void MainWindow::on_action_Close_triggered()
{
    textEditTab->currentTEditor->do_file_SaveOrNot();
    textEditTab->currentTEditor->setVisible(false);
    first_statusLabel->setText(tr("文本编辑器已关闭"));
    second_statusLabel->setText(tr("Lootepad 0.9.0"));
}

void MainWindow::on_action_Quit_triggered()
{
    on_action_Close_triggered();
    qApp->quit();
}

void MainWindow::on_action_Undo_triggered()
{
    textEditTab->currentTEditor->undo();
}

void MainWindow::on_action_Cut_triggered()
{
    textEditTab->currentTEditor->cut();
}

void MainWindow::on_action_Copy_triggered()
{
    textEditTab->currentTEditor->copy();
}

void MainWindow::on_action_Past_triggered()
{
    textEditTab->currentTEditor->paste();
}

void MainWindow::on_action_Find_triggered()
{
    QDialog *findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    find_textLineEdit = new QLineEdit(findDlg);
    QPushButton *find_Btn = new QPushButton(tr("查找下一个"),findDlg);
    QVBoxLayout* layout = new QVBoxLayout(findDlg);
    layout->addWidget(find_textLineEdit);
    layout->addWidget(find_Btn);
    findDlg->show();
    connect(find_Btn,SIGNAL(clicked()),this,SLOT(show_findText()));
    second_statusLabel->setText(tr("正在进行查找"));
}

void MainWindow::show_findText()
{
    QString findText = find_textLineEdit->text();
    if(!textEditTab->currentTEditor->find(findText,QTextDocument::FindBackward))
    {
        QMessageBox::warning(this,tr("查找"),tr("找不到 %1").arg(findText));
    }
}

void MainWindow::init_statusBar()
{
    QStatusBar* bar = ui->statusBar;
    first_statusLabel = new QLabel;
    first_statusLabel->setMinimumSize(150,20);
    first_statusLabel->setFrameShape(QFrame::WinPanel);
    first_statusLabel->setFrameShadow(QFrame::Sunken);
    second_statusLabel = new QLabel;
    second_statusLabel->setMinimumSize(150,20);
    second_statusLabel->setFrameShape(QFrame::WinPanel);
    second_statusLabel->setFrameShadow(QFrame::Sunken);
    bar->addWidget(first_statusLabel);
    bar->addWidget(second_statusLabel);
    first_statusLabel->setText(tr("欢迎使用文本编辑器"));
    second_statusLabel->setText(tr("Lootepad 0.9.0"));
}

void MainWindow::do_cursorChanged()
{
    int rowNum = textEditTab->currentTEditor->document()->blockCount();
    const QTextCursor cursor = textEditTab->currentTEditor->textCursor();
    int colNum = cursor.columnNumber();
    first_statusLabel->setText(tr("%1 行 %2 列").arg(rowNum).arg(colNum));
}

void MainWindow::on_action_triggered()
{
    textEditTab->currentTEditor->redo();
}

void MainWindow::on_action_LDE_triggered()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("/usr/bin/ldeabout",NULL);
}

void MainWindow::on_actionNewTab_triggered()
{
    emit textEditTab->addEditTab();
}

void MainWindow::on_second_statusLabel_updateText(QString text)
{
    second_statusLabel->setText(text);
}
