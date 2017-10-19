INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib
LIBS += -larmadillo -llapack -lblas
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    eulercromer.cpp \
    integrator.cpp \
    main.cpp \
    velocityverlet.cpp

HEADERS += \
    eulercromer.h \
    integrator.h \
    velocityverlet.h
