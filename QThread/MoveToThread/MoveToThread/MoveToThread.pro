QT += core
QT -= gui

CONFIG += c++11

TARGET = MoveToThread
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DESTDIR = $$PWD/../bin/$$TARGET

SOURCES += main.cpp \
    atimertest.cpp

HEADERS += \
    atimertest.h
