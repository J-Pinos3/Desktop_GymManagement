/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblGymImage;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLineEdit *txtUser;
    QLineEdit *txtPassword;
    QComboBox *cbxRoles;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnLogearse;
    QPushButton *btnRegistrarse;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(638, 714);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 15, 15);"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblGymImage = new QLabel(centralwidget);
        lblGymImage->setObjectName("lblGymImage");
        lblGymImage->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	margin-top: 40;\n"
"	margin-right: 40;\n"
"	margin-left: 40;\n"
"	background:black;\n"
"}\n"
"\n"
""));
        lblGymImage->setFrameShape(QFrame::Box);
        lblGymImage->setPixmap(QPixmap(QString::fromUtf8(":/images/Images/GoldsGym1.png")));
        lblGymImage->setScaledContents(true);
        lblGymImage->setAlignment(Qt::AlignCenter);
        lblGymImage->setMargin(2);

        verticalLayout_2->addWidget(lblGymImage);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(120, -1, 120, -1);
        txtUser = new QLineEdit(centralwidget);
        txtUser->setObjectName("txtUser");
        QFont font;
        font.setPointSize(12);
        txtUser->setFont(font);
        txtUser->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	padding-left: 20;\n"
"	height: 30;\n"
"	background-color: white;\n"
"}"));

        verticalLayout->addWidget(txtUser);

        txtPassword = new QLineEdit(centralwidget);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setFont(font);
        txtPassword->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	padding-left: 20;\n"
"	height: 30;\n"
"	background-color: white;\n"
"}"));
        txtPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(txtPassword);

        cbxRoles = new QComboBox(centralwidget);
        cbxRoles->setObjectName("cbxRoles");
        cbxRoles->setFont(font);
        cbxRoles->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	padding-left: 20;\n"
"	height: 30;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QComboBox::open {\n"
"	background-color: yellow;\n"
"}\n"
"\n"
"QComboBox QListView {\n"
"	background-color: white;\n"
"}"));

        verticalLayout->addWidget(cbxRoles);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnLogearse = new QPushButton(centralwidget);
        btnLogearse->setObjectName("btnLogearse");
        btnLogearse->setBaseSize(QSize(20, 20));
        btnLogearse->setFont(font);
        btnLogearse->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 120;\n"
"	height: 45;\n"
"	background: white;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed {\n"
"background: #ffd600; \n"
"}"));

        horizontalLayout->addWidget(btnLogearse);

        btnRegistrarse = new QPushButton(centralwidget);
        btnRegistrarse->setObjectName("btnRegistrarse");
        btnRegistrarse->setFont(font);
        btnRegistrarse->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 120;\n"
"	height: 45;\n"
"	background: white;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed {\n"
"background: #ffd600; \n"
"}"));

        horizontalLayout->addWidget(btnRegistrarse);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(txtUser, btnRegistrarse);
        QWidget::setTabOrder(btnRegistrarse, btnLogearse);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblGymImage->setText(QString());
        txtUser->setPlaceholderText(QCoreApplication::translate("MainWindow", "Correo ", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Contrase\303\261a ", nullptr));
        btnLogearse->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        btnRegistrarse->setText(QCoreApplication::translate("MainWindow", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
