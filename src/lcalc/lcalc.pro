QT += widgets

include(../ldeframework/lithium/lithium.pri)

HEADERS       = button.h \
                calculator.h \
    history.h
SOURCES       = button.cpp \
                calculator.cpp \
                main.cpp \
    history.cpp

DESTDIR += ../../usr/bin

# install
target.path = /usr/bin
INSTALLS += target
