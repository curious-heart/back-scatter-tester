QT       += core gui serialbus serialport network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "$$[QT_INSTALL_HEADERS]/QtSerialBus/$$[QT_VERSION]/QtSerialBus" \
"$$[QT_INSTALL_HEADERS]/QtCore/$$[QT_VERSION]/QtCore" \
"$$[QT_INSTALL_HEADERS]/QtCore/$$[QT_VERSION]"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common_tools/common_tool_func.cpp \
    config_recorder/uiconfigrecorder.cpp \
    logger/logger.cpp \
    main.cpp \
    maindialog.cpp \
    qtsingleapplication/qtlocalpeer.cpp \
    qtsingleapplication/qtlockedfile.cpp \
    qtsingleapplication/qtlockedfile_unix.cpp \
    qtsingleapplication/qtlockedfile_win.cpp \
    qtsingleapplication/qtsingleapplication.cpp \
    qtsingleapplication/qtsinglecoreapplication.cpp \
    sc_data_connsettings.cpp \
    serialportsetdlg.cpp \
    sysconfigs/sysconfigs.cpp \
    version_def/version_def.cpp

HEADERS += \
    common_tools/common_tool_func.h \
    config_recorder/uiconfigrecorder.h \
    logger/logger.h \
    maindialog.h \
    qtsingleapplication/QtLockedFile \
    qtsingleapplication/QtSingleApplication \
    qtsingleapplication/qtlocalpeer.h \
    qtsingleapplication/qtlockedfile.h \
    qtsingleapplication/qtsingleapplication.h \
    qtsingleapplication/qtsinglecoreapplication.h \
    sc_data_connsettings.h \
    serialportsetdlg.h \
    sysconfigs/sysconfigs.h \
    version_def/version_def.h

FORMS += \
    maindialog.ui \
    sc_data_connsettings.ui \
    serialportsetdlg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8