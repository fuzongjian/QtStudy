#-------------------------------------------------
#
# Project created by QtCreator 2017-07-01T11:37:36
#
#-------------------------------------------------

QT       += core gui sql xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    domxml.cpp

HEADERS  += mainwindow.h \
    domxml.h

FORMS    += mainwindow.ui
