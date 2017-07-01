#-------------------------------------------------
#
# Project created by QtCreator 2017-07-01T17:14:12
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SafetyMonitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titlewidget.cpp

HEADERS  += mainwindow.h \
    titlewidget.h

FORMS    += mainwindow.ui \
    titlewidget.ui

RESOURCES += \
    images.qrc


CONFIG += C++11
