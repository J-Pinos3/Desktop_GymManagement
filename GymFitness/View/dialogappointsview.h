#ifndef DIALOGAPPOINTSVIEW_H
#define DIALOGAPPOINTSVIEW_H

#include <QWidget>
#include <QDialog>

#include "sqlconnection.h"
#include <QDate>
//#import "View/dialogcalendar.h"

namespace Ui {
class DialogAppointsView;
}

class DialogAppointsView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAppointsView(QWidget *parent = nullptr, const QDate& date = QDate::currentDate());
    ~DialogAppointsView();

    void getAppointsForDate();

    void showAppointsChart();

public slots:
    void getAppointsList(const QDate& date);

private slots:
    void on_btnLeaveAppointsDialog_clicked();

private:
    Ui::DialogAppointsView *ui;
    QString selectedAppointDate;
    QStringList appointsList;

};

#endif // DIALOGAPPOINTSVIEW_H
