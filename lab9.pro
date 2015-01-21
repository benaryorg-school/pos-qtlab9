TEMPLATE = app
TARGET = main
DEPENDPATH += lang src
INCLUDEPATH += src
OBJECTS_DIR = build/obj
MOC_DIR = build/moc

QT += core gui widgets
CONFIG += release qt
CONFIG -= debug

QMAKE_CXXFLAGS += -std=c++11

RESOURCES = qt.qrc

# Input
HEADERS += src/enums.h src/window.h src/input.h src/options.h src/logo.h src/results.h
SOURCES += src/main.cpp src/window.cpp src/input.cpp src/options.cpp src/logo.cpp src/results.cpp
TRANSLATIONS += lang/de.ts
