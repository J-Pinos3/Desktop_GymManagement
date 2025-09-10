#include "dialogappointsview.h"
#include "ui_dialogappointsview.h"

/// IF NECCESARY CHANGE THE TYPE FROM QDATE TO QDATETIME
DialogAppointsView::DialogAppointsView(QWidget *parent, const QDate& date) :
    QDialog(parent),
    ui(new Ui::DialogAppointsView)
{
    ui->setupUi(this);
    //selectedAppointDate = date.toString("yyyy-MM-dd");


    //getAppointsForDate();

    //showAppointsChart();
}

DialogAppointsView::~DialogAppointsView()
{
    delete ui;
}


void DialogAppointsView::getAppointsList(const QDate& date){
    selectedAppointDate = date.toString("yyyy-MM-dd") ;

    appointsList.clear();
    ui->appointsListChart->clear();

    getAppointsForDate();

    showAppointsChart();
    qDebug() << "Constructorrrr apoints view" << selectedAppointDate << "\n";
}


void DialogAppointsView::showAppointsChart(){
    qDebug() << "List size" << appointsList.size() << "\n";

    if(appointsList.isEmpty()) {
        ui->appointsListChart->addItem("No hay citas para esta fecha");
    }else{
       for(const QString& item : appointsList ){
            this->ui->appointsListChart->addItem(item);
       }
    }


}

void DialogAppointsView::getAppointsForDate(){
    SqlConnection con;
    con.conOpen();


    QString sqlSentence;
    sqlSentence.append(
        "SELECT\n"
        "Servel.fecha_serv as fecha,\n"
        "(SELECT serv_titulo FROM Servicio WHERE Servicio.id_serv = Servel.id_serv) as titulo,\n"
        "Pers.nombre as nombre,\n"
        "Pers.apellido as apellido\n"
        "FROM ServicioElegido as Servel\n"
        "LEFT JOIN DetalleFactura as Detf ON Detf.id_deta_fact = Servel.id_deta_fact\n"
        "LEFT JOIN CabeceraFactura as CabFac ON CabFac.id_cab_fact = Detf.id_cab_fact\n"
        "LEFT JOIN Persona as Pers ON Pers.cod_persona = CabFac.cod_persona\n"
        "WHERE Servel.fecha_serv LIKE '" + selectedAppointDate +"%';"
            );
    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            appointsList.append(
                query.value("fecha").toString() +" "+
                query.value("titulo").toString()+" "+
                "cliente: " + query.value("nombre").toString()+" "+
                query.value("apellido").toString()+"."
            );
            qDebug() <<  query.value("fecha").toString() +" "+
                query.value("titulo").toString() << "\n";
        }
    }else{
        //qDebug() << "Error getting appoins for " << selectedAppointDate << "\n";
        qDebug() << "Error getting appoins: " << query.lastError().text() << "\n";
    }

    con.conClose();
}

void DialogAppointsView::on_btnLeaveAppointsDialog_clicked()
{
    this->close();
}

