#-------------------------------------------------
#
# Project created by QtCreator 2022-06-02T01:37:51
#
#-------------------------------------------------

QT       += core gui sql testlib

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
        main.cpp \
        mainwindow.cpp \
    entity/kproductentity.cpp \
    dao/kproductdao.cpp \
    windows/kloginwindow.cpp \
    test/kuserdaotest.cpp \
    windows/kproductmanagerwindow.cpp \
    service/kuserservice.cpp \
    dao/kuserdao.cpp \
    entity/kuserentity.cpp \
    service/kproductservice.cpp \
    test/kproductdaotest.cpp

HEADERS += \
        mainwindow.h \
    utils/kconstants.h \
    entity/kproductentity.h \
    dao/kproductdao.h \
    windows/kloginwindow.h \
    test/kuserdaotest.h \
    utils/ktoolmethods.h \
    windows/kproductmanagerwindow.h \
    service/kuserservice.h \
    dao/kuserdao.h \
    entity/kuserentity.h \
    service/kproductservice.h \
    test/kproductdaotest.h

FORMS += \
        mainwindow.ui \
    windows/kloginwindow.ui \
    windows/kproductmanagerwindow.ui
