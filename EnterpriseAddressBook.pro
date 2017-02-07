#-------------------------------------------------
#
# Projet Tony CALVEZ - 2017
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnterpriseAddressBook
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ajouterdialog.cpp \

HEADERS  += widget.h \
    ajouterdialog.h

FORMS    += widget.ui \
    ajouterdialog.ui

RC_FILE = myapp.rc
