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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GymOperations
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabInicio;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtPersonCodeSearchIntro;
    QPushButton *btnCustomerSearchIntro;
    QPushButton *btnAllCustomers;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblWidCustomersIntro;
    QWidget *tabGestion;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_6;
    QCheckBox *checkBox_2;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *tabCitas;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit_10;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *comboBox_2;
    QCheckBox *checkBox_3;
    QTableWidget *tableWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *tabPagos;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_7;
    QDateTimeEdit *dateTimeEdit_2;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_9;
    QTableWidget *tableWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QWidget *GymOperations)
    {
        if (GymOperations->objectName().isEmpty())
            GymOperations->setObjectName("GymOperations");
        GymOperations->resize(855, 509);
        GymOperations->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
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
"	background-color: #ffd600;\n"
"	padding-top: 10%;\n"
"	padding-right: 20%;\n"
"	padding-bottom: 10%;\n"
"	padding-left: 20%;\n"
"	border: 1px solid black\n"
"}\n"
""));
        tabInicio = new QWidget();
        tabInicio->setObjectName("tabInicio");
        tabInicio->setStyleSheet(QString::fromUtf8("QWidget#tabInicio QTableWidget {\n"
"    background-color: #d1d1d1;\n"
"}\n"
"\n"
"QWidget#tabInicio QHeaderView::Section {\n"
"    background-color: #00baff;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 2%;\n"
"	font-size:16px;\n"
"	font-style: bold;\n"
"}\n"
"\n"
"QWidget#tabInicio QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"	margin-right: 20px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QWidget#tabInicio QLineEdit{\n"
"	padding-top: 1%;\n"
"	padding-bottom: 2%;\n"
"	padding-left: 5%;\n"
"	border: 1px solid #ffd600\n"
"}\n"
"\n"
"\n"
""));
        verticalLayout_3 = new QVBoxLayout(tabInicio);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        txtPersonCodeSearchIntro = new QLineEdit(tabInicio);
        txtPersonCodeSearchIntro->setObjectName("txtPersonCodeSearchIntro");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtPersonCodeSearchIntro->sizePolicy().hasHeightForWidth());
        txtPersonCodeSearchIntro->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        txtPersonCodeSearchIntro->setFont(font1);
        txtPersonCodeSearchIntro->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(txtPersonCodeSearchIntro);

        btnCustomerSearchIntro = new QPushButton(tabInicio);
        btnCustomerSearchIntro->setObjectName("btnCustomerSearchIntro");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnCustomerSearchIntro->sizePolicy().hasHeightForWidth());
        btnCustomerSearchIntro->setSizePolicy(sizePolicy1);
        btnCustomerSearchIntro->setFont(font1);

        horizontalLayout->addWidget(btnCustomerSearchIntro);

        btnAllCustomers = new QPushButton(tabInicio);
        btnAllCustomers->setObjectName("btnAllCustomers");
        sizePolicy1.setHeightForWidth(btnAllCustomers->sizePolicy().hasHeightForWidth());
        btnAllCustomers->setSizePolicy(sizePolicy1);
        btnAllCustomers->setFont(font1);

        horizontalLayout->addWidget(btnAllCustomers);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        tblWidCustomersIntro = new QTableWidget(tabInicio);
        if (tblWidCustomersIntro->columnCount() < 7)
            tblWidCustomersIntro->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblWidCustomersIntro->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tblWidCustomersIntro->setObjectName("tblWidCustomersIntro");
        tblWidCustomersIntro->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout_2->addWidget(tblWidCustomersIntro);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tabInicio, QString());
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        tabGestion->setStyleSheet(QString::fromUtf8("QWidget#tabGestion QLineEdit{\n"
"	padding-top: 2%;\n"
"	padding-bottom: 3%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width:200px;\n"
"	color: white;\n"
"	font-size: 16px;\n"
"	border: 1px solid #ffd600\n"
"}\n"
"\n"
"QWidget#tabGestion QDateEdit{\n"
"	padding-top: 2%;\n"
"	padding-bottom: 3%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width:200px;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	border: 1px solid #ffd600\n"
"}\n"
"\n"
"QWidget#tabGestion QCheckBox{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"QWidget#tabGestion QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"	margin-right: 20px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget#tabGestion QTableWidget{\n"
"	padding-left: 20px;\n"
"	background-color: #9BEC00;\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(tabGestion);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        lineEdit_2 = new QLineEdit(tabGestion);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMinimumSize(QSize(207, 0));
        QFont font2;
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(tabGestion);
        lineEdit_3->setObjectName("lineEdit_3");
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(tabGestion);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);
        lineEdit_4->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(lineEdit_4);

        dateEdit = new QDateEdit(tabGestion);
        dateEdit->setObjectName("dateEdit");

        verticalLayout_4->addWidget(dateEdit);

        lineEdit_6 = new QLineEdit(tabGestion);
        lineEdit_6->setObjectName("lineEdit_6");
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);
        lineEdit_6->setMinimumSize(QSize(207, 0));
        lineEdit_6->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(lineEdit_6);

        checkBox_2 = new QCheckBox(tabGestion);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout_4->addWidget(checkBox_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        tableWidget_2 = new QTableWidget(tabGestion);
        tableWidget_2->setObjectName("tableWidget_2");

        horizontalLayout_3->addWidget(tableWidget_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_2 = new QPushButton(tabGestion);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(tabGestion);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(tabGestion);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_2->addWidget(pushButton_6);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tabGestion, QString());
        tabCitas = new QWidget();
        tabCitas->setObjectName("tabCitas");
        tabCitas->setStyleSheet(QString::fromUtf8("QWidget#tabCitas QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"	margin-right: 20px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"QWidget#tabCitas QLineEdit{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width:200px;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"QWidget#tabCitas QCheckBox{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 60%;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"\n"
"QWidget#tabCitas QTableWidget{\n"
"	padding-left: 20px;\n"
"	background-color: #9BEC00;\n"
"}\n"
""));
        verticalLayout_9 = new QVBoxLayout(tabCitas);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        lineEdit_10 = new QLineEdit(tabCitas);
        lineEdit_10->setObjectName("lineEdit_10");
        sizePolicy.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(lineEdit_10);

        dateTimeEdit = new QDateTimeEdit(tabCitas);
        dateTimeEdit->setObjectName("dateTimeEdit");
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(dateTimeEdit);

        comboBox_2 = new QComboBox(tabCitas);
        comboBox_2->setObjectName("comboBox_2");

        verticalLayout_8->addWidget(comboBox_2);

        checkBox_3 = new QCheckBox(tabCitas);
        checkBox_3->setObjectName("checkBox_3");
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(checkBox_3);


        horizontalLayout_8->addLayout(verticalLayout_8);

        tableWidget_4 = new QTableWidget(tabCitas);
        tableWidget_4->setObjectName("tableWidget_4");

        horizontalLayout_8->addWidget(tableWidget_4);


        verticalLayout_9->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pushButton_3 = new QPushButton(tabCitas);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_7->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(tabCitas);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_7->addWidget(pushButton_4);


        verticalLayout_9->addLayout(horizontalLayout_7);

        tabWidget->addTab(tabCitas, QString());
        tabPagos = new QWidget();
        tabPagos->setObjectName("tabPagos");
        tabPagos->setStyleSheet(QString::fromUtf8("QWidget#tabPagos QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"	margin-right: 20px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget#tabPagos QLineEdit{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width:200px;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"QWidget#tabPagos QCheckBox{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 60%;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"\n"
"QWidget#tabPagos QTableWidget{\n"
"	padding-left: 20px;\n"
"	background-color: #9BEC00;\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_2 = new QGridLayout(tabPagos);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(9);
        verticalLayout_6->setObjectName("verticalLayout_6");
        lineEdit_7 = new QLineEdit(tabPagos);
        lineEdit_7->setObjectName("lineEdit_7");
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);
        lineEdit_7->setMinimumSize(QSize(207, 0));

        verticalLayout_6->addWidget(lineEdit_7);

        dateTimeEdit_2 = new QDateTimeEdit(tabPagos);
        dateTimeEdit_2->setObjectName("dateTimeEdit_2");
        sizePolicy.setHeightForWidth(dateTimeEdit_2->sizePolicy().hasHeightForWidth());
        dateTimeEdit_2->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(dateTimeEdit_2);

        comboBox = new QComboBox(tabPagos);
        comboBox->setObjectName("comboBox");

        verticalLayout_6->addWidget(comboBox);

        spinBox = new QSpinBox(tabPagos);
        spinBox->setObjectName("spinBox");
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(spinBox);

        checkBox = new QCheckBox(tabPagos);
        checkBox->setObjectName("checkBox");
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(checkBox);

        lineEdit_9 = new QLineEdit(tabPagos);
        lineEdit_9->setObjectName("lineEdit_9");
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(lineEdit_9);


        horizontalLayout_4->addLayout(verticalLayout_6);

        tableWidget_3 = new QTableWidget(tabPagos);
        tableWidget_3->setObjectName("tableWidget_3");

        horizontalLayout_4->addWidget(tableWidget_3);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton_7 = new QPushButton(tabPagos);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout_6->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(tabPagos);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout_6->addWidget(pushButton_8);


        verticalLayout_7->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tabPagos, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(GymOperations);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GymOperations);
    } // setupUi

    void retranslateUi(QWidget *GymOperations)
    {
        GymOperations->setWindowTitle(QCoreApplication::translate("GymOperations", "Form", nullptr));
        txtPersonCodeSearchIntro->setPlaceholderText(QCoreApplication::translate("GymOperations", "C\303\263digo:", nullptr));
        btnCustomerSearchIntro->setText(QCoreApplication::translate("GymOperations", "Buscar Cliente", nullptr));
        btnAllCustomers->setText(QCoreApplication::translate("GymOperations", "Listar Clientes", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblWidCustomersIntro->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GymOperations", "C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblWidCustomersIntro->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GymOperations", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblWidCustomersIntro->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GymOperations", "Peso", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblWidCustomersIntro->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GymOperations", "Fecha Inicio", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblWidCustomersIntro->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GymOperations", "Rol", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblWidCustomersIntro->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GymOperations", "Fecha Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblWidCustomersIntro->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GymOperations", "Fecha Caducaci\303\263n", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInicio), QCoreApplication::translate("GymOperations", "Inicio", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("GymOperations", "Nombre:", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("GymOperations", "Apellido:", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("GymOperations", "Peso:", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("GymOperations", "yyyy-MM-dd", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("GymOperations", "C\303\263digo:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("GymOperations", "Cliente Nuevo?", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GymOperations", "Guardar", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GymOperations", "Cancelar", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GymOperations", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("GymOperations", "Gesti\303\263n", nullptr));
        checkBox_3->setText(QCoreApplication::translate("GymOperations", "Nueva Cita", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GymOperations", "Guardar", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GymOperations", "Cancelar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCitas), QCoreApplication::translate("GymOperations", "Citas", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("GymOperations", "C\303\263digo:", nullptr));
        checkBox->setText(QCoreApplication::translate("GymOperations", "Abono", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("GymOperations", "Cantidad a abonar", nullptr));
        pushButton_7->setText(QCoreApplication::translate("GymOperations", "Aceptar", nullptr));
        pushButton_8->setText(QCoreApplication::translate("GymOperations", "Cancelar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPagos), QCoreApplication::translate("GymOperations", "Pagos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GymOperations: public Ui_GymOperations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GYMOPERATIONS_H
