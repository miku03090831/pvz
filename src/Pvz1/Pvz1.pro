QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/common.cpp \
    view/gameover_pic.cpp \
    view/pea_pic.cpp \
    view/plant_pic.cpp \
    view/seedbox.cpp \
    view/sun_pic.cpp \
    view/zombie_pic.cpp \
    viewmodel/gamewindow1.cpp \
    app/main.cpp \
    viewmodel/mainwindow.cpp \
    model/plant.cpp \
    model/shootpea.cpp \
    model/zombie.cpp

HEADERS += \
    common/common.h \
    view/gameover_pic.h \
    view/pea_pic.h \
    view/plant_pic.h \
    view/seedbox.h \
    view/sun_pic.h \
    view/zombie_pic.h \
    viewmodel/gamewindow1.h \
    viewmodel/mainwindow.h \
    model/plant.h \
    model/shootpea.h \
    model/zombie.h

FORMS += \
    viewmodel/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
