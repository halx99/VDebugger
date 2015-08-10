#ifndef VDBG_THREAD
#define VDBG_THREAD

#include <QThread>
#include "vdbg.h"



class DebugThread : public QThread
{
     Q_OBJECT
public:
      DebugThread(LPCWSTR path, VDbg ** dbg);
      void setGeneralOutput(string output);
      void NotifyInitDone();
      ~DebugThread();
signals:
    void sendString(QString);
    void Init_done();
protected:
      void run();
private:

      LPCWSTR path;
      VDbg ** tdbg;

};
#endif
