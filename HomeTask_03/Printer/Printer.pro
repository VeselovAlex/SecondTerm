TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    printer.cpp \
    consoleprinter.cpp \
    fileprinter.cpp

HEADERS += \
    printer.h \
    consoleprinter.h \
    fileprinter.h

