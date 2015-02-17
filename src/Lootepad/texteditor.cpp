#include "texteditor.h"
#include "mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>

TextEditor::TextEditor(MainWindow *parent)
{
    pMainWindow = parent;
    connect(this,SIGNAL(cursorPositionChanged()),pMainWindow,SLOT(do_cursorChanged()));
}

TextEditor::~TextEditor()
{

}

void TextEditor::do_file_New()
{
    do_file_SaveOrNot();
    isSaved = false;
    curFile = tr("untitled.txt");
    formTitle = curFile + tr(" - Lootepad 0.9");
    pMainWindow->setWindowTitle(formTitle);
    this->clear();
    this->setVisible(true);

}

void TextEditor::do_file_SaveOrNot()
{
    if(this->document()->isModified())
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

void TextEditor::do_file_Save()
{
    if(isSaved){
        saveFile(curFile);
    }
    else{
        do_file_SaveAs();
    }
}

void TextEditor::do_file_SaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(!fileName.isEmpty())
    {
        saveFile(fileName);
    }
}

bool TextEditor::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件 %1:\n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<this->toPlainText();
    isSaved = true;
    curFile = QFileInfo(fileName).canonicalFilePath();
    formTitle = curFile + tr(" - Lootepad 0.9");
    pMainWindow->setWindowTitle(formTitle);
    emit pMainWindow->updateText(tr("保存文件成功"));

    return true;
}

void TextEditor::do_file_Open()
{
    do_file_SaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        do_file_Load(fileName);
    }
    this->setVisible(true);
}

bool TextEditor::do_file_Load(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("读取文件"),tr("无法读取文件 %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    this->setText(in.readAll());
    curFile = QFileInfo(fileName).canonicalFilePath();
    formTitle = curFile + tr(" - Lootepad 0.9");
    pMainWindow->setWindowTitle(formTitle);
    emit pMainWindow->updateText(tr("打开文件成功"));
    return true;
}
