#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isSaved = false;
    curFile = tr("未命名.txt");
    formTitle = curFile + tr(" - Lootepad 0.5");
    setWindowTitle(formTitle);
    init_statusBar();
    connect(ui->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(do_cursorChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_file_New()
{
    do_file_SaveOrNot();
    isSaved = false;
    curFile = tr("未命名.txt");
    formTitle = curFile + tr(" - Lootepad 0.5");
    setWindowTitle(formTitle);
    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
}

void MainWindow::do_file_SaveOrNot()
{
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr("尚未保存，是否保存？"));
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if(box.exec() == QMessageBox::Yes)
            do_file_Save();
    }
}

void MainWindow::do_file_Save()
{
    if(isSaved){
        saveFile(curFile);
    }
    else{
        do_file_SaveAs();
    }
}

void MainWindow::do_file_SaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(!fileName.isEmpty())
    {
        saveFile(fileName);
    }
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件 %1:\n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();
    isSaved = true;
    curFile = QFileInfo(fileName).canonicalFilePath();
    formTitle = curFile + tr(" - Lootepad 0.5");
    setWindowTitle(formTitle);
    second_statusLabel->setText(tr("保存文件成功"));
    return true;
}

void MainWindow::on_action_New_triggered()
{
    do_file_New();
}

void MainWindow::on_action_Save_triggered()
{
    do_file_Save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    do_file_SaveAs();
}

void MainWindow::on_action_Help_triggered()
{
    QMessageBox::information(this,tr("版本说明"),tr("lootepad 0.5.8"));
}

void MainWindow::do_file_Open()
{
    do_file_SaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        do_file_Load(fileName);
    }
    ui->textEdit->setVisible(true);
}

bool MainWindow::do_file_Load(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("读取文件"),tr("无法读取文件 %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    curFile = QFileInfo(fileName).canonicalFilePath();
    formTitle = curFile + tr(" - Lootepad 0.5");
    setWindowTitle(formTitle);
    second_statusLabel->setText(tr("打开文件成功"));
    return true;
}

void MainWindow::on_action_Open_triggered()
{
    do_file_Open();
}

void MainWindow::on_action_Close_triggered()
{
    do_file_SaveOrNot();
    ui->textEdit->setVisible(false);
    first_statusLabel->setText(tr("文本编辑器已关闭"));
    second_statusLabel->setText(tr("Lootepad 0.5.8"));
}

void MainWindow::on_action_Quit_triggered()
{
    on_action_Close_triggered();
    qApp->quit();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_Past_triggered()
{
    ui->textEdit->paste();
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
    if(!ui->textEdit->find(findText,QTextDocument::FindBackward))
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
    second_statusLabel->setText(tr("Lootepad 0.5.8"));
}

void MainWindow::do_cursorChanged()
{
    int rowNum = ui->textEdit->document()->blockCount();
    const QTextCursor cursor =ui->textEdit->textCursor();
    int colNum = cursor.columnNumber();
    first_statusLabel->setText(tr("%1 行 %2 列").arg(rowNum).arg(colNum));
}

void MainWindow::on_action_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_action_LDE_triggered()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("/usr/bin/ldeabout",NULL);
}
