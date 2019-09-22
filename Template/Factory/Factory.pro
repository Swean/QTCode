QT += core
QT -= gui

CONFIG += c++11

TARGET = Factory
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    awheelbmw.cpp \
    awheel.cpp \
    acar.cpp \
    afactory.cpp \
    acarbig.cpp \
    acarsmall.cpp

HEADERS += \
    awheel.h \
    awheelbmw.h \
    acar.h \
    afactory.h \
    acarbig.h \
    acarsmall.h
