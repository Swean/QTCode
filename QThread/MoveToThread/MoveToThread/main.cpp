#include <QCoreApplication>
#include <QThread>
#include "atimertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ATimerTest tt;
    QThread thd;
    tt.moveToThread(&thd);
    thd.start();
    emit tt.sig_timer();

    return a.exec();
}
