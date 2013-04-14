QT += core

TEMPLATE = app
CONFIG += console qtestlib

SOURCES += \
    list.cpp \
    slist.cpp \
    listel.cpp \
    doublelistel.cpp \
    doublelist.cpp \
    main.cpp

HEADERS += \
    list.h \
    slist.h \
    listel.h \
    doublelistel.h \
    doublelist.h \
    Test/SLListTest.h \
    Test/DLListTest.h \
    Exceptions/emptycontainerexception.h \
    Exceptions/datanotfoundexception.h \
    Exceptions/dataexistsexception.h
