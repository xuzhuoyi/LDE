#-------------------------------------------------
#
# Project created by QtCreator 2014-08-25T09:37:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR += ../../usr/bin

TARGET = loogout
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

# install
target.path = /usr/bin
INSTALLS += target

