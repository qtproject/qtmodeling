TARGET = qdusemetamodel

PLUGIN_TYPE = metamodels
PLUGIN_CLASS_NAME = QDuseMetaModelPlugin
load(qt_plugin)

QT += modeling duse

HEADERS = qdusemetamodelplugin.h

SOURCES = qdusemetamodelplugin.cpp

xmi.files = Duse.xmi
xmi.path = $$MODULE_BASE_OUTDIR/plugins/$$PLUGIN_TYPE

INSTALLS += xmi

OTHER_FILES += duse.json
