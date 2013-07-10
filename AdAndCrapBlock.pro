#-------------------------------------------------
#
# Project created by QtCreator 2013-07-05T19:41:42
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdAndCrapBlock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        downloader.cpp \
    parserthread.cpp \
    processsimthread.cpp

HEADERS  += mainwindow.h \
    downloader.h \
    parserthread.h \
    processsimthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    AppResources.qrc
