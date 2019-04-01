TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    arvoreavl.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arvoreavl.h

