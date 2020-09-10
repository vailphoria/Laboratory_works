INCLUDEPATH += D:\QTprojects\Lab9\Lab9_Project_for_tests
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../Lab9_Project_for_tests/IKeypad.h \
        ../Lab9_Project_for_tests/ILatch.h \
        ../Lab9_Project_for_tests/lockcontroller.h \
        tst_testirovanie.h

SOURCES += \
        ../Lab9_Project_for_tests/lockcontroller.cpp \
        main.cpp
