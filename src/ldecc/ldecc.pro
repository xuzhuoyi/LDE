#-------------------------------------------------
#
# Project created by QtCreator 2014-10-03T16:55:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR += ../../usr/bin

TARGET = ldecc
TEMPLATE = app


SOURCES += main.cpp\
        ldecc.cpp \
    gencc.cpp \
    lancc.cpp \
    safcc.cpp

HEADERS  += ldecc.h \
    gencc.h \
    lancc.h \
    safcc.h

FORMS    += ldecc.ui \
    gencc.ui \
    lancc.ui \
    safcc.ui

RESOURCES += \
    ldeccrc.qrc
