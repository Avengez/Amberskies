#-------------------------------------------------
#
# Project created by QtCreator 2016-01-03T13:51:34
#
#-------------------------------------------------

QT       -= gui

TARGET = GameEngine
TEMPLATE = lib
CONFIG += staticlib

SOURCES += gameengine.cpp

HEADERS += gameengine.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
