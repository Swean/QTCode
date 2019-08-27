#include "atimertest.h"
#include <QDebug>

ATimerTest::ATimerTest()
{
    m_tm = QTime::currentTime();
//    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slt_timeout()));
//    m_pT->start(1000);
    connect(this, SIGNAL(sig_timer()), this, SLOT(slt_start()));

}

void ATimerTest::slt_start()
{
    m_pT = new QTimer();    // 放在槽函数里，才会使在子线程里创建，后续的槽函数修改才能正常运行
    connect(m_pT, SIGNAL(timeout()), this, SLOT(slt_timeout()));
    m_pT->start(1000);
}

void ATimerTest::slt_timeout()
{
    qDebug() << QTime::currentTime() ;
    if(m_tm.secsTo(QTime::currentTime()) > 10)
        m_pT->setInterval(500);
    if(m_tm.secsTo(QTime::currentTime()) > 20)
        m_pT->setInterval(100);
    if(m_tm.secsTo(QTime::currentTime()) > 30)
        m_pT->stop();
}
