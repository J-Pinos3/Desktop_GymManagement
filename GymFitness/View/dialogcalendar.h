#ifndef DIALOGCALENDAR_H
#define DIALOGCALENDAR_H

#include <QWidget>
#include <QDialog>

#include "sqlconnection.h"
#include <QDate>
namespace Ui {
class DialogCalendar;
}

class DialogCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCalendar(QWidget *parent = nullptr);
    ~DialogCalendar();

    //QDate getSelectedDate();
    void formatCalendar();

    void getServiceDates();

    void markSelectedDates();

signals:
    void choosenDate(const QDate& date);

private slots:

    void on_btnCloseCalendar_clicked();

    void on_appointsCalendar_clicked(const QDate &date);

private:
    Ui::DialogCalendar *ui;
    QStringList datesList;
    //QDate selectedDateAppo;
};

#endif // DIALOGCALENDAR_H
