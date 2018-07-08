QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashesToHashes
DESTDIR = ../../bin
TEMPLATE = app

VERSION =  1.0.0.1
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

SOURCES += main.cpp\
        ui/mainwindow.cpp \
    hashes/hashesmanager.cpp \
    hashes/crc16/crc16family.cpp \
    hashes/crc16/crc16.cpp \
    hashes/crc16/crcccitt.cpp \
    hashes/crc16/crc16factory.cpp \
    hashes/crc16/crcccittfactory.cpp

HEADERS  += ui/mainwindow.h \
    hashes/hashesmanager.h \
    hashes/crc16/crc16family.h \
    hashes/crc16/crc16.h \
    hashes/crc16/crcccitt.h \
    hashes/crc16/crc16familyfactory.h \
    hashes/crc16/crc16factory.h \
    hashes/crc16/crcccittfactory.h

FORMS    += ui/mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cryptopp/release/ -lcryptopp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../cryptopp/debug/ -lcryptopp
else:unix: LIBS += -L$$OUT_PWD/../core/cryptopp/ -lcryptopp

INCLUDEPATH += $$PWD/../cryptopp
DEPENDPATH += $$PWD/../cryptopp

win32-msvc*{
    CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cryptopp/release/cryptopp.lib
    CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cryptopp/debug/cryptopp.lib
}

win32-g++{
    CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cryptopp/release/libcryptopp.a
    CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cryptopp/debug/libcryptopp.a
}

unix{
    PRE_TARGETDEPS += $$OUT_PWD/../core/cryptopp/libcryptopp.a
}

RC_ICONS = ui/images/hash-icon.ico

RESOURCES += \
    appresources.qrc
