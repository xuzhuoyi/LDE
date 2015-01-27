QT += widgets

HEADERS       = button.h \
                calculator.h
SOURCES       = button.cpp \
                calculator.cpp \
                main.cpp

DESTDIR += ../../usr/bin

# install
# target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/calculator
# INSTALLS += target
