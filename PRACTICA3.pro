TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        funciones.cpp \
        main.cpp

HEADERS += \
    funciones.h
QMAKE_CXXFLAGS += -std=c++11
