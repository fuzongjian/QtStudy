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
    titlewidget.cpp \
    pushbutton.cpp \
    toolbutton.cpp \
    monitormanager.cpp \
    locationalarm.cpp \
    alarmrecord.cpp \
    handlelog.cpp \
    systemsetting.cpp

HEADERS  += mainwindow.h \
    titlewidget.h \
    pushbutton.h \
    toolbutton.h \
    monitormanager.h \
    locationalarm.h \
    alarmrecord.h \
    handlelog.h \
    systemsetting.h

FORMS    += mainwindow.ui \
    titlewidget.ui \
    monitormanager.ui \
    locationalarm.ui \
    alarmrecord.ui \
    handlelog.ui \
    systemsetting.ui

RESOURCES += \
    images.qrc


CONFIG += C++11
