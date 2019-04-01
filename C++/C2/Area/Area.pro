TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    areapoligono.cpp \
    retangulo.cpp \
    triangulo.cpp \
    circulo.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    areapoligono.h \
    retangulo.h \
    triangulo.h \
    circulo.h

