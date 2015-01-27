
QT      +=  webkitwidgets network widgets

HEADERS =   mainwindow.h

SOURCES =   main.cpp \
            mainwindow.cpp

RESOURCES = jquery.qrc

TRANSLATIONS = looplorer_zh.ts

DESTDIR += ../../usr/bin

# install
# target.path = $$[QT_INSTALL_EXAMPLES]/webkitwidgets/fancybrowser
# INSTALLS += target
