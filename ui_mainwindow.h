/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOpenText;
    QAction *actionQuit;
    QAction *actionRun_Continue;
    QAction *actionStep_Over;
    QAction *actionStep_In;
    QAction *actionStep_Out;
    QAction *actionBreak_Point;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_17;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuDebug;
    QMenu *menuWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(905, 573);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpenText = new QAction(MainWindow);
        actionOpenText->setObjectName(QStringLiteral("actionOpenText"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionRun_Continue = new QAction(MainWindow);
        actionRun_Continue->setObjectName(QStringLiteral("actionRun_Continue"));
        actionStep_Over = new QAction(MainWindow);
        actionStep_Over->setObjectName(QStringLiteral("actionStep_Over"));
        actionStep_In = new QAction(MainWindow);
        actionStep_In->setObjectName(QStringLiteral("actionStep_In"));
        actionStep_Out = new QAction(MainWindow);
        actionStep_Out->setObjectName(QStringLiteral("actionStep_Out"));
        actionBreak_Point = new QAction(MainWindow);
        actionBreak_Point->setObjectName(QStringLiteral("actionBreak_Point"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 881, 331));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 881, 311));
        tabWidget->addTab(tab, QString());
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(20, 350, 881, 191));
        tab_17 = new QWidget();
        tab_17->setObjectName(QStringLiteral("tab_17"));
        textEdit = new QTextEdit(tab_17);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 871, 171));
        tabWidget_2->addTab(tab_17, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        listWidget = new QListWidget(tab_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 881, 171));
        tabWidget_2->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 905, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionOpenText);
        menu->addAction(actionQuit);
        menuDebug->addAction(actionRun_Continue);
        menuDebug->addAction(actionStep_Over);
        menuDebug->addAction(actionStep_In);
        menuDebug->addAction(actionStep_Out);
        menuDebug->addAction(actionBreak_Point);
        menuWindow->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VDebugger", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open(binary)", 0));
        actionOpenText->setText(QApplication::translate("MainWindow", "Open(text)", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionRun_Continue->setText(QApplication::translate("MainWindow", "Run/Continue", 0));
        actionStep_Over->setText(QApplication::translate("MainWindow", "Step Over", 0));
        actionStep_In->setText(QApplication::translate("MainWindow", "Step In", 0));
        actionStep_Out->setText(QApplication::translate("MainWindow", "Step Out", 0));
        actionBreak_Point->setText(QApplication::translate("MainWindow", "Break Point", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "untitled", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_17), QApplication::translate("MainWindow", "General Output", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Relevant Source Files", 0));
        menu->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuDebug->setTitle(QApplication::translate("MainWindow", "Debug", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
