TEMPLATE     = app
CONFIG      += c++14
QT          += widgets
DESTDIR      = $$PWD/..


INCLUDEPATH += ../../../qtframework2

FORMS        = forms/mainwindow.ui

HEADERS      = ../../../qtframework2/*.h \
               dodapreferences.h \
               mainwindow.h

SOURCES      = ../../../qtframework2/logger.cpp \
               ../../../qtframework2/preferences.cpp \
               ../../../qtframework2/severity.cpp \
               ../../../qtframework2/tracer.cpp \
               main.cpp \
               mainwindow.cpp
