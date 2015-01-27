QT += widgets

HEADERS       = button.h \
                calculator.h
SOURCES       = button.cpp \
                calculator.cpp \
                main.cpp

DESTDIR += ../../usr/bin

# install
target.path = /usr/bin
INSTALLS += target

