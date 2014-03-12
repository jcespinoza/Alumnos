#-------------------------------------------------
#
# Project created by QtCreator 2014-03-05T11:01:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Alumnos
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filemanager.cpp \
    tabladedatos.cpp

HEADERS  += mainwindow.h \
    filemanager.h \
    tabladedatos.h

FORMS    += mainwindow.ui

RESOURCES += \
    Iconos.qrc
