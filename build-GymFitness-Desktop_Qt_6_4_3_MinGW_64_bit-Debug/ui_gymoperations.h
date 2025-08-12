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
    QLineEdit *txtManageName;
    QLineEdit *txtManageLastName;
    QLineEdit *txtManageWeight;
    QDateEdit *manageInscriptionDate;
    QLineEdit *txtManageCode;
    QCheckBox *cbxManageNew;
    QTableWidget *tblWidManage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnManageSave;
    QPushButton *btnManageCancel;
    QPushButton *btnManageSearch;
    QWidget *tabCitas;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_11;
    QTableWidget *tblWidAppointInvoice;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btnAppointNewInvoice;
    QPushButton *btnAppointAllInvoices;
    QPushButton *btnAppointSearchInvoice;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *appointInvoiceNumber;
    QLineEdit *txtAppointUserCode;
    QDateTimeEdit *appointDate;
    QLineEdit *appointNumber;
    QComboBox *combxAppointService;
    QSpinBox *sbAppointQuantity;
    QLineEdit *appointPayAmmount;
    QCheckBox *cbxAppointNew;
    QTableWidget *tblWidAppointLine;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnAppointSaveAll;
    QPushButton *btnAppointAdd;
    QPushButton *btnSaveAppoint;
    QPushButton *btnAppointCancel;
    QWidget *tabPagos;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tblWidPaymentInvoice;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnPaymentNewInvoice;
    QPushButton *btnPaymentAllInvoices;
    QPushButton *btnPaymentSearchInvoice;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *invoiceNumber;
    QLineEdit *txtPaymentUserCode;
    QLineEdit *invoiceInfoLineNumber;
    QDateEdit *paymentDatePay;
    QComboBox *cbxPaymentPackage;
    QSpinBox *sbPaymentQuantity;
    QLineEdit *txtPaymentAmount;
    QCheckBox *checkPaymentPartial;
    QLineEdit *txtPaymentPartialPay;
    QTableWidget *tblWidPaymentLine;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnPaymentSaveAll;
    QPushButton *btnPaymentAddLine;
    QPushButton *btnSaveLine;
    QPushButton *btnPaymentCancel;
    QWidget *tabFacturas;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QTableWidget *tblAllInvoices;
    QTableWidget *tblInvoiceLines;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btnAllInvoicesReport;
    QPushButton *btnGenerateReport;
    QWidget *tabCorreos;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *txtEmailAddress;
    QTableWidget *tblEmailFiles;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *btnSendEmail;
    QPushButton *btnListFiles;

    void setupUi(QWidget *GymOperations)
    {
        if (GymOperations->objectName().isEmpty())
            GymOperations->setObjectName("GymOperations");
        GymOperations->setWindowModality(Qt::NonModal);
        GymOperations->resize(1092, 645);
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
"\n"
""));
        tabInicio = new QWidget();
        tabInicio->setObjectName("tabInicio");
        tabInicio->setStyleSheet(QString::fromUtf8("QWidget#tabInicio QTableWidget {\n"
"    background-color: #d1d1d1;\n"
"}\n"
"\n"
"\n"
"QWidget#tabInicio QHeaderView::Section {\n"
"    background-color: #00baff;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 2%;\n"
"	font-size:16px;\n"
"	font-style: bold;\n"
"}\n"
"\n"
"\n"
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
"	border: 1px solid #ffd600;\n"
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
"	background-color: #d1d1d1;\n"
"}\n"
"\n"
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
        txtManageName = new QLineEdit(tabGestion);
        txtManageName->setObjectName("txtManageName");
        sizePolicy.setHeightForWidth(txtManageName->sizePolicy().hasHeightForWidth());
        txtManageName->setSizePolicy(sizePolicy);
        txtManageName->setMinimumSize(QSize(207, 0));
        QFont font2;
        txtManageName->setFont(font2);
        txtManageName->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(txtManageName);

        txtManageLastName = new QLineEdit(tabGestion);
        txtManageLastName->setObjectName("txtManageLastName");
        sizePolicy.setHeightForWidth(txtManageLastName->sizePolicy().hasHeightForWidth());
        txtManageLastName->setSizePolicy(sizePolicy);
        txtManageLastName->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(txtManageLastName);

        txtManageWeight = new QLineEdit(tabGestion);
        txtManageWeight->setObjectName("txtManageWeight");
        sizePolicy.setHeightForWidth(txtManageWeight->sizePolicy().hasHeightForWidth());
        txtManageWeight->setSizePolicy(sizePolicy);
        txtManageWeight->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(txtManageWeight);

        manageInscriptionDate = new QDateEdit(tabGestion);
        manageInscriptionDate->setObjectName("manageInscriptionDate");

        verticalLayout_4->addWidget(manageInscriptionDate);

        txtManageCode = new QLineEdit(tabGestion);
        txtManageCode->setObjectName("txtManageCode");
        sizePolicy.setHeightForWidth(txtManageCode->sizePolicy().hasHeightForWidth());
        txtManageCode->setSizePolicy(sizePolicy);
        txtManageCode->setMinimumSize(QSize(207, 0));
        txtManageCode->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(txtManageCode);

        cbxManageNew = new QCheckBox(tabGestion);
        cbxManageNew->setObjectName("cbxManageNew");

        verticalLayout_4->addWidget(cbxManageNew);


        horizontalLayout_3->addLayout(verticalLayout_4);

        tblWidManage = new QTableWidget(tabGestion);
        if (tblWidManage->columnCount() < 7)
            tblWidManage->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblWidManage->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        tblWidManage->setObjectName("tblWidManage");

        horizontalLayout_3->addWidget(tblWidManage);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnManageSave = new QPushButton(tabGestion);
        btnManageSave->setObjectName("btnManageSave");

        horizontalLayout_2->addWidget(btnManageSave);

        btnManageCancel = new QPushButton(tabGestion);
        btnManageCancel->setObjectName("btnManageCancel");

        horizontalLayout_2->addWidget(btnManageCancel);

        btnManageSearch = new QPushButton(tabGestion);
        btnManageSearch->setObjectName("btnManageSearch");

        horizontalLayout_2->addWidget(btnManageSearch);


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
"\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget#tabCitas QLineEdit{\n"
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
"\n"
"\n"
"QWidget#tabCitas QCheckBox{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 60%;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	border: 1px solid #ffd600;\n"
"}\n"
"\n"
"\n"
"QWidget#tabCitas QTableWidget{\n"
"	background-color: #d1d1d1;\n"
"}\n"
"\n"
"QWidget#tabCitas QDateTimeEdit{\n"
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
"\n"
"QWidget#tabCitas QSpinBox{\n"
"	padding-top: 2%;\n"
"	p"
                        "adding-bottom: 3%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width: 200px;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	border: 1px solid #ffd600;\n"
"}\n"
"\n"
"\n"
"QWidget#tabCitas QComboBox{\n"
"	padding-left: 20;\n"
"	height: 30;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QWidget#tabCitas QComboBox::open {\n"
"	background-color: yellow;\n"
"}\n"
"\n"
"QWidget#tabCitas QComboBox QListView {\n"
"	background-color: white;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(tabCitas);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        tblWidAppointInvoice = new QTableWidget(tabCitas);
        if (tblWidAppointInvoice->columnCount() < 6)
            tblWidAppointInvoice->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblWidAppointInvoice->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblWidAppointInvoice->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblWidAppointInvoice->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblWidAppointInvoice->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblWidAppointInvoice->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblWidAppointInvoice->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        tblWidAppointInvoice->setObjectName("tblWidAppointInvoice");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tblWidAppointInvoice->sizePolicy().hasHeightForWidth());
        tblWidAppointInvoice->setSizePolicy(sizePolicy2);

        verticalLayout_11->addWidget(tblWidAppointInvoice);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(-1, 0, -1, -1);
        btnAppointNewInvoice = new QPushButton(tabCitas);
        btnAppointNewInvoice->setObjectName("btnAppointNewInvoice");

        horizontalLayout_10->addWidget(btnAppointNewInvoice);

        btnAppointAllInvoices = new QPushButton(tabCitas);
        btnAppointAllInvoices->setObjectName("btnAppointAllInvoices");

        horizontalLayout_10->addWidget(btnAppointAllInvoices);

        btnAppointSearchInvoice = new QPushButton(tabCitas);
        btnAppointSearchInvoice->setObjectName("btnAppointSearchInvoice");

        horizontalLayout_10->addWidget(btnAppointSearchInvoice);


        verticalLayout_11->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        appointInvoiceNumber = new QLineEdit(tabCitas);
        appointInvoiceNumber->setObjectName("appointInvoiceNumber");
        sizePolicy.setHeightForWidth(appointInvoiceNumber->sizePolicy().hasHeightForWidth());
        appointInvoiceNumber->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(appointInvoiceNumber);

        txtAppointUserCode = new QLineEdit(tabCitas);
        txtAppointUserCode->setObjectName("txtAppointUserCode");
        sizePolicy.setHeightForWidth(txtAppointUserCode->sizePolicy().hasHeightForWidth());
        txtAppointUserCode->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(txtAppointUserCode);

        appointDate = new QDateTimeEdit(tabCitas);
        appointDate->setObjectName("appointDate");
        sizePolicy.setHeightForWidth(appointDate->sizePolicy().hasHeightForWidth());
        appointDate->setSizePolicy(sizePolicy);
        appointDate->setCalendarPopup(true);

        verticalLayout_8->addWidget(appointDate);

        appointNumber = new QLineEdit(tabCitas);
        appointNumber->setObjectName("appointNumber");
        sizePolicy.setHeightForWidth(appointNumber->sizePolicy().hasHeightForWidth());
        appointNumber->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(appointNumber);

        combxAppointService = new QComboBox(tabCitas);
        combxAppointService->setObjectName("combxAppointService");

        verticalLayout_8->addWidget(combxAppointService);

        sbAppointQuantity = new QSpinBox(tabCitas);
        sbAppointQuantity->setObjectName("sbAppointQuantity");

        verticalLayout_8->addWidget(sbAppointQuantity);

        appointPayAmmount = new QLineEdit(tabCitas);
        appointPayAmmount->setObjectName("appointPayAmmount");
        sizePolicy.setHeightForWidth(appointPayAmmount->sizePolicy().hasHeightForWidth());
        appointPayAmmount->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(appointPayAmmount);

        cbxAppointNew = new QCheckBox(tabCitas);
        cbxAppointNew->setObjectName("cbxAppointNew");
        sizePolicy.setHeightForWidth(cbxAppointNew->sizePolicy().hasHeightForWidth());
        cbxAppointNew->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(cbxAppointNew);


        horizontalLayout_8->addLayout(verticalLayout_8);

        tblWidAppointLine = new QTableWidget(tabCitas);
        if (tblWidAppointLine->columnCount() < 6)
            tblWidAppointLine->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblWidAppointLine->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblWidAppointLine->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblWidAppointLine->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblWidAppointLine->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tblWidAppointLine->setHorizontalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tblWidAppointLine->setHorizontalHeaderItem(5, __qtablewidgetitem25);
        tblWidAppointLine->setObjectName("tblWidAppointLine");

        horizontalLayout_8->addWidget(tblWidAppointLine);


        verticalLayout_11->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnAppointSaveAll = new QPushButton(tabCitas);
        btnAppointSaveAll->setObjectName("btnAppointSaveAll");

        horizontalLayout_7->addWidget(btnAppointSaveAll);

        btnAppointAdd = new QPushButton(tabCitas);
        btnAppointAdd->setObjectName("btnAppointAdd");

        horizontalLayout_7->addWidget(btnAppointAdd);

        btnSaveAppoint = new QPushButton(tabCitas);
        btnSaveAppoint->setObjectName("btnSaveAppoint");

        horizontalLayout_7->addWidget(btnSaveAppoint);

        btnAppointCancel = new QPushButton(tabCitas);
        btnAppointCancel->setObjectName("btnAppointCancel");

        horizontalLayout_7->addWidget(btnAppointCancel);


        verticalLayout_11->addLayout(horizontalLayout_7);


        verticalLayout_9->addLayout(verticalLayout_11);

        tabWidget->addTab(tabCitas, QString());
        tabPagos = new QWidget();
        tabPagos->setObjectName("tabPagos");
        tabPagos->setStyleSheet(QString::fromUtf8("QWidget#tabPagos QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"	\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget#tabPagos QLineEdit{\n"
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
"QWidget#tabPagos QCheckBox{\n"
"	padding-top: 3%;\n"
"	padding-bottom: 4%;\n"
"	padding-left: 5%;\n"
"	width: 60%;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	border: 1px solid #ffd600;\n"
"}\n"
"\n"
"\n"
"QWidget#tabPagos QTableWidget{\n"
"	background-color: #d1d1d1;\n"
"}\n"
"\n"
"\n"
"QWidget#tabPagos QDateTimeEdit{\n"
"	padding-top: 2%;\n"
"	padding-bottom: 3%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width: 200px;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	border: 1px solid #ffd600;\n"
"}\n"
"\n"
"QWidget#tabPagos QSpinBox{\n"
"	padding-top: 2%;\n"
"	padding-"
                        "bottom: 3%;\n"
"	padding-left: 5%;\n"
"	width: 100%;\n"
"	min-width: 200px;\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	border: 1px solid #ffd600;\n"
"}\n"
"\n"
"\n"
"QWidget#tabPagos QComboBox{\n"
"	padding-left: 20;\n"
"	height: 30;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QWidget#tabPagos QComboBox::open {\n"
"	background-color: yellow;\n"
"}\n"
"\n"
"QWidget#tabPagos QComboBox QListView {\n"
"	background-color: white;\n"
"}"));
        gridLayout_2 = new QGridLayout(tabPagos);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        tblWidPaymentInvoice = new QTableWidget(tabPagos);
        if (tblWidPaymentInvoice->columnCount() < 6)
            tblWidPaymentInvoice->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tblWidPaymentInvoice->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tblWidPaymentInvoice->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tblWidPaymentInvoice->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tblWidPaymentInvoice->setHorizontalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tblWidPaymentInvoice->setHorizontalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tblWidPaymentInvoice->setHorizontalHeaderItem(5, __qtablewidgetitem31);
        tblWidPaymentInvoice->setObjectName("tblWidPaymentInvoice");
        sizePolicy2.setHeightForWidth(tblWidPaymentInvoice->sizePolicy().hasHeightForWidth());
        tblWidPaymentInvoice->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(tblWidPaymentInvoice);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        btnPaymentNewInvoice = new QPushButton(tabPagos);
        btnPaymentNewInvoice->setObjectName("btnPaymentNewInvoice");

        horizontalLayout_5->addWidget(btnPaymentNewInvoice);

        btnPaymentAllInvoices = new QPushButton(tabPagos);
        btnPaymentAllInvoices->setObjectName("btnPaymentAllInvoices");

        horizontalLayout_5->addWidget(btnPaymentAllInvoices);

        btnPaymentSearchInvoice = new QPushButton(tabPagos);
        btnPaymentSearchInvoice->setObjectName("btnPaymentSearchInvoice");

        horizontalLayout_5->addWidget(btnPaymentSearchInvoice);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        invoiceNumber = new QLineEdit(tabPagos);
        invoiceNumber->setObjectName("invoiceNumber");
        sizePolicy.setHeightForWidth(invoiceNumber->sizePolicy().hasHeightForWidth());
        invoiceNumber->setSizePolicy(sizePolicy);
        invoiceNumber->setReadOnly(false);

        verticalLayout_6->addWidget(invoiceNumber);

        txtPaymentUserCode = new QLineEdit(tabPagos);
        txtPaymentUserCode->setObjectName("txtPaymentUserCode");
        sizePolicy.setHeightForWidth(txtPaymentUserCode->sizePolicy().hasHeightForWidth());
        txtPaymentUserCode->setSizePolicy(sizePolicy);
        txtPaymentUserCode->setMinimumSize(QSize(207, 0));

        verticalLayout_6->addWidget(txtPaymentUserCode);

        invoiceInfoLineNumber = new QLineEdit(tabPagos);
        invoiceInfoLineNumber->setObjectName("invoiceInfoLineNumber");
        sizePolicy.setHeightForWidth(invoiceInfoLineNumber->sizePolicy().hasHeightForWidth());
        invoiceInfoLineNumber->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(invoiceInfoLineNumber);

        paymentDatePay = new QDateEdit(tabPagos);
        paymentDatePay->setObjectName("paymentDatePay");

        verticalLayout_6->addWidget(paymentDatePay);

        cbxPaymentPackage = new QComboBox(tabPagos);
        cbxPaymentPackage->setObjectName("cbxPaymentPackage");

        verticalLayout_6->addWidget(cbxPaymentPackage);

        sbPaymentQuantity = new QSpinBox(tabPagos);
        sbPaymentQuantity->setObjectName("sbPaymentQuantity");
        sizePolicy.setHeightForWidth(sbPaymentQuantity->sizePolicy().hasHeightForWidth());
        sbPaymentQuantity->setSizePolicy(sizePolicy);
        sbPaymentQuantity->setMinimumSize(QSize(207, 0));

        verticalLayout_6->addWidget(sbPaymentQuantity);

        txtPaymentAmount = new QLineEdit(tabPagos);
        txtPaymentAmount->setObjectName("txtPaymentAmount");
        sizePolicy.setHeightForWidth(txtPaymentAmount->sizePolicy().hasHeightForWidth());
        txtPaymentAmount->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(txtPaymentAmount);

        checkPaymentPartial = new QCheckBox(tabPagos);
        checkPaymentPartial->setObjectName("checkPaymentPartial");
        sizePolicy.setHeightForWidth(checkPaymentPartial->sizePolicy().hasHeightForWidth());
        checkPaymentPartial->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(checkPaymentPartial);

        txtPaymentPartialPay = new QLineEdit(tabPagos);
        txtPaymentPartialPay->setObjectName("txtPaymentPartialPay");
        sizePolicy.setHeightForWidth(txtPaymentPartialPay->sizePolicy().hasHeightForWidth());
        txtPaymentPartialPay->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(txtPaymentPartialPay);


        horizontalLayout_4->addLayout(verticalLayout_6);

        tblWidPaymentLine = new QTableWidget(tabPagos);
        if (tblWidPaymentLine->columnCount() < 6)
            tblWidPaymentLine->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tblWidPaymentLine->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tblWidPaymentLine->setHorizontalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tblWidPaymentLine->setHorizontalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tblWidPaymentLine->setHorizontalHeaderItem(3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tblWidPaymentLine->setHorizontalHeaderItem(4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tblWidPaymentLine->setHorizontalHeaderItem(5, __qtablewidgetitem37);
        tblWidPaymentLine->setObjectName("tblWidPaymentLine");

        horizontalLayout_4->addWidget(tblWidPaymentLine);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btnPaymentSaveAll = new QPushButton(tabPagos);
        btnPaymentSaveAll->setObjectName("btnPaymentSaveAll");

        horizontalLayout_6->addWidget(btnPaymentSaveAll);

        btnPaymentAddLine = new QPushButton(tabPagos);
        btnPaymentAddLine->setObjectName("btnPaymentAddLine");

        horizontalLayout_6->addWidget(btnPaymentAddLine);

        btnSaveLine = new QPushButton(tabPagos);
        btnSaveLine->setObjectName("btnSaveLine");

        horizontalLayout_6->addWidget(btnSaveLine);

        btnPaymentCancel = new QPushButton(tabPagos);
        btnPaymentCancel->setObjectName("btnPaymentCancel");

        horizontalLayout_6->addWidget(btnPaymentCancel);


        verticalLayout_7->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tabPagos, QString());
        tabFacturas = new QWidget();
        tabFacturas->setObjectName("tabFacturas");
        tabFacturas->setStyleSheet(QString::fromUtf8("QWidget#tabFacturas QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"QWidget#tabFacturas QTableWidget{\n"
"	background-color: #d1d1d1;\n"
"}\n"
""));
        gridLayout_3 = new QGridLayout(tabFacturas);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(-1, -1, -1, 10);
        tblAllInvoices = new QTableWidget(tabFacturas);
        if (tblAllInvoices->columnCount() < 5)
            tblAllInvoices->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tblAllInvoices->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tblAllInvoices->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tblAllInvoices->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tblAllInvoices->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tblAllInvoices->setHorizontalHeaderItem(4, __qtablewidgetitem42);
        tblAllInvoices->setObjectName("tblAllInvoices");
        tblAllInvoices->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_9->addWidget(tblAllInvoices);

        tblInvoiceLines = new QTableWidget(tabFacturas);
        if (tblInvoiceLines->columnCount() < 5)
            tblInvoiceLines->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tblInvoiceLines->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tblInvoiceLines->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tblInvoiceLines->setHorizontalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tblInvoiceLines->setHorizontalHeaderItem(3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tblInvoiceLines->setHorizontalHeaderItem(4, __qtablewidgetitem47);
        tblInvoiceLines->setObjectName("tblInvoiceLines");

        horizontalLayout_9->addWidget(tblInvoiceLines);


        gridLayout_3->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 5, -1, 0);
        btnAllInvoicesReport = new QPushButton(tabFacturas);
        btnAllInvoicesReport->setObjectName("btnAllInvoicesReport");
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        btnAllInvoicesReport->setFont(font3);

        horizontalLayout_11->addWidget(btnAllInvoicesReport);

        btnGenerateReport = new QPushButton(tabFacturas);
        btnGenerateReport->setObjectName("btnGenerateReport");
        btnGenerateReport->setFont(font3);

        horizontalLayout_11->addWidget(btnGenerateReport);


        gridLayout_3->addLayout(horizontalLayout_11, 1, 0, 1, 1);

        tabWidget->addTab(tabFacturas, QString());
        tabCorreos = new QWidget();
        tabCorreos->setObjectName("tabCorreos");
        tabCorreos->setStyleSheet(QString::fromUtf8("QWidget#tabCorreos QPushButton {\n"
"    background-color: #ffd600;\n"
"	padding-top: 2%;\n"
"	padding-bottom: 4%;\n"
"	padding-right: 7%;\n"
"	padding-left: 7%;\n"
"	\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget#tabCorreos QLineEdit{\n"
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
"\n"
"\n"
"QWidget#tabCorreos QTableWidget{\n"
"	background-color: #d1d1d1;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        verticalLayout_12 = new QVBoxLayout(tabCorreos);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        txtEmailAddress = new QLineEdit(tabCorreos);
        txtEmailAddress->setObjectName("txtEmailAddress");

        verticalLayout_10->addWidget(txtEmailAddress);

        tblEmailFiles = new QTableWidget(tabCorreos);
        if (tblEmailFiles->columnCount() < 1)
            tblEmailFiles->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tblEmailFiles->setHorizontalHeaderItem(0, __qtablewidgetitem48);
        tblEmailFiles->setObjectName("tblEmailFiles");

        verticalLayout_10->addWidget(tblEmailFiles);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 10, -1, 10);
        btnSendEmail = new QPushButton(tabCorreos);
        btnSendEmail->setObjectName("btnSendEmail");

        horizontalLayout_12->addWidget(btnSendEmail);

        btnListFiles = new QPushButton(tabCorreos);
        btnListFiles->setObjectName("btnListFiles");

        horizontalLayout_12->addWidget(btnListFiles);


        verticalLayout_10->addLayout(horizontalLayout_12);


        verticalLayout_12->addLayout(verticalLayout_10);

        tabWidget->addTab(tabCorreos, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(GymOperations);

        tabWidget->setCurrentIndex(5);


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
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GymOperations", "Fecha L\303\255mite", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInicio), QCoreApplication::translate("GymOperations", "Inicio", nullptr));
        txtManageName->setPlaceholderText(QCoreApplication::translate("GymOperations", "Nombre:", nullptr));
        txtManageLastName->setPlaceholderText(QCoreApplication::translate("GymOperations", "Apellido:", nullptr));
        txtManageWeight->setPlaceholderText(QCoreApplication::translate("GymOperations", "Peso:", nullptr));
        manageInscriptionDate->setDisplayFormat(QCoreApplication::translate("GymOperations", "yyyy-MM-dd", nullptr));
        txtManageCode->setPlaceholderText(QCoreApplication::translate("GymOperations", "C\303\263digo:", nullptr));
        cbxManageNew->setText(QCoreApplication::translate("GymOperations", "Cliente Nuevo?", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblWidManage->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("GymOperations", "C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblWidManage->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("GymOperations", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblWidManage->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("GymOperations", "Peso", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblWidManage->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("GymOperations", "Fecha Inicio", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblWidManage->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("GymOperations", "Rol", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblWidManage->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("GymOperations", "Fecha Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblWidManage->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("GymOperations", "Fecha L\303\255mite", nullptr));
        btnManageSave->setText(QCoreApplication::translate("GymOperations", "Guardar", nullptr));
        btnManageCancel->setText(QCoreApplication::translate("GymOperations", "Cancelar", nullptr));
        btnManageSearch->setText(QCoreApplication::translate("GymOperations", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("GymOperations", "Gesti\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblWidAppointInvoice->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("GymOperations", "Id Cabecera", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblWidAppointInvoice->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("GymOperations", "Fecha de  Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblWidAppointInvoice->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("GymOperations", "Codigo Usuario", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblWidAppointInvoice->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("GymOperations", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblWidAppointInvoice->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("GymOperations", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblWidAppointInvoice->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("GymOperations", "Abono", nullptr));
        btnAppointNewInvoice->setText(QCoreApplication::translate("GymOperations", "Nueva Factura", nullptr));
        btnAppointAllInvoices->setText(QCoreApplication::translate("GymOperations", "Todas las Facturas", nullptr));
        btnAppointSearchInvoice->setText(QCoreApplication::translate("GymOperations", "Buscar Factura", nullptr));
        appointInvoiceNumber->setPlaceholderText(QCoreApplication::translate("GymOperations", "Factura N\302\260 10", nullptr));
        txtAppointUserCode->setPlaceholderText(QCoreApplication::translate("GymOperations", "C\303\263digo del Cliente", nullptr));
        appointNumber->setPlaceholderText(QCoreApplication::translate("GymOperations", "Cita N\302\260 22", nullptr));
        appointPayAmmount->setPlaceholderText(QCoreApplication::translate("GymOperations", "$00.00", nullptr));
        cbxAppointNew->setText(QCoreApplication::translate("GymOperations", "Nueva Cita", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblWidAppointLine->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("GymOperations", "Id Cita", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblWidAppointLine->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("GymOperations", "Servicio", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tblWidAppointLine->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("GymOperations", "N\303\272mero de Sesiones", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tblWidAppointLine->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("GymOperations", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tblWidAppointLine->horizontalHeaderItem(4);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("GymOperations", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tblWidAppointLine->horizontalHeaderItem(5);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("GymOperations", "Fecha Sesi\303\263n", nullptr));
        btnAppointSaveAll->setText(QCoreApplication::translate("GymOperations", "Guardar Todo", nullptr));
        btnAppointAdd->setText(QCoreApplication::translate("GymOperations", "Agregar Cita", nullptr));
        btnSaveAppoint->setText(QCoreApplication::translate("GymOperations", "Guardar Cita", nullptr));
        btnAppointCancel->setText(QCoreApplication::translate("GymOperations", "Cancelar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCitas), QCoreApplication::translate("GymOperations", "Citas", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tblWidPaymentInvoice->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("GymOperations", "Id Cabecera", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tblWidPaymentInvoice->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("GymOperations", "Fecha de Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tblWidPaymentInvoice->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("GymOperations", "Codigo Usuario", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tblWidPaymentInvoice->horizontalHeaderItem(3);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("GymOperations", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tblWidPaymentInvoice->horizontalHeaderItem(4);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("GymOperations", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tblWidPaymentInvoice->horizontalHeaderItem(5);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("GymOperations", "Abono", nullptr));
        btnPaymentNewInvoice->setText(QCoreApplication::translate("GymOperations", "Nueva Factura", nullptr));
        btnPaymentAllInvoices->setText(QCoreApplication::translate("GymOperations", "Todas las Facturas", nullptr));
        btnPaymentSearchInvoice->setText(QCoreApplication::translate("GymOperations", "Buscar Factura", nullptr));
        invoiceNumber->setPlaceholderText(QCoreApplication::translate("GymOperations", "Factura N\302\260 10 ", nullptr));
        txtPaymentUserCode->setPlaceholderText(QCoreApplication::translate("GymOperations", "C\303\263digo del cliente:", nullptr));
        invoiceInfoLineNumber->setPlaceholderText(QCoreApplication::translate("GymOperations", "Detalle N\302\260 22", nullptr));
        paymentDatePay->setDisplayFormat(QCoreApplication::translate("GymOperations", "yyyy/MM/dd", nullptr));
        txtPaymentAmount->setPlaceholderText(QCoreApplication::translate("GymOperations", "$00.00", nullptr));
        checkPaymentPartial->setText(QCoreApplication::translate("GymOperations", "Abono", nullptr));
        txtPaymentPartialPay->setPlaceholderText(QCoreApplication::translate("GymOperations", "Cantidad a abonar", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tblWidPaymentLine->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("GymOperations", "Id Detalle", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tblWidPaymentLine->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("GymOperations", "Paquete", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tblWidPaymentLine->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("GymOperations", "Cantidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tblWidPaymentLine->horizontalHeaderItem(3);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("GymOperations", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tblWidPaymentLine->horizontalHeaderItem(4);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("GymOperations", "Fecha de Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tblWidPaymentLine->horizontalHeaderItem(5);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("GymOperations", "Fecha L\303\255mite", nullptr));
        btnPaymentSaveAll->setText(QCoreApplication::translate("GymOperations", "Guardar Todo", nullptr));
        btnPaymentAddLine->setText(QCoreApplication::translate("GymOperations", "Agregar Detalle", nullptr));
        btnSaveLine->setText(QCoreApplication::translate("GymOperations", "Guardar Detalle", nullptr));
        btnPaymentCancel->setText(QCoreApplication::translate("GymOperations", "Cancelar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPagos), QCoreApplication::translate("GymOperations", "Pagos", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tblAllInvoices->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("GymOperations", "Id Cabecera", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tblAllInvoices->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("GymOperations", "Fecha de Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tblAllInvoices->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("GymOperations", "C\303\263digo de Usuario", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tblAllInvoices->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("GymOperations", "Nombres", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tblAllInvoices->horizontalHeaderItem(4);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("GymOperations", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tblInvoiceLines->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("GymOperations", "Id Detalle", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tblInvoiceLines->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("GymOperations", "Total Detalle", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tblInvoiceLines->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("GymOperations", "Detalle", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tblInvoiceLines->horizontalHeaderItem(3);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("GymOperations", "Fecha", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tblInvoiceLines->horizontalHeaderItem(4);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("GymOperations", "Usuario", nullptr));
        btnAllInvoicesReport->setText(QCoreApplication::translate("GymOperations", "Todas las Facturas", nullptr));
        btnGenerateReport->setText(QCoreApplication::translate("GymOperations", "Generar PDF de la Factura", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabFacturas), QCoreApplication::translate("GymOperations", "Facturas", nullptr));
        txtEmailAddress->setPlaceholderText(QCoreApplication::translate("GymOperations", "Correo: ", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tblEmailFiles->horizontalHeaderItem(0);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("GymOperations", "Archivo", nullptr));
        btnSendEmail->setText(QCoreApplication::translate("GymOperations", "Enviar Correo", nullptr));
        btnListFiles->setText(QCoreApplication::translate("GymOperations", "Seleccionar Archivos", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCorreos), QCoreApplication::translate("GymOperations", "Correos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GymOperations: public Ui_GymOperations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GYMOPERATIONS_H
