#include "textedittab.h"
#include <QTextEdit>
#include "mainwindow.h"
#include "texteditor.h"



TextEditTab::TextEditTab(MainWindow *parent):
    QTabWidget(parent)
{
    auto par = parent;
    connect(this, SIGNAL(addEditTab(MainWindow*)), this, SLOT(on_TextEditTab_addEditTab(MainWindow*)));

    textEditorList = new QList<TextEditor*>;
    TextEditor *textLine = new TextEditor(par);
    this->addTab(textLine, "untitled");
    currentTEditor = textLine;
    textEditorList->append(textLine);
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(onCurrentChanged(int)));
}

TextEditTab::~TextEditTab()
{

}

void TextEditTab::on_TextEditTab_addEditTab(MainWindow *parent)
{
    TextEditor *tEdit = new TextEditor(parent);
    this->addTab(tEdit, "untitled");
    textEditorList->append(tEdit);
}

void TextEditTab::onCurrentChanged(int index)
{
    currentTEditor = textEditorList->at(index);
}


