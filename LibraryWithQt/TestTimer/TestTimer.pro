TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Timer/release/ -lTimer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Timer/debug/ -lTimer
else:unix: LIBS += -L$$OUT_PWD/../Timer/ -lTimer

INCLUDEPATH += $$PWD/../Timer
DEPENDPATH += $$PWD/../Timer
