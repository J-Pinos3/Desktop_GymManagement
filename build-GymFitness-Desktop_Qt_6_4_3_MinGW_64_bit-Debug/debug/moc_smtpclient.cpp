/****************************************************************************
** Meta object code from reading C++ file 'smtpclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GymFitness/smtpclient.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smtpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_SmtpClient_t {
    uint offsetsAndSizes[128];
    char stringdata0[11];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[2];
    char stringdata5[13];
    char stringdata6[24];
    char stringdata7[2];
    char stringdata8[10];
    char stringdata9[15];
    char stringdata10[14];
    char stringdata11[9];
    char stringdata12[10];
    char stringdata13[13];
    char stringdata14[19];
    char stringdata15[29];
    char stringdata16[6];
    char stringdata17[12];
    char stringdata18[29];
    char stringdata19[16];
    char stringdata20[16];
    char stringdata21[11];
    char stringdata22[10];
    char stringdata23[10];
    char stringdata24[10];
    char stringdata25[23];
    char stringdata26[21];
    char stringdata27[20];
    char stringdata28[17];
    char stringdata29[12];
    char stringdata30[12];
    char stringdata31[12];
    char stringdata32[15];
    char stringdata33[14];
    char stringdata34[14];
    char stringdata35[14];
    char stringdata36[12];
    char stringdata37[17];
    char stringdata38[16];
    char stringdata39[15];
    char stringdata40[11];
    char stringdata41[20];
    char stringdata42[17];
    char stringdata43[19];
    char stringdata44[11];
    char stringdata45[12];
    char stringdata46[11];
    char stringdata47[17];
    char stringdata48[21];
    char stringdata49[16];
    char stringdata50[17];
    char stringdata51[16];
    char stringdata52[16];
    char stringdata53[15];
    char stringdata54[12];
    char stringdata55[14];
    char stringdata56[14];
    char stringdata57[19];
    char stringdata58[19];
    char stringdata59[13];
    char stringdata60[18];
    char stringdata61[13];
    char stringdata62[13];
    char stringdata63[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SmtpClient_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SmtpClient_t qt_meta_stringdata_SmtpClient = {
    {
        QT_MOC_LITERAL(0, 10),  // "SmtpClient"
        QT_MOC_LITERAL(11, 5),  // "error"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 21),  // "SmtpClient::SmtpError"
        QT_MOC_LITERAL(40, 1),  // "e"
        QT_MOC_LITERAL(42, 12),  // "stateChanged"
        QT_MOC_LITERAL(55, 23),  // "SmtpClient::ClientState"
        QT_MOC_LITERAL(79, 1),  // "s"
        QT_MOC_LITERAL(81, 9),  // "connected"
        QT_MOC_LITERAL(91, 14),  // "readyConnected"
        QT_MOC_LITERAL(106, 13),  // "authenticated"
        QT_MOC_LITERAL(120, 8),  // "mailSent"
        QT_MOC_LITERAL(129, 9),  // "mailReset"
        QT_MOC_LITERAL(139, 12),  // "disconnected"
        QT_MOC_LITERAL(152, 18),  // "socketStateChanged"
        QT_MOC_LITERAL(171, 28),  // "QAbstractSocket::SocketState"
        QT_MOC_LITERAL(200, 5),  // "state"
        QT_MOC_LITERAL(206, 11),  // "socketError"
        QT_MOC_LITERAL(218, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(247, 15),  // "socketReadyRead"
        QT_MOC_LITERAL(263, 15),  // "socketEncrypted"
        QT_MOC_LITERAL(279, 10),  // "AuthMethod"
        QT_MOC_LITERAL(290, 9),  // "AuthPlain"
        QT_MOC_LITERAL(300, 9),  // "AuthLogin"
        QT_MOC_LITERAL(310, 9),  // "SmtpError"
        QT_MOC_LITERAL(320, 22),  // "ConnectionTimeoutError"
        QT_MOC_LITERAL(343, 20),  // "ResponseTimeoutError"
        QT_MOC_LITERAL(364, 19),  // "AuthenticationError"
        QT_MOC_LITERAL(384, 16),  // "MailSendingError"
        QT_MOC_LITERAL(401, 11),  // "ServerError"
        QT_MOC_LITERAL(413, 11),  // "ClientError"
        QT_MOC_LITERAL(425, 11),  // "SocketError"
        QT_MOC_LITERAL(437, 14),  // "ConnectionType"
        QT_MOC_LITERAL(452, 13),  // "TcpConnection"
        QT_MOC_LITERAL(466, 13),  // "SslConnection"
        QT_MOC_LITERAL(480, 13),  // "TlsConnection"
        QT_MOC_LITERAL(494, 11),  // "ClientState"
        QT_MOC_LITERAL(506, 16),  // "UnconnectedState"
        QT_MOC_LITERAL(523, 15),  // "ConnectingState"
        QT_MOC_LITERAL(539, 14),  // "ConnectedState"
        QT_MOC_LITERAL(554, 10),  // "ReadyState"
        QT_MOC_LITERAL(565, 19),  // "AuthenticatingState"
        QT_MOC_LITERAL(585, 16),  // "MailSendingState"
        QT_MOC_LITERAL(602, 18),  // "DisconnectingState"
        QT_MOC_LITERAL(621, 10),  // "ResetState"
        QT_MOC_LITERAL(632, 11),  // "_EHLO_State"
        QT_MOC_LITERAL(644, 10),  // "_TLS_State"
        QT_MOC_LITERAL(655, 16),  // "_READY_Connected"
        QT_MOC_LITERAL(672, 20),  // "_READY_Authenticated"
        QT_MOC_LITERAL(693, 15),  // "_READY_MailSent"
        QT_MOC_LITERAL(709, 16),  // "_READY_Encrypted"
        QT_MOC_LITERAL(726, 15),  // "_QUITTING_State"
        QT_MOC_LITERAL(742, 15),  // "_TLS_0_STARTTLS"
        QT_MOC_LITERAL(758, 14),  // "_TLS_1_ENCRYPT"
        QT_MOC_LITERAL(773, 11),  // "_TLS_2_EHLO"
        QT_MOC_LITERAL(785, 13),  // "_AUTH_PLAIN_0"
        QT_MOC_LITERAL(799, 13),  // "_AUTH_LOGIN_0"
        QT_MOC_LITERAL(813, 18),  // "_AUTH_LOGIN_1_USER"
        QT_MOC_LITERAL(832, 18),  // "_AUTH_LOGIN_2_PASS"
        QT_MOC_LITERAL(851, 12),  // "_MAIL_0_FROM"
        QT_MOC_LITERAL(864, 17),  // "_MAIL_1_RCPT_INIT"
        QT_MOC_LITERAL(882, 12),  // "_MAIL_2_RCPT"
        QT_MOC_LITERAL(895, 12),  // "_MAIL_3_DATA"
        QT_MOC_LITERAL(908, 17)   // "_MAIL_4_SEND_DATA"
    },
    "SmtpClient",
    "error",
    "",
    "SmtpClient::SmtpError",
    "e",
    "stateChanged",
    "SmtpClient::ClientState",
    "s",
    "connected",
    "readyConnected",
    "authenticated",
    "mailSent",
    "mailReset",
    "disconnected",
    "socketStateChanged",
    "QAbstractSocket::SocketState",
    "state",
    "socketError",
    "QAbstractSocket::SocketError",
    "socketReadyRead",
    "socketEncrypted",
    "AuthMethod",
    "AuthPlain",
    "AuthLogin",
    "SmtpError",
    "ConnectionTimeoutError",
    "ResponseTimeoutError",
    "AuthenticationError",
    "MailSendingError",
    "ServerError",
    "ClientError",
    "SocketError",
    "ConnectionType",
    "TcpConnection",
    "SslConnection",
    "TlsConnection",
    "ClientState",
    "UnconnectedState",
    "ConnectingState",
    "ConnectedState",
    "ReadyState",
    "AuthenticatingState",
    "MailSendingState",
    "DisconnectingState",
    "ResetState",
    "_EHLO_State",
    "_TLS_State",
    "_READY_Connected",
    "_READY_Authenticated",
    "_READY_MailSent",
    "_READY_Encrypted",
    "_QUITTING_State",
    "_TLS_0_STARTTLS",
    "_TLS_1_ENCRYPT",
    "_TLS_2_EHLO",
    "_AUTH_PLAIN_0",
    "_AUTH_LOGIN_0",
    "_AUTH_LOGIN_1_USER",
    "_AUTH_LOGIN_2_PASS",
    "_MAIL_0_FROM",
    "_MAIL_1_RCPT_INIT",
    "_MAIL_2_RCPT",
    "_MAIL_3_DATA",
    "_MAIL_4_SEND_DATA"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SmtpClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       4,  106, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,
       5,    1,   89,    2, 0x06,    3 /* Public */,
       8,    0,   92,    2, 0x06,    5 /* Public */,
       9,    0,   93,    2, 0x06,    6 /* Public */,
      10,    0,   94,    2, 0x06,    7 /* Public */,
      11,    0,   95,    2, 0x06,    8 /* Public */,
      12,    0,   96,    2, 0x06,    9 /* Public */,
      13,    0,   97,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,   98,    2, 0x09,   11 /* Protected */,
      17,    1,  101,    2, 0x09,   13 /* Protected */,
      19,    0,  104,    2, 0x09,   15 /* Protected */,
      20,    0,  105,    2, 0x09,   16 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,    1,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      21,   21, 0x0,    2,  126,
      24,   24, 0x0,    7,  130,
      32,   32, 0x0,    3,  144,
      36,   36, 0x0,   27,  150,

 // enum data: key, value
      22, uint(SmtpClient::AuthPlain),
      23, uint(SmtpClient::AuthLogin),
      25, uint(SmtpClient::ConnectionTimeoutError),
      26, uint(SmtpClient::ResponseTimeoutError),
      27, uint(SmtpClient::AuthenticationError),
      28, uint(SmtpClient::MailSendingError),
      29, uint(SmtpClient::ServerError),
      30, uint(SmtpClient::ClientError),
      31, uint(SmtpClient::SocketError),
      33, uint(SmtpClient::TcpConnection),
      34, uint(SmtpClient::SslConnection),
      35, uint(SmtpClient::TlsConnection),
      37, uint(SmtpClient::UnconnectedState),
      38, uint(SmtpClient::ConnectingState),
      39, uint(SmtpClient::ConnectedState),
      40, uint(SmtpClient::ReadyState),
      41, uint(SmtpClient::AuthenticatingState),
      42, uint(SmtpClient::MailSendingState),
      43, uint(SmtpClient::DisconnectingState),
      44, uint(SmtpClient::ResetState),
      45, uint(SmtpClient::_EHLO_State),
      46, uint(SmtpClient::_TLS_State),
      47, uint(SmtpClient::_READY_Connected),
      48, uint(SmtpClient::_READY_Authenticated),
      49, uint(SmtpClient::_READY_MailSent),
      50, uint(SmtpClient::_READY_Encrypted),
      51, uint(SmtpClient::_QUITTING_State),
      52, uint(SmtpClient::_TLS_0_STARTTLS),
      53, uint(SmtpClient::_TLS_1_ENCRYPT),
      54, uint(SmtpClient::_TLS_2_EHLO),
      55, uint(SmtpClient::_AUTH_PLAIN_0),
      56, uint(SmtpClient::_AUTH_LOGIN_0),
      57, uint(SmtpClient::_AUTH_LOGIN_1_USER),
      58, uint(SmtpClient::_AUTH_LOGIN_2_PASS),
      59, uint(SmtpClient::_MAIL_0_FROM),
      60, uint(SmtpClient::_MAIL_1_RCPT_INIT),
      61, uint(SmtpClient::_MAIL_2_RCPT),
      62, uint(SmtpClient::_MAIL_3_DATA),
      63, uint(SmtpClient::_MAIL_4_SEND_DATA),

       0        // eod
};

Q_CONSTINIT const QMetaObject SmtpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SmtpClient.offsetsAndSizes,
    qt_meta_data_SmtpClient,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SmtpClient_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SmtpClient, std::true_type>,
        // method 'error'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SmtpClient::SmtpError, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SmtpClient::ClientState, std::false_type>,
        // method 'connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'authenticated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mailSent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mailReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'socketStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'socketError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'socketReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'socketEncrypted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SmtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SmtpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< std::add_pointer_t<SmtpClient::SmtpError>>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<SmtpClient::ClientState>>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->readyConnected(); break;
        case 4: _t->authenticated(); break;
        case 5: _t->mailSent(); break;
        case 6: _t->mailReset(); break;
        case 7: _t->disconnected(); break;
        case 8: _t->socketStateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 9: _t->socketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 10: _t->socketReadyRead(); break;
        case 11: _t->socketEncrypted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SmtpClient::*)(SmtpClient::SmtpError );
            if (_t _q_method = &SmtpClient::error; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)(SmtpClient::ClientState );
            if (_t _q_method = &SmtpClient::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (_t _q_method = &SmtpClient::connected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (_t _q_method = &SmtpClient::readyConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (_t _q_method = &SmtpClient::authenticated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (_t _q_method = &SmtpClient::mailSent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (_t _q_method = &SmtpClient::mailReset; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (_t _q_method = &SmtpClient::disconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *SmtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SmtpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SmtpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SmtpClient::error(SmtpClient::SmtpError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SmtpClient::stateChanged(SmtpClient::ClientState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SmtpClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SmtpClient::readyConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SmtpClient::authenticated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SmtpClient::mailSent()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SmtpClient::mailReset()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SmtpClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
