#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T16:46:37
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_task
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    sqlconnectiondialog.cpp

HEADERS  += mainwindow.h \
    sqlconnectiondialog.h

FORMS    += mainwindow.ui \
    sqlconnectiondialog.ui
