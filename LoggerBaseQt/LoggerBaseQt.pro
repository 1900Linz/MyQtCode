QT       += core gui qml  concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    logmanager.cpp \
    main.cpp \
    logview.cpp

HEADERS += \
    logmanager.h \
    logview.h

FORMS += \
    logview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc

DISTFILES +=

DESTDIR = $$PWD/bin
