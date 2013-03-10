TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consoleprinter.cpp \
    fileprinter.cpp \
    matrix.cpp

HEADERS += \
    printer.h \
    consoleprinter.h \
    fileprinter.h \
    matrix.h

