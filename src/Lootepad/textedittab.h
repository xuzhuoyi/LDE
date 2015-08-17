#ifndef TEXTEDITTAB_H
#define TEXTEDITTAB_H

#include <QTabWidget>
#include <QTextEdit>
#include <QList>
#include "texteditor.h"

class MainWindow;

class TextEditTab : public QTabWidget
{
    Q_OBJECT

public:
    explicit TextEditTab(MainWindow *parent = 0);
    ~TextEditTab();
    TextEditor *currentTEditor;
    QList<TextEditor*> *textEditorList;

signals:
    void addEditTab(MainWindow *parent = 0);

private slots:
    void on_TextEditTab_addEditTab(MainWindow *parent = 0);
    void onCurrentChanged(int index);


};

#endif // TEXTEDITTAB_H
