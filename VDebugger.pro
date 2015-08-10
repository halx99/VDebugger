#-------------------------------------------------
#
# Project created by QtCreator 2015-08-07T12:47:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VDebugger
TEMPLATE = app

LIBS += Dbghelp.lib

DEFINES  -= ASCII

SOURCES += main.cpp\
        mainwindow.cpp \
    vdbg.cpp \
    DebugThread.cpp

HEADERS  += mainwindow.h \
    vdbg.h \
    DebugThread.h

FORMS    += mainwindow.ui

RC_FILE = mainicon.rc
