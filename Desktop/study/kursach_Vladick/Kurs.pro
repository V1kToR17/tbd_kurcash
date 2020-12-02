QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autorization.cpp \
    bank.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialog3.cpp \
    dialog4.cpp \
    main.cpp \
    mainwindow.cpp \
    material.cpp \
    provider.cpp

HEADERS += \
    ../../../Documents/tbd_kursach/deaths_by_year.h \
    autorization.h \
    bank.h \
    dialog1.h \
    dialog2.h \
    dialog3.h \
    dialog4.h \
    global.h \
    mainwindow.h \
    material.h \
    provider.h

FORMS += \
    autorization.ui \
    bank.ui \
    dialog1.ui \
    dialog2.ui \
    dialog3.ui \
    dialog4.ui \
    mainwindow.ui \
    material.ui \
    provider.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
