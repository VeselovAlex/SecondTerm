#-------------------------------------------------
#
# Project created by QtCreator 2013-03-10T12:17:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdvancedCalc
TEMPLATE = app

CONFIG += qtestlib

SOURCES +=\
        calculator.cpp \
    calc/SimpleCalculator.cpp \
    main.cpp

HEADERS  += calculator.h \
    calc/SimpleCalculator.h \
    tests/SimpleCalcTest.h

FORMS    += calculator.ui
