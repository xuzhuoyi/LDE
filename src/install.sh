#!/bin/sh
install -d /usr/
install -d /usr/bin/
install -d /usr/share/
install -d /usr/share/applications/
install -d /usr/share/xsessions/
install -d /usr/share/wallpapers/
install -d /usr/share/apps/kdm/sessions/
install usr/bin/* /usr/bin/
install share/*.desktop /usr/share/applications/
install shell/startlde /usr/bin/
install xsessions/LDE.desktop /usr/share/xsessions/
install wallpapers/lde-default.png /usr/share/wallpapers/
install xsessions/LDE.desktop /usr/share/apps/kdm/sessions/
