CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(slidingbarplugin)
TEMPLATE    = lib

HEADERS     = slidingbarplugin.h \
    slidingbar.h
SOURCES     = slidingbarplugin.cpp \
    slidingbar.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(slidingbar.pri)

FORMS += \
    slidingbar.ui
