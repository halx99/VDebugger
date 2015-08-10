#include "mainwindow.h"
#include "ui_mainwindow.h"


VDbg * dbg = NULL;
DebugThread * myThread = NULL;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(on_actionTabClose(int)));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(on_actionItemDoubleClicked(QListWidgetItem*)));
    bUntitled = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFileToTab(QString path)
{
    QString filename = path.mid(path.lastIndexOf("\\") + 1);
    int pos = -1;
    for(int i = 0; i < ui->tabWidget->count(); i++)
    {
        if(filename == ui->tabWidget->tabText(i))
            pos = i;
    }
    if(pos != -1)
    {
        ui->tabWidget->setCurrentIndex(pos);
        return;
    }
    QFile f(path);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream txtInput(&f);
    QString lineStr;

    QTextEdit * tedit = new QTextEdit();


    if(ui->tabWidget->count() == 1 && bUntitled)
    {
        delete tedit;
        tedit = ui->textEdit_2;
        bUntitled = false;
        ui->tabWidget->setTabText(0, filename);
    }
    else
    {
        ui->tabWidget->addTab(tedit, filename);
    }
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        tedit->append(lineStr);
    }
    f.close();
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::on_actionOpen_triggered()
{
    // allocate an object of type VDbg, enter blocking state, and wait for user command
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open Executable"), "", tr("Executable Files (*.exe);"));
    if(fileName == "") return;
    LPCWSTR lpwFileName = (LPCWSTR)fileName.utf16();


    myThread = new DebugThread(lpwFileName, &dbg);
    dbg = new VDbg(myThread);
    connect(myThread, SIGNAL(sendString(QString)), ui->textEdit, SLOT(append(QString)));
    connect(myThread, SIGNAL(Init_done()), this, SLOT(on_actionInitDone()));
    myThread->start();
    ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_actionRun_Continue_triggered()
{
    if(dbg)
        dbg->dbgSetEvent();
    else
        ui->textEdit->append("what are you trying to run here ?");
}

void MainWindow::on_actionBreak_Point_triggered()
{
    if(dbg)
    {
        // get the breakpoint command, if the file is not opened yet, create a tab and open it
        QString bp_command = QInputDialog::getText(this, "Break Point", "Enter filename and line number, seperated by a colon. ", QLineEdit::Normal, tr("leetcode.cpp:56"));
        string  s_bp_command = bp_command.toStdString();

        vector<string> vec;
        dbg->str_split(dbg->strTrim(s_bp_command), ":", vec);

        if(vec.size() != 2)
        {
            ui->textEdit->append("invalid command \n");
            return;
        }

        string full_path = dbg->getFullPath(vec[0]);

        if(full_path != "")
            dbg->SetBreakPointBySourceLine((char*)full_path.c_str(), atoi(vec[1].c_str()), false);
        else
            ui->textEdit->append("invalid filename \n");
    }
    else
    {
        ui->textEdit->append("please please open the executable you like to debug first");
    }
}

void MainWindow::on_actionStep_Over_triggered()
{
    if(dbg && dbg->isRunning())
    {
        dbg->setDebugMode(STEP_OVER);
        dbg->dbgSetEvent();
    }
    else
    {
        ui->textEdit->append("there is nothing to step over, you haven't run your program yet");
    }
}

void MainWindow::on_actionStep_In_triggered()
{
    if(dbg && dbg->isRunning())
    {
        dbg->setDebugMode(STEP_IN);
        dbg->dbgSetEvent();
    }
    else
    {
        ui->textEdit->append("there is nothing to step in, you haven't run your program yet");
    }
}

void MainWindow::on_actionStep_Out_triggered()
{
    if(dbg && dbg->isRunning())
        dbg->stepOut();
    else
        ui->textEdit->append("there is nothing to step out of, you haven't run your program yet");
}

void MainWindow::on_actionOpenText_triggered()
{
    QString path;
    path = QFileDialog::getOpenFileName(this, "Open Text", "", "Code (*.cpp *.c);;Header files (*.hpp *.h);;Text files (*.txt)");
    addFileToTab(path);
}
void MainWindow::on_actionTabClose(int tabId)
{
    if(ui->tabWidget->count() > 1)
        ui->tabWidget->removeTab(tabId);
}
void MainWindow::on_actionInitDone()
{
    QString fileName;
    for(unsigned int i = 0; i < dbg->enum_files.size(); i++)
    {
        QString sAddToList = QString::fromStdString(dbg->enum_files[i]);
        ui->listWidget->addItem(sAddToList);
    }
}

void MainWindow::on_actionItemDoubleClicked(QListWidgetItem * item)
{
    QString itemStr = item->text();
    addFileToTab(itemStr);
}
