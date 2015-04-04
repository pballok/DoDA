TEMPLATE     = app
CONFIG      += c++11
INCLUDEPATH += ../src
QT          -= gui
LIBS        += -lgtest -lgtest_main

HEADERS     += ../src/sector.h \
               ../src/zone.h
               
SOURCES     += test_sector.cpp \
               test_zone.cpp \
               ../src/sector.cpp \
               ../src/zone.cpp





