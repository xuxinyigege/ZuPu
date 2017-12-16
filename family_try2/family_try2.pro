#-------------------------------------------------
#
# Project created by QtCreator 2017-12-14T21:38:14
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = family_try2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    ../../../图片/family_tree/familymanagement.cpp \
    ../../../图片/family_tree/Date.cpp \
    ../../../图片/family_tree/main.cpp \
    fileoperate.cpp \
    creatfamily.cpp \
    mainmenu.cpp \
    mainmenu.cpp \
    familymanage.cpp \
    changeinfo.cpp \
    memberinsert.cpp \
    memberdelete.cpp \
    familyview.cpp \
    bloodview.cpp \
    familychoose.cpp \
    membersearch.cpp

HEADERS += \
    ../../../图片/family_tree/Date.h \
    ../../../图片/family_tree/familymanagement.h \
    mainmenu.h \
    fileoperate.h \
    creatfamily.h \
    creatfamily.h \
    familymanage.h \
    mainmenu.h \
    familymanage.h \
    changeinfo.h \
    memberinsert.h \
    memberdelete.h \
    familyview.h \
    bloodview.h \
    familychoose.h \
    membersearch.h \
    tree.h

FORMS += \
    creatfamily.ui \
    mainmenu.ui \
    familymanage.ui \
    changeinfo.ui \
    memberinsert.ui \
    memberdelete.ui \
    familyview.ui \
    bloodview.ui \
    familychoose.ui \
    membersearch.ui

DISTFILES += \
    ../../../图片/family_tree/member.txt
