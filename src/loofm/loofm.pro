# -------------------------------------------------
# Project created by QtCreator 2010-05-15T16:14:31
# -------------------------------------------------
QT += widgets

DESTDIR += ../../usr/bin

TARGET = loofm

TEMPLATE = app

SOURCES += main.cpp \
    fileview.cpp

HEADERS += fileview.h

FORMS += fileview.ui

RESOURCES += resource.qrc

TRANSLATIONS +=filemanager_zh.ts

# install
target.path = /usr/bin
INSTALLS += target

