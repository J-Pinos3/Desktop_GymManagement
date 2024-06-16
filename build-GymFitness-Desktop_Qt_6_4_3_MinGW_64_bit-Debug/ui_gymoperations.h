/********************************************************************************
** Form generated from reading UI file 'gymoperations.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GYMOPERATIONS_H
#define UI_GYMOPERATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GymOperations
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabInicio;
    QPushButton *pushButton;
    QWidget *tabGestion;
    QPushButton *pushButton_2;
    QWidget *tabCitas;
    QPushButton *pushButton_3;
    QWidget *tabPagos;
    QPushButton *pushButton_4;

    void setupUi(QWidget *GymOperations)
    {
        if (GymOperations->objectName().isEmpty())
            GymOperations->setObjectName("GymOperations");
        GymOperations->resize(855, 509);
        GymOperations->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"QPushButton{\n"
"background-color: #f232A;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(GymOperations);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(GymOperations);
        tabWidget->setObjectName("tabWidget");
        QFont font;
        font.setPointSize(18);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{\n"
"	background-color: #00aaff;\n"
"	padding-top: 10%;\n"
"	padding-right: 20%;\n"
"	padding-bottom: 10%;\n"
"	padding-left: 20%;\n"
"}"));
        tabInicio = new QWidget();
        tabInicio->setObjectName("tabInicio");
        pushButton = new QPushButton(tabInicio);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 100, 75, 24));
        tabWidget->addTab(tabInicio, QString());
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        pushButton_2 = new QPushButton(tabGestion);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 100, 75, 24));
        tabWidget->addTab(tabGestion, QString());
        tabCitas = new QWidget();
        tabCitas->setObjectName("tabCitas");
        pushButton_3 = new QPushButton(tabCitas);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(400, 120, 75, 24));
        tabWidget->addTab(tabCitas, QString());
        tabPagos = new QWidget();
        tabPagos->setObjectName("tabPagos");
        pushButton_4 = new QPushButton(tabPagos);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(320, 140, 75, 24));
        tabWidget->addTab(tabPagos, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(GymOperations);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GymOperations);
    } // setupUi

    void retranslateUi(QWidget *GymOperations)
    {
        GymOperations->setWindowTitle(QCoreApplication::translate("GymOperations", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("GymOperations", "atb1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInicio), QCoreApplication::translate("GymOperations", "Inicio", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GymOperations", "btn2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("GymOperations", "Gesti\303\263n", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GymOperations", "pag3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCitas), QCoreApplication::translate("GymOperations", "Citas", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GymOperations", "pag4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPagos), QCoreApplication::translate("GymOperations", "Pagos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GymOperations: public Ui_GymOperations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GYMOPERATIONS_H
