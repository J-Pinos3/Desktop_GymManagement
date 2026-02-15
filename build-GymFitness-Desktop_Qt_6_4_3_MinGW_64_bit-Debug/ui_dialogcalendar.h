/********************************************************************************
** Form generated from reading UI file 'dialogcalendar.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCALENDAR_H
#define UI_DIALOGCALENDAR_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCalendar
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *appointsCalendar;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCloseCalendar;

    void setupUi(QDialog *DialogCalendar)
    {
        if (DialogCalendar->objectName().isEmpty())
            DialogCalendar->setObjectName("DialogCalendar");
        DialogCalendar->resize(448, 338);
        verticalLayout = new QVBoxLayout(DialogCalendar);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        appointsCalendar = new QCalendarWidget(DialogCalendar);
        appointsCalendar->setObjectName("appointsCalendar");
        appointsCalendar->setLocale(QLocale(QLocale::Spanish, QLocale::Spain));
        appointsCalendar->setMinimumDate(QDate(1999, 9, 15));
        appointsCalendar->setMaximumDate(QDate(2060, 12, 31));
        appointsCalendar->setFirstDayOfWeek(Qt::Monday);
        appointsCalendar->setGridVisible(true);
        appointsCalendar->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        appointsCalendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        appointsCalendar->setNavigationBarVisible(true);
        appointsCalendar->setDateEditEnabled(true);

        verticalLayout_2->addWidget(appointsCalendar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 10, -1, 10);
        btnCloseCalendar = new QPushButton(DialogCalendar);
        btnCloseCalendar->setObjectName("btnCloseCalendar");
        QFont font;
        font.setPointSize(12);
        btnCloseCalendar->setFont(font);

        horizontalLayout->addWidget(btnCloseCalendar);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(DialogCalendar);

        QMetaObject::connectSlotsByName(DialogCalendar);
    } // setupUi

    void retranslateUi(QDialog *DialogCalendar)
    {
        DialogCalendar->setWindowTitle(QCoreApplication::translate("DialogCalendar", "Dialog", nullptr));
        btnCloseCalendar->setText(QCoreApplication::translate("DialogCalendar", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCalendar: public Ui_DialogCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCALENDAR_H
