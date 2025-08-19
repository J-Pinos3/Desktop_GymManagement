QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controllers/LoginControllers/logincontroller.cpp \
    Controllers/PersonControllers/personcontroller.cpp \
    Controllers/AppointmentControllers/appointmentcontroller.cpp \
    Controllers/PaymentControllers/paymentcontrollers.cpp \
    Controllers/ReportsControllers/reportcontroller.cpp \
    Models/detallefactura.cpp \
    Models/detallereporte.cpp \
    Models/factura.cpp \
    Models/paqueteentreno.cpp \
    Models/persona.cpp \
    Models/planelegido.cpp \
    Models/servicio.cpp \
    Models/servicioelegido.cpp \
    View/dialogcalendar.cpp \
    View/gymoperations.cpp \
    emailaddress.cpp \
    main.cpp \
    mainwindow.cpp \
    Models/rol.cpp \
    mimeattachment.cpp \
    mimebase64encoder.cpp \
    mimebase64formatter.cpp \
    mimebytearrayattachment.cpp \
    mimecontentencoder.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimeqpencoder.cpp \
    mimeqpformatter.cpp \
    mimetext.cpp \
    quotedprintable.cpp \
    smtpclient.cpp \
    sqlconnection.cpp

HEADERS += \
    Controllers/LoginControllers/logincontroller.h \
    Controllers/PersonControllers/personcontroller.h \
    Controllers/AppointmentControllers/appointmentcontroller.h \
    Controllers/PaymentControllers/paymentcontrollers.h \
    Controllers/ReportsControllers/reportcontroller.h \
    Models/detallefactura.h \
    Models/detallereporte.h \
    Models/factura.h \
    Models/paqueteentreno.h \
    Models/persona.h \
    Models/planelegido.h \
    Models/servicio.h \
    View/dialogcalendar.h \
    View/gymoperations.h \
    Models/servicioelegido.h \
    SmtpMime \
    emailaddress.h \
    mainwindow.h \
    Models/rol.h \
    mimeattachment.h \
    mimebase64encoder.h \
    mimebase64formatter.h \
    mimebytearrayattachment.h \
    mimecontentencoder.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimeqpencoder.h \
    mimeqpformatter.h \
    mimetext.h \
    quotedprintable.h \
    smtpclient.h \
    smtpmime_global.h \
    sqlconnection.h

FORMS += \
    View/dialogcalendar.ui \
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

SUBDIRS += \
    SMTPEmail.pro
