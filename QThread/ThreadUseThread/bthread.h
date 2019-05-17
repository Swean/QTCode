#ifndef BTHREAD_H
#define BTHREAD_H
#include <QThread>

class BThread : public QThread
{
public:
    BThread(QObject *parent = 0);
    virtual ~BThread();
    bool stop();

protected:
    virtual void run();
private:
    bool doSomething();
    bool m_isRunning;
    bool m_stop;
};

#endif // BTHREAD_H
