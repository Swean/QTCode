#ifndef ATHREAD_H
#define ATHREAD_H

#include <QThread>
#include "bthread.h"


class AThread : public QThread
{
public:
    AThread(QObject *parent = 0);
    virtual ~AThread();
    bool stop();

protected:
    virtual void run();
private:
    bool doSomething();
    bool m_isRunning;
    bool m_stop;
    BThread *m_bthd = NULL;

};

#endif // ATHREAD_H
