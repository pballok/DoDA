TEMPLATE     = app
CONFIG      += c++14
QT          -= gui
LIBS        += -lgtest -lgtest_main
DESTDIR      = $$PWD

INCLUDEPATH += ../../../qtframework2 \
               ../src

HEADERS     += ../../../qtframework2/enum_to_string.h \
               ../../../qtframework2/severity.h \
               ../src/hexcoordinate.h \
               ../src/sector.h \
               ../src/zone.h
               
SOURCES     += test_hexcoordinate.cpp \
               test_sector.cpp \
               test_zone.cpp \
               ../src/hexcoordinate.cpp \
               ../src/sector.cpp \
               ../src/zone.cpp

