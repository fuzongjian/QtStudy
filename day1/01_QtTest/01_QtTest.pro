#-------------------------------------------------
#
# Project created by QtCreator 2017-06-26T16:22:02
#
#-------------------------------------------------
# 模块
QT       += core gui
# 高于4版本，添加QT += widgets，为了兼容Qt4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#应用程序的名字  可以任意修改
TARGET = 01_QtTest

#指定makefile的类型，app
TEMPLATE = app

#源文件  .cpp文件
SOURCES += main.cpp\
        mywidget.cpp
#头文件  .h文件
HEADERS  += mywidget.h
