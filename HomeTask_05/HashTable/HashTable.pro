#-------------------------------------------------
#
# Project created by QtCreator 2013-03-15T11:24:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashTable
TEMPLATE = app

CONFIG += qtestlib

SOURCES +=\
    HashTable/hashtableofstrings.cpp \
    HashTable/hashfunctions.cpp \
    List/slist.cpp \
    List/listel.cpp \
    List/list.cpp

HEADERS  += \
    HashTable/hashtableofstrings.h \
    HashTable/hashfunctions.h \
    List/slist.h \
    List/listel.h \
    List/list.h \
    Test/HashTableTest.h

FORMS    +=
