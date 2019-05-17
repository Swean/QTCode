#include "athread.h"
#include <QDebug>

AThread::AThread(QObject *parent):QThread(parent)
{
    m_stop = false;
    m_isRunning = false;
//    if(NULL == m_bthd)
//        m_bthd = new BThread(NULL);
//    m_bthd->start();
}

AThread::~AThread()
{
    if(m_bthd != NULL)
    {
        m_bthd->stop();
        delete m_bthd;
        m_bthd = NULL;
    }
    qDebug() << "delete AThread";
}

void AThread::run()
{
    qDebug() << "begin run";
    //while(!m_stop)
    {
        //sleep(5);
        for(int i = 0; i < 5000/10; i++)
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

bool AThread::doSomething()
{
    qDebug() << "AThread::doSomething";
    return true;
}

bool AThread::stop()
{
    m_stop = true;
    //if(m_isRunning)
        wait();
    return true;
}
