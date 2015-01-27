#-------------------------------------------------
#
# Project created by QtCreator 2014-08-21T23:23:49
#
#-------------------------------------------------

QT       += core

QT       -= gui

DESTDIR += ../../usr/bin

TARGET = ldeinit
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    init.cpp

HEADERS += \
    init.h

# install
target.path = /usr/bin
INSTALLS += target
