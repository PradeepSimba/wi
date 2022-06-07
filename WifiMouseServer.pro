#-------------------------------------------------
#
# Project created by QtCreator 2017-07-30T12:52:11
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

QT += svg
QT += network
QT += bluetooth

win32 {
    SOURCES += fakeinput-windows.cpp
    LIBS += -luser32 -lpdh
}
macx {
    LIBS += -framework ApplicationServices
    SOURCES += fakeinput-mac.cpp
    ICON = $${PWD}/MacIcon.icns
    #note: on Mac had to edit ~/Qt/ver/mkspecs/macx-clang/Info.plist to add
    #LSUIElement 1 to hide from dock
}
linux {
    # to compile qt statically:
    #./configure -static -prefix /home/computer/Qt-static -release -nomake examples -skip qtwebengine -qt-xcb -qt-xkbcommon
    LIBS += -lXtst -lX11
    SOURCES += fakeinput-linux.cpp
    HEADERS += fakeinput-linux-keysyms-map.h
    QMAKE_LFLAGS += -no-pie
}

TARGET = WifiMouseServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    networkthread.cpp \
    abstractedserver.cpp \
    encryptutils.cpp \
    aes.c \
    abstractedsocket.cpp 

HEADERS  += networkthread.h \
    fakeinput.h \
    abstractedserver.h \
    encryptutils.h \
    aes.h \
    abstractedsocket.h 

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
