#include "textedittab.h"
#include <QTextEdit>
#include "mainwindow.h"
#include "texteditor.h"



TextEditTab::TextEditTab(MainWindow *parent):
    QTabWidget(parent)
{
    auto par = parent;
    connect(this, SIGNAL(addEditTab()), this, SLOT(on_TextEditTab_addEditTab()));
    TextEditor *textLine = new TextEditor(par);
    this->addTab(textLine, "untitled");
    currentTEditor = textLine;
}

TextEditTab::~TextEditTab()
{

}

void TextEditTab::on_TextEditTab_addEditTab()
{
    QTextEdit *tEdit = new QTextEdit;
    this->addTab(tEdit, "untitle");
}


