#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_New_triggered();

    void on_action_Save_triggered();

    void on_action_SaveAs_triggered();

    void on_action_Help_triggered();

    void on_action_Open_triggered();

    void on_action_Close_triggered();

    void on_action_Quit_triggered();

    void on_action_Undo_triggered();

    void on_action_Cut_triggered();

    void on_action_Copy_triggered();

    void on_action_Past_triggered();

    void show_findText();

    void on_action_Find_triggered();

    void do_cursorChanged();

    void on_action_triggered();

    void on_action_LDE_triggered();

private:
    Ui::MainWindow *ui;
    bool isSaved;
    QString curFile;
    QString formTitle;
    void do_file_New();
    void do_file_SaveOrNot();
    void do_file_Save();
    void do_file_SaveAs();
    bool saveFile(const QString& fileName);
    void do_file_Open();
    bool do_file_Load(const QString& fileName);
    QLineEdit *find_textLineEdit;
    QLabel* first_statusLabel;
    QLabel* second_statusLabel;
    void init_statusBar();
};

#endif // MAINWINDOW_H
