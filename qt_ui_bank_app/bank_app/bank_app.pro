#-------------------------------------------------
#
# Project created by QtCreator 2017-08-21T12:24:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bank_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clientdlg.cpp

HEADERS  += mainwindow.h \
    clientdlg.h

FORMS    += mainwindow.ui \
    clientdlg.ui

RC_ICONS = icon.ico
