/********************************************************************************
** Form generated from reading UI file 'dialogappointsview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAPPOINTSVIEW_H
#define UI_DIALOGAPPOINTSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogAppointsView
{
public:
    QGridLayout *gridLayout;
    QListWidget *appointsListChart;
    QPushButton *btnLeaveAppointsDialog;

    void setupUi(QDialog *DialogAppointsView)
    {
        if (DialogAppointsView->objectName().isEmpty())
            DialogAppointsView->setObjectName("DialogAppointsView");
        DialogAppointsView->resize(479, 355);
        gridLayout = new QGridLayout(DialogAppointsView);
        gridLayout->setObjectName("gridLayout");
        appointsListChart = new QListWidget(DialogAppointsView);
        appointsListChart->setObjectName("appointsListChart");
        QFont font;
        font.setPointSize(14);
        appointsListChart->setFont(font);

        gridLayout->addWidget(appointsListChart, 0, 0, 1, 1);

        btnLeaveAppointsDialog = new QPushButton(DialogAppointsView);
        btnLeaveAppointsDialog->setObjectName("btnLeaveAppointsDialog");
        QFont font1;
        font1.setPointSize(12);
        btnLeaveAppointsDialog->setFont(font1);

        gridLayout->addWidget(btnLeaveAppointsDialog, 1, 0, 1, 1);


        retranslateUi(DialogAppointsView);

        QMetaObject::connectSlotsByName(DialogAppointsView);
    } // setupUi

    void retranslateUi(QDialog *DialogAppointsView)
    {
        DialogAppointsView->setWindowTitle(QCoreApplication::translate("DialogAppointsView", "Dialog", nullptr));
        btnLeaveAppointsDialog->setText(QCoreApplication::translate("DialogAppointsView", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAppointsView: public Ui_DialogAppointsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAPPOINTSVIEW_H
