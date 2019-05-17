#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMutex>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("DEBUG:");
        break;

    case QtInfoMsg:
        text = QString("INFO:");

    case QtWarningMsg:
        text = QString("WARN:");
        break;

    case QtCriticalMsg:
        text = QString("CRITICAL:");
        break;

    case QtFatalMsg:
        text = QString("FATAL:");
        break;
    default:
        text = QString("DEF");
    }

    QString context_info = QString("[%1][%2]").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyyMMdd hh:mm:ss.zzz");
    QString current_date = QString("[%1]").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(current_date).arg(text).arg(context_info).arg(msg);


    QString sAppPath = QCoreApplication::applicationDirPath();
    QFile file(sAppPath + "\\thread.log");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    if(m_athd == NULL)
     m_athd = new AThread(NULL);
    m_athd->start();
    qDebug() << "btn start";
    QThread::sleep(3);
    if(m_athd->isFinished())
    {
        m_athd->start();
        qDebug() << "btn start2";
    }
    QThread::sleep(3);
    if(m_athd->isFinished())
    {
        m_athd->start();
        qDebug() << "btn start3";
    }

}



void MainWindow::on_btnStop_clicked()
{
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    if(m_athd != NULL)
    {
        m_athd->stop();
        delete m_athd;
        m_athd = NULL;
    }
    qDebug() << "btn stop";
}
