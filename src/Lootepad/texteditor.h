#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QTextEdit>
#include "mainwindow.h"

class TextEditor : public QTextEdit
{
    Q_OBJECT

public:
    explicit TextEditor(MainWindow *parent = 0);
    ~TextEditor();
    void do_file_New();
    void do_file_SaveOrNot();
    void do_file_Save();
    void do_file_SaveAs();
    void do_file_Open();
private:
    MainWindow *pMainWindow;

    bool saveFile(const QString &fileName);
    bool isSaved;

    bool do_file_Load(const QString &fileName);
    QString curFile;
    QString formTitle;
};

#endif // TEXTEDITOR_H
