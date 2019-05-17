#-------------------------------------------------
#
# Project created by QtCreator 2017-08-21T09:07:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadUseThread

win32{
	DESTDIR = $$PWD/../Output/bin
}

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    athread.cpp \
    bthread.cpp

HEADERS  += mainwindow.h \
    athread.h \
    bthread.h

FORMS    += mainwindow.ui
