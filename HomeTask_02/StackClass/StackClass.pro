QT += core

TEMPLATE = app
CONFIG += console qtestlib

SOURCES += \
    stack.cpp \
    arraystack.cpp \
    pointerstack.cpp \
    listel.cpp

HEADERS += \
    stack.h \
    arraystack.h \
    pointerstack.h \
    listel.h \
    Tests/PointerStackTest.h \
    Tests/ArrayStackTest.h

