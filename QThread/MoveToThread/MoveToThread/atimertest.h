#ifndef ATIMERTEST_H
#define ATIMERTEST_H

#include <QObject>
#include <QTimer>
#include <QTime>

class ATimerTest : public QObject
{
    Q_OBJECT
public:
    ATimerTest();
private:
    //QTimer m_timer; // qtimer不能在其他线程关闭或开启 QObject::killTimer: Timers cannot be stopped from another thread
    QTimer *m_pT;
    QTime  m_tm;

signals:
    void sig_timer();
private slots:
    void slt_timeout();
    void slt_start();
};

#endif // ATIMERTEST_H
