#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T08:19:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebDermGui
TEMPLATE = app

SOURCES +=\
        mainwindow.cpp \
    displaywindow.cpp \
    histogramdialog.cpp \
    run.cpp \
    mousecolorgui.cpp \
    main.cpp \
    Algorithms/mean.cpp \
    Algorithms/median.cpp \
    Algorithms/quicksort.cpp \
    Algorithms/stddev.cpp \
    Algorithms/write.cpp \
    Color/color.cpp \
    Contrast/contrast.cpp \
    FileData/filedata.cpp \
    Histogram/histogram.cpp \
    hsl/hsl.cpp \
    hysteresis/hysteresis.cpp \
    Intensity/intensity.cpp \
    Intensity/rules.cpp \
    Math/maths.cpp \
    MD5/md5.cpp \
    Mouse/mouse.cpp \
    rgb/rgb.cpp \
    Shades/shades.cpp \
    skin/Skin.cpp \
    test/testfunctions.cpp \
    functions.cpp \
    functions2.cpp \
    global.cpp \
    stdafx.cpp \
    table.cpp \
    test.cpp \
    hysteresisgui.cpp

HEADERS  += mainwindow.h \
    displaywindow.h \
    histogramdialog.h \
    mousecolorgui.h \
    Algorithms/mean.h \
    Algorithms/median.h \
    Algorithms/quicksort.h \
    Algorithms/stddev.h \
    Algorithms/write.h \
    Color/color.h \
    Contrast/contrast.h \
    FileData/filedata.h \
    Histogram/histogram.h \
    hsl/hsl.h \
    hysteresis/hysteresis.h \
    Intensity/intensity.h \
    Intensity/rules.h \
    Math/maths.h \
    MD5/md5.h \
    Mouse/mouse.h \
    rgb/rgb.h \
    Shades/shades.h \
    skin/Skin.h \
    test/testfunctions.h \
    functions.h \
    functions2.h \
    global.h \
    run.h \
    stdafx.h \
    table.h \
    test.h \
    hysteresisgui.h

FORMS    += mainwindow.ui \
    displaywindow.ui \
    histogramdialog.ui \
    mousecolorgui.ui \
    hysteresisgui.ui

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lopencv_core

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_highgui

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_imgproc

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/ -lboost_filesystem

INCLUDEPATH += $$PWD/../../../../../../usr/include/boost
DEPENDPATH += $$PWD/../../../../../../usr/include/boost

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/ -lboost_system

INCLUDEPATH += $$PWD/../../../../../../usr/include/boost
DEPENDPATH += $$PWD/../../../../../../usr/include/boost
