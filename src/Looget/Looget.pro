#-------------------------------------------------
#
# Project created by QtCreator 2014-08-12T23:25:51
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR += ../../usr/bin

TARGET = looget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

# install
target.path = /usr/bin
INSTALLS += target
