TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    aes.cpp \
    jni_impl.cpp

HEADERS += \
    aes.h \
    com_km_chat_custom_AESMessageMapper.h

INCLUDEPATH += /usr/lib/jvm/java-8-openjdk/include/
INCLUDEPATH += /usr/lib/jvm/java-8-openjdk/include/linux
LIBS += /usr/lib/jvm/java-8-openjdk/jre/lib/amd64/server/libjvm.so

