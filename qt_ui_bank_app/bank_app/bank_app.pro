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
    clientdlg.cpp \
    pageoperate.cpp

HEADERS  += mainwindow.h \
    clientdlg.h \
    pageoperate.h

FORMS    += mainwindow.ui \
    clientdlg.ui \
    pageoperate.ui

RC_ICONS =images/icon.ico

DISTFILES +=

RESOURCES += \
    myimage.qrc
