#-------------------------------------------------
#
# Project created by QtCreator 2013-03-10T12:17:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdvancedCalc
TEMPLATE = app


SOURCES += main.cpp\
        calculator.cpp \
    calc/SimpleCalculator.cpp

HEADERS  += calculator.h \
    calc/SimpleCalculator.h

FORMS    += calculator.ui
