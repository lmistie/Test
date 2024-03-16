QT -= gui
QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#unix:!macx: LIBS += -L$$PWD/../SmtpClient-for-Qt/src/ -lSmtpMime

#INCLUDEPATH += $$PWD/../SmtpClient-for-Qt/src
#DEPENDPATH += $$PWD/../SmtpClient-for-Qt/src


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../SmtpClient-for-Qt-2.0/src/release/ -lSmtpMime2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../SmtpClient-for-Qt-2.0/src/debug/ -lSmtpMime2
else:unix: LIBS += -L$$PWD/../SmtpClient-for-Qt-2.0/src/ -lSmtpMime2

INCLUDEPATH += $$PWD/../SmtpClient-for-Qt-2.0/src/debug
DEPENDPATH += $$PWD/../SmtpClient-for-Qt-2.0/src/debug
