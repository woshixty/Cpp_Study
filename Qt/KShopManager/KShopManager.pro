#-------------------------------------------------
#
# Project created by QtCreator 2022-06-02T01:37:51
#
#-------------------------------------------------

QT       += core gui
QT       += core sql
QT       += core testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KShopManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        dao/kproductdao.cpp \
        dialog/kdialogin.cpp \
        kproductentity.cpp \
        kuserdao.cpp \
        kuserservice.cpp \
        main.cpp \
        mainwindow.cpp \
        test/kuserdaotest.cpp

HEADERS += \
        dao/kproductdao.h \
        dialog/kdialogin.h \
        kconstant.h \
        kproductentity.h \
        kuserdao.h \
        kuserentity.h \
        kuserservice.h \
        mainwindow.h \
        test/kuserdaotest.h \
        tool/ktoolmethod.h

FORMS += \
        dialog/kdialogin.ui \
        mainwindow.ui
