QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controllers/LoginControllers/logincontroller.cpp \
    Models/persona.cpp \
    View/gymoperations.cpp \
    main.cpp \
    mainwindow.cpp \
    Models/rol.cpp \
    sqlconnection.cpp

HEADERS += \
    Controllers/LoginControllers/logincontroller.h \
    Models/persona.h \
    View/gymoperations.h \
    mainwindow.h \
    Models/rol.h \
    sqlconnection.h

FORMS += \
    View/gymoperations.ui \
    mainwindow.ui


# Añadir las rutas de inclusión
INCLUDEPATH += "C:/Program Files/OpenSSL-Win64/include/"

# Añadir las bibliotecas
LIBS += -L"C:/Program Files/OpenSSL-Win64/lib/VC/x64/MD" -llibcrypto -llibssl

LIBS += -L"C:/Program Files/OpenSSL-Win64/bin/libcrypto-3-x64.dll"
LIBS += -L"C:/Program Files/OpenSSL-Win64/bin/libssl-3-x64.dll"
INCLUDEPATH += "C:/Program Files/OpenSSL-Win64/bin"


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
