#include "dialogcalendar.h"
#include "qtextformat.h"
#include "ui_dialogcalendar.h"

DialogCalendar::DialogCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalendar)
{
    ui->setupUi(this);
    ui->appointsCalendar->setGridVisible(true);
    ui->appointsCalendar->setDateEditEnabled(true);
    ui->appointsCalendar->setMaximumDate(QDate(2100,10,10));
    ui->appointsCalendar->setMinimumDate(QDate(2022,01,01));
    ui->appointsCalendar->setSelectionMode( QCalendarWidget::SelectionMode::SingleSelection );
    formatCalendar();

    getServiceDates();
}

DialogCalendar::~DialogCalendar()
{
    delete ui;
}

void DialogCalendar::getServiceDates(){
    SqlConnection con;
    con.conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "SELECT DISTINCT\n"
    "SUBSTRING(fecha_serv,1,10) as date_service\n"
    "FROM ServicioElegido;"
    );

    QSqlQuery query;
    query.prepare(sqlSentence);
    if( query.exec() ){
        while( query.next() ){
            datesList.append( query.value("date_service").toString() );
            qDebug() <<"new date:"<< query.value("date_service").toString()<<"\n";
        }
    }else{
        qDebug() << "Error getting services choosen dates\n";
    }

    con.conClose();


    markSelectedDates();
}

void DialogCalendar::formatCalendar(){
    QTextCharFormat format;

    format.setForeground(
        qvariant_cast<QColor>( QColor(Qt::black) )
    );

    ui->appointsCalendar->setWeekdayTextFormat( Qt::Monday, format );
    ui->appointsCalendar->setWeekdayTextFormat( Qt::Tuesday, format );
    ui->appointsCalendar->setWeekdayTextFormat( Qt::Wednesday, format );
    ui->appointsCalendar->setWeekdayTextFormat( Qt::Thursday, format );
    ui->appointsCalendar->setWeekdayTextFormat( Qt::Friday, format );
    ui->appointsCalendar->setWeekdayTextFormat( Qt::Saturday, format );
    ui->appointsCalendar->setWeekdayTextFormat( Qt::Sunday, format );


}

void DialogCalendar::markSelectedDates(){

    QTextCharFormat format;

    format.setBackground( QBrush( QColor::fromRgb(237,120,95) ) );
    format.setForeground(Qt::black );


    for( const QString& currentDate : datesList){
    //qDebug() <<"choosen date:"<< currentDate<<"\n";
        ui->appointsCalendar->setDateTextFormat(
        QDate::fromString( currentDate, Qt::ISODate ), format
    );
    }
}



void DialogCalendar::on_btnCloseCalendar_clicked()
{
    this->close();
}


void DialogCalendar::on_appointsCalendar_clicked(const QDate &date)
{
    if( !date.isNull() || !date.isValid() ){
        emit choosenDate(date);
    }
    //selectedDateAppo = date;
    qDebug() << "date: " << date.day() << "**-**-**" << date.year()<<"\n";
}

/*
QDate DialogCalendar::getSelectedDate(){
    if ( !selectedDateAppo.isNull() || !selectedDateAppo.isValid() )
        return  QDate::fromString( QDate::currentDate().toString("yyyy-MM-dd") );

    return selectedDateAppo;
}
*/
