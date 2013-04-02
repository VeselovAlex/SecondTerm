#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:53:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robot
TEMPLATE = app


SOURCES += main.cpp\
    Processor.cpp \
    Command.cpp

HEADERS  += \
    Equip/Engine.h \
    Processor.h \
    Equip/DistanceSensor.h \
    Equip/TouchSensor.h \
    Command.h

FORMS    +=
