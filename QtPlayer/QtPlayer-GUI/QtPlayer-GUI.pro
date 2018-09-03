#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T23:30:28
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = QtPlayer-GUI
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui

TRANSLATIONS += zh_CN.ts

unix:!macx: LIBS += -L$$PWD/dev/lib64/ -lVLCQtCore

INCLUDEPATH += $$PWD/dev/include
DEPENDPATH += $$PWD/dev/include

unix:!macx: LIBS += -L$$PWD/dev/lib64/ -lVLCQtWidgets

INCLUDEPATH += $$PWD/dev/include
DEPENDPATH += $$PWD/dev/include

DESTDIR = $$PWD/out

vlc_lib.path = $$DESTDIR

win32 {
    vlc_lib.files += $$PWD/dev/bin/VLCQtCore.dll
    vlc_lib.files += $$PWD/dev/bin/VLCQtWidgets.dll
}

INSTALLS += vlc_lib

RESOURCES += \
    iamge.qrc
