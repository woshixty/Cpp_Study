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
    delegate/kcategorydelegate.cpp \
        main.cpp \
        mainwindow.cpp \
    dao/kproductdao.cpp \
    test/ksingletontest.cpp \
    utils/ksingleton.cpp \
    utils/ksnowflake.cpp \
    windows/kenterpagewindow.cpp \
    windows/kloginwindow.cpp \
    test/kuserdaotest.cpp \
    windows/kproductmanagerwindow.cpp \
    service/kuserservice.cpp \
    dao/kuserdao.cpp \
    service/kproductservice.cpp \
    test/kproductdaotest.cpp \
    windows/kproductsellwindows.cpp

HEADERS += \
    delegate/kcategorydelegate.h \
        mainwindow.h \
    test/ksingletontest.h \
    utils/kconstants.h \
    entity/kproductentity.h \
    dao/kproductdao.h \
    utils/ksingleton.h \
    utils/ksnowflake.h \
    windows/kenterpagewindow.h \
    windows/kloginwindow.h \
    test/kuserdaotest.h \
    windows/kproductmanagerwindow.h \
    service/kuserservice.h \
    dao/kuserdao.h \
    entity/kuserentity.h \
    service/kproductservice.h \
    test/kproductdaotest.h \
    windows/kproductsellwindows.h

FORMS += \
        mainwindow.ui \
    windows/kenterpagewindow.ui \
    windows/kloginwindow.ui \
    windows/kproductmanagerwindow.ui \
    windows/kproductsellwindows.ui
