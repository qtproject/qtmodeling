load(qt_build_config)

TARGET = QtWrappedObjects
QT = core-private gui

QMAKE_DOCS = $$PWD/doc/qtwrappedobjects.qdocconf

load(qt_module)

PUBLIC_HEADERS += \
    qtwrappedobjectsglobal.h \
    qwrappedobject.h \
    qmetawrappedobject.h \
    qwrappedobjectpointer.h \
    qtwrappedobjectsnamespace.h \
    qwrappedobjectmodel.h \
    qwrappedobjectpropertymodel.h \
    qmetamodelplugin.h

PRIVATE_HEADERS += \
    qwrappedobject_p.h \
    qmetawrappedobject_p.h

SOURCES += \
    qwrappedobject.cpp \
    qmetawrappedobject.cpp \
    qtwrappedobjectsnamespace.cpp \
    qwrappedobjectmodel.cpp \
    qwrappedobjectpropertymodel.cpp \
    qmetamodelplugin.cpp

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS