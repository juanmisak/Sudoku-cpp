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
    cell.cpp \
    home.cpp \
    developer.cpp

HEADERS  += mainwindow.h \
    cell.h \
    home.h \
    developer.h

FORMS    += mainwindow.ui \
    home.ui \
    developer.ui

RESOURCES += \
    Resources.qrc
