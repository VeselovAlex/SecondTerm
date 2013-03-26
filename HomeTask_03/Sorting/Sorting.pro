QT += core

TEMPLATE = app
CONFIG += console
CONFIG += qtestlib

SOURCES += \
    bubblesort.cpp \
    quicksort.cpp \
    chosesort.cpp \
    main.cpp

HEADERS += \
    sort.h \
    bubblesort.h \
    quicksort.h \
    chosesort.h \
    Tests/BubbleSortTest.h \
    Tests/QuickSortTest.h \
    Tests/ChoseSortTest.h \
    Tests.h

OTHER_FILES +=

