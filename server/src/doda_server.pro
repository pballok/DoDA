TEMPLATE     = app
CONFIG      += c++14
QT          += widgets sql
DESTDIR      = $$PWD/..


INCLUDEPATH += ../../../qtframework2

FORMS        = forms/dlgcrud.ui \
               forms/dlgmaintenance.ui \
               forms/dlgpreferences.ui \
               forms/dlgstatus.ui \
               forms/wndmain.ui


HEADERS      = ../../../qtframework2/*.h \
               dlgcrud.h \
               dlgstatus.h \
               dlgmaintenance.h \
               dlgpreferences.h \
               dodapreferences.h \
               idbpreferences.h \
               wndmain.h

SOURCES      = ../../../qtframework2/loggedquery.cpp \
               ../../../qtframework2/logger.cpp \
               ../../../qtframework2/preferences.cpp \
               ../../../qtframework2/severity.cpp \
               ../../../qtframework2/tracer.cpp \
               dlgcrud.cpp \
               dlgstatus.cpp \
               dlgmaintenance.cpp \
               dlgpreferences.cpp \
               dodapreferences.cpp \
               main.cpp \
               wndmain.cpp
