#-------------------------------------------------
#
# Project created by QtCreator 2014-10-03T16:55:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ldecc
TEMPLATE = app


SOURCES += main.cpp\
        ldecc.cpp \
    gencc.cpp \
    lancc.cpp

HEADERS  += ldecc.h \
    gencc.h \
    lancc.h

FORMS    += ldecc.ui \
    gencc.ui \
    lancc.ui

RESOURCES += \
    ldeccrc.qrc
