#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vdbg.h"
#include "DebugThread.h"
#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QTextStream>
#include <QFile>
#include <QTabWidget>
#include <QTextEdit>
#include <QList>
class DebugThread;
extern VDbg * dbg;
extern DebugThread * myThread;
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


    void on_actionOpen_triggered();

    void on_actionRun_Continue_triggered();

    void on_actionBreak_Point_triggered();

    void on_actionStep_Over_triggered();

    void on_actionStep_In_triggered();

    void on_actionStep_Out_triggered();

    void on_actionOpenText_triggered();

    void on_actionTabClose(int tabId);

    void on_actionInitDone();

    void on_actionItemDoubleClicked(QListWidgetItem * item);

private:
    Ui::MainWindow *ui;

    void addFileToTab(QString path);
    bool bUntitled;
};

#endif // MAINWINDOW_H
