#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T11:32:36
#
#-------------------------------------------------

QT       += core gui

TARGET = Shulte
TEMPLATE = app


SOURCES += main.cpp\
        sulte.cpp

HEADERS  += sulte.h \
    csswork.h

FORMS    += sulte.ui

OTHER_FILES += \
    shulte_icon.rc

RESOURCES += \
    resouces.qrc

win32:RC_FILE = "shulte_icon.rc"
