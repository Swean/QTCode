QT += core
QT -= gui

CONFIG += c++11

TARGET = basic
CONFIG += console
CONFIG -= app_bundle

DESTDIR = $$PWD/../../bin/Class

TEMPLATE = app

SOURCES += main.cpp \
    sizeofclass.cpp

HEADERS += \
    sizeofclass.h
