TEMPLATE = app
TARGET      = test-cpp
CONFIG      += qt warn_on thread c++14
QT += qml quick widgets core gui quickcontrols2
include(../src/quickqanava.pri)
SOURCES += \
    ../cpp/cpp_sample.cpp \
    graphcreator.cpp \
    infoitem.cpp \
    kneron_sdk_p.cpp \
    kneron_internal_api.cpp \
    main.cpp

RESOURCES += \
    qml.qrc \
    ../cpp/cpp_sample.qrc
EXAMPLE_FILES = \
    layouts.qml

target.path = $$[QT_INSTALL_EXAMPLES]/quick/layouts
INSTALLS += target

DISTFILES += \
#    InputName.qml \
#    Compiler.qml \
    Viewer.qml \
    ../cpp/cpp_sample.qml \
    ../cpp/custom.qml \
    ../cpp/CustomEdge.qml \
    ../cpp/CustomGroup.qml \
    ../cpp/CustomNode.qml

HEADERS += \
    ../cpp/cpp_sample.h \
    graphcreator.h \
    infoitem.h \
    kneron_sdk_internal.h \
    onnx.pb.h \
    kneron_sdk_p.h \
    kneron_internal_api.h

