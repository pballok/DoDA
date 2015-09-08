TEMPLATE     = app
CONFIG      += c++14
QT          += widgets
DESTDIR      = $$PWD


INCLUDEPATH += ../../../qtframework2

FORMS        = forms/mainwindow.ui

HEADERS      = ../../../qtframework2/*.h \
               dodapreferences.h \
               mainwindow.h

SOURCES      = ../../../qtframework2/preferences.cpp \
               ../../../qtframework2/severity.cpp \
               main.cpp \
               mainwindow.cpp
