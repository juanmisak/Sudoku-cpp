#-------------------------------------------------
#
# Project created by QtCreator 2013-06-05T12:34:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    cell.h

FORMS    += mainwindow.ui