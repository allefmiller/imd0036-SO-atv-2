#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T11:14:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trem
TEMPLATE = app

PATH = $$PWD


SOURCES += main.cpp\
        mainwindow.cpp \
    trem.cpp

HEADERS  += mainwindow.h \
    trem.h

FORMS    += mainwindow.ui

DISTFILES += \
    sprites/sprite-train-down.png \
    sprites/sprite-train-left.png \
    sprites/sprite-train-right.png \
    sprites/sprite-train-up.png
