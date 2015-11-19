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
               ui/dlgcrud.h \
               ui/dlgcrudmaps.h \
               ui/dlgstatus.h \
               ui/dlgmaintenance.h \
               ui/dlgpreferences.h \
               ui/wndmain.h \
               dodapreferences.h \
               idbpreferences.h

SOURCES      = ../../../qtframework2/loggedquery.cpp \
               ../../../qtframework2/logger.cpp \
               ../../../qtframework2/preferences.cpp \
               ../../../qtframework2/severity.cpp \
               ../../../qtframework2/tracer.cpp \
               ui/dlgcrud.cpp \
               ui/dlgcrudmaps.cpp \
               ui/dlgstatus.cpp \
               ui/dlgmaintenance.cpp \
               ui/dlgpreferences.cpp \
               ui/wndmain.cpp \
               dodapreferences.cpp \
               main.cpp
