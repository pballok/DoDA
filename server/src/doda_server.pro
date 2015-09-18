TEMPLATE     = app
CONFIG      += c++14
QT          += widgets sql
DESTDIR      = $$PWD/..


INCLUDEPATH += ../../../qtframework2

FORMS        = forms/dlgpreferences.ui \
               forms/wndmain.ui


HEADERS      = ../../../qtframework2/*.h \
               dlgpreferences.h \
               dodapreferences.h \
               idbpreferences.h \
               wndmain.h

SOURCES      = ../../../qtframework2/logger.cpp \
               ../../../qtframework2/preferences.cpp \
               ../../../qtframework2/severity.cpp \
               ../../../qtframework2/tracer.cpp \
               dlgpreferences.cpp \
               dodapreferences.cpp \
               main.cpp \
               wndmain.cpp
