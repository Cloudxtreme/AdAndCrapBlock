#-------------------------------------------------
#
# Project created by QtCreator 2013-07-05T19:41:42
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdAndCrapBlock
target.path = /usr/bin
INSTALLS += target
TEMPLATE = app

data.path = /usr/share/AdAndCrapBlock/icons
data.files = icons/*
INSTALLS += data

desktop.path = /usr/share/applications
desktop.files = AdAndCrapBlock.desktop
INSTALLS += desktop


SOURCES += main.cpp\
        mainwindow.cpp \
        downloader.cpp \
    parserthread.cpp \
    processsimthread.cpp \
    pathhelper.cpp \
    addurl.cpp

HEADERS  += mainwindow.h \
    downloader.h \
    parserthread.h \
    processsimthread.h \
    pathhelper.h \
    addurl.h

FORMS    += mainwindow.ui \
    addurl.ui

RESOURCES += \
    AppResources.qrc
