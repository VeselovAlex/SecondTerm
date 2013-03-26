QT += core

TEMPLATE = app
CONFIG += console qtestlib
CONFIG -= app_bundle

SOURCES += \
    matrix.cpp \
    quicksort.cpp

HEADERS += \
    matrix.h \
    sort.h \
    quicksort.h \
    Tests/MatrixSorterTest.h

