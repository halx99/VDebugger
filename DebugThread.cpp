#include "DebugThread.h"
#include <iostream>
#include <QDebug>
DebugThread::DebugThread(LPCWSTR path, VDbg ** dbg) : QThread()
{
    tdbg = dbg;
    int len = wcslen(path);
    this->path = new wchar_t(len * 2 + 2);
    memset((LPVOID)this->path, 0, len * 2 + 2);
    memcpy((LPVOID)this->path, (LPVOID)path, len*2);
}

void DebugThread::run()
{
    // define a VDbg object and start debugging
    (*tdbg)->StartDebugging(path);
    emit sendString("Debugging finished");
}
void DebugThread::setGeneralOutput(string output)
{
    emit sendString(QString::fromStdString(output));
    //qDebug(output.c_str());
}
void DebugThread::NotifyInitDone()
{
    emit Init_done();
}
DebugThread::~DebugThread()
{

}
