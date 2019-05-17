#include "bthread.h"
#include <QDebug>

BThread::BThread(QObject *parent):QThread(parent)
{
    m_stop = false;
    m_isRunning = false;
}

BThread::~BThread()
{
    qDebug() << "delete BThread";
}

void BThread::run()
{
    qDebug() << "begin run";
    while(!m_stop)
    {
        //sleep(5);
        for(int i = 0; i < 3000/10; i++)
        {
            if(m_stop)
                return;
            msleep(10);
        }
        m_isRunning = true;
        doSomething();
        m_isRunning = false;
    }
    qDebug() << "end run";
}

bool BThread::doSomething()
{
    qDebug() << "BThread::doSomething";
    return true;
}

bool BThread::stop()
{
    m_stop = true;
    //if(m_isRunning)
        wait();
    return true;
}
