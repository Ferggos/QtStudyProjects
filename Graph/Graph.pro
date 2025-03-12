QT += widgets
CONFIG += c++17


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += \
        graph.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        graph.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
