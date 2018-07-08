#-------------------------------------------------
#
# Project created by QtCreator 2018-07-07T17:58:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE     =      subdirs
CONFIG      +=      c++11

SUBDIRS += cryptopp \
           app

app.depends = cryptopp
