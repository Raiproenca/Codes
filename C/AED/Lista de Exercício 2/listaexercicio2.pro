TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    lista.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    lista.h

