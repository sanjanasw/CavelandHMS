QT       += core gui
QT       += core gui charts
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    analyticsdata.cpp \
    dashboarddata.cpp \
    dbconnection.cpp \
    expansions.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    popupwindow.cpp \
    staff.cpp \
    studentsdata.cpp

HEADERS += \
    analyticsdata.h \
    dashboarddata.h \
    dbconnection.h \
    expansions.h \
    login.h \
    mainwindow.h \
    popupwindow.h \
    staff.h \
    studentsdata.h

FORMS += \
    mainwindow.ui \
    popupwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    img/29299 1.png \
    img/5293 1.png
