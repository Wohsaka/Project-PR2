#-------------------------------------------------
#
# Project created by QtCreator 2018-06-11T21:59:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto-PR2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    medicamento.cpp \
    ingresarfact.cpp \
    ver_inventario.cpp \
    vencimientos.cpp

HEADERS  += mainwindow.h \
    medicamento.h \
    ingresarfact.h \
    ver_inventario.h \
    vencimientos.h

FORMS    += mainwindow.ui \
    ingresarfact.ui \
    ver_inventario.ui \
    vencimientos.ui
