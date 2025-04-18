#include "reportcontroller.h"

void ReportController::getAllInvoices(SqlConnection *con,
std::vector<Factura>& facturas){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "SELECT\n"
    "CabFac.id_cab_fact,\n"
    "CabFac.fecha_cab_fact,\n"
    "CabFac.total_cab_fact,\n"
    "Pers.cod_persona,\n"
    "Pers.nombre,\n"
    "Pers.apellido\n"
    "FROM CabeceraFactura as CabFac, Persona as Pers\n"
    "WHERE Pers.cod_persona = CabFac.cod_persona");

    Persona clienteActual;
    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            clienteActual.setNombre(
            query.value("Pers.nombre").toString().toStdString());

            clienteActual.setApellido(
            query.value("Pers.apellido").toString().toStdString());

            facturas.push_back(
                Factura(
                    query.value("CabFac.id_cab_fact").toInt(),
                    query.value("CabFac.fecha_cab_fact").toString().toStdString(),
                    query.value("CabFac.total_cab_fact").toDouble(),
                    query.value("pers.cod_persona").toString().toStdString(),
                    clienteActual

                )
            );
        }
    }else{
        qDebug() << "Error getting all payment invoices for report: "
                << query.lastError().text();
    }

    con->conClose();
}


void ReportController::getInvoiceLinesById(SqlConnection * con, int cod_factura,
std::vector<DetalleReporte>& lineas){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "SELECT\n"
    "Detf.id_deta_fact,\n"
    "Detf.total_deta_fact,\n"
    "IF((Servel.num_sesiones <> -1) or (Servel.num_sesiones is not null), Servi.serv_titulo, Paq.paq_descripcion) as Detalle,\n"
    "IF((Servel.num_sesiones <> -1) or (Servel.num_sesiones is not null), Servel.fecha_serv, Ple.fecha_pago) as Fecha,\n"
    "COALESCE( concat(Pers.nombre, \' \', Pers.apellido), \'---\' ) as Nombre\n"
    "FROM DetalleFactura as Detf\n"
    "LEFT JOIN CabeceraFactura as CabFact on Detf.id_cab_fact = CabFact.id_cab_fact\n"
    "LEFT JOIN Persona as Pers on CabFact.cod_persona = Pers.cod_persona\n"
    "LEFT JOIN ServicioElegido as Servel on Detf.id_deta_fact = Servel.id_deta_fact\n"
    "LEFT JOIN Servicio as Servi on Servel.id_serv = Servi.id_serv\n"
    "LEFT JOIN PlanElegido as Ple on Ple.id_deta_fact = Detf.id_deta_fact\n"
    "LEFT JOIN Paquete as Paq on Ple.id_paq = Paq.id_paq\n"
    "WHERE Detf.id_cab_fact = " + QString::number(cod_factura) + ";");

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            lineas.push_back(
                DetalleReporte(
                    query.value("Detf.id_deta_fact").toString().toInt(),
                    query.value("Detf.total_deta_fact").toString().toDouble(),
                    query.value("Detalle").toString().toStdString(),
                    query.value("Nombre").toString().toStdString(),
                    query.value("Fecha").toString().toStdString()
                )
            );
        }


    }else{
        qDebug() << "Error getting lines for invoice: " << cod_factura <<
            " for report" << query.lastError().text();
    }

    con->conClose();
}




