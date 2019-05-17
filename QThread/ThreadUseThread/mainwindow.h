#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "athread.h"
#include "bthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::MainWindow *ui;

private:
    AThread *m_athd = NULL;
};

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
#endif // MAINWINDOW_H
