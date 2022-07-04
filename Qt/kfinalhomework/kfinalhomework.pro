QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dao/kguestdao.cpp \
    dao/kroominfodao.cpp \
    dao/kuserdoo.cpp \
    main.cpp \
    kmainwindow.cpp \
    service/kroomservice.cpp \
    service/kuserservice.cpp \
    view/innerpage/kemployeeregistration.cpp \
    view/innerpage/kemployeeupdate.cpp \
    view/innerpage/kguestinfocheck.cpp \
    view/innerpage/kroomcheckin.cpp \
    view/innerpage/kroomcheckout.cpp \
    view/innerpage/kroomsearch.cpp \
    view/kemployeeinformation.cpp \
    view/klogindialog.cpp \
    view/kroominformation.cpp \
    view/kroomstatus.cpp \
    view/ktodayroom.cpp \
    view/loginwindow.cpp

HEADERS += \
    dao/kguestdao.h \
    dao/kroominfodao.h \
    dao/kuserdoo.h \
    kmainwindow.h \
    service/kroomservice.h \
    service/kuserservice.h \
    utils/kconstant.h \
    view/innerpage/kemployeeregistration.h \
    view/innerpage/kemployeeupdate.h \
    view/innerpage/kguestinfocheck.h \
    view/innerpage/kroomcheckin.h \
    view/innerpage/kroomcheckout.h \
    view/innerpage/kroomsearch.h \
    view/kemployeeinformation.h \
    view/klogindialog.h \
    view/kroominformation.h \
    view/kroomstatus.h \
    view/ktodayroom.h \
    view/loginwindow.h

FORMS += \
    kmainwindow.ui \
    view/innerpage/kemployeeregistration.ui \
    view/innerpage/kemployeeupdate.ui \
    view/innerpage/kguestinfocheck.ui \
    view/innerpage/kroomcheckin.ui \
    view/innerpage/kroomcheckout.ui \
    view/innerpage/kroomsearch.ui \
    view/kemployeeinformation.ui \
    view/klogindialog.ui \
    view/kroominformation.ui \
    view/kroomstatus.ui \
    view/ktodayroom.ui \
    view/loginwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
