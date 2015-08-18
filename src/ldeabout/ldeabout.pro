#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T20:06:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR += ../../usr/bin

TARGET = ldeabout
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    laboutwidget.cpp

HEADERS  += widget.h \
    laboutwidget.h

FORMS    += widget.ui

# install
target.path = /usr/bin
INSTALLS += target
