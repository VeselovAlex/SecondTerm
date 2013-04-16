#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T19:20:28
#
#-------------------------------------------------

QT       += core gui


TARGET = Game
TEMPLATE = app
CONFIG += qtestlib

SOURCES += main.cpp\
        GameField.cpp \
        GameButton.cpp \
    GameChecker.cpp

HEADERS  += GameField.h \
         GameButton.h \
    GameChecker.h \
    GameCheckerTest.h

FORMS    += GameField.ui

RESOURCES += \
    TokenIcons.qrc
