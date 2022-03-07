QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actionwidget.cpp \
    characterwidget.cpp \
    combatwidget.cpp \
    darklabel.cpp \
    deathsaves.cpp \
    dndobjects.cpp \
    dropdisplay.cpp \
    dropdowndarklabel.cpp \
    dropdownlabel.cpp \
    hitdie.cpp \
    introwindow.cpp \
    inventorywidget.cpp \
    itemwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    spellslotswidget.cpp \
    spellswidget.cpp \
    statdisplay.cpp \
    temphpwidget.cpp

HEADERS += \
    actionwidget.h \
    characterwidget.h \
    combatwidget.h \
    darklabel.h \
    deathsaves.h \
    dndobjects.h \
    dropdisplay.h \
    dropdowndarklabel.h \
    dropdownlabel.h \
    hitdie.h \
    introwindow.h \
    inventorywidget.h \
    itemwidget.h \
    mainwindow.h \
    spellslotswidget.h \
    spellswidget.h \
    statdisplay.h \
    temphpwidget.h

FORMS += \
    actionwidget.ui \
    characterwidget.ui \
    combatwidget.ui \
    darklabel.ui \
    deathsaves.ui \
    dropdisplay.ui \
    dropdowndarklabel.ui \
    dropdownlabel.ui \
    hitdie.ui \
    introwindow.ui \
    inventorywidget.ui \
    itemwidget.ui \
    mainwindow.ui \
    spellslotswidget.ui \
    spellswidget.ui \
    statdisplay.ui \
    temphpwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
