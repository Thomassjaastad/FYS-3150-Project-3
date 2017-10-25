TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE -= -O2

SOURCES += main.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    vec3.cpp \
    euler.cpp \
    velocityverlet.cpp

HEADERS += \
    celestialbody.h \
    solarsystem.h \
    vec3.h \
    euler.h \
    velocityverlet.h

