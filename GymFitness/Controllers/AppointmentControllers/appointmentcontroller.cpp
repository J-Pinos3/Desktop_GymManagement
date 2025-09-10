#include "appointmentcontroller.h"


void AppointmentController::getGymServices(SqlConnection *con, std::vector<Servicio>& servicios){

    con->conOpen();
    QString sqlSentence;
    sqlSentence.append("SELECT * FROM Servicio");

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            servicios.push_back(
                Servicio(
                    query.value("id_serv").toInt(),
                    query.value("serv_titulo").toString().toStdString(),
                    query.value("serv_price").toDouble()
                )
            );
        }
    }


    con->conClose();
}


bool AppointmentController::createEmptyPaymentInvoiceAP(SqlConnection *con, const Factura& factura){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO CabeceraFactura"
    "(fecha_cab_fact, total_cab_fact, cod_persona)"
    "VALUES('"+QString::fromStdString( factura.getFechaCabFactura() ) +
    "', " + QString::number( factura.getTotalCabFactura() ) +
    ", '" + QString::fromStdString( factura.getCodPersona()+"')" ));

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error creating a empty invoice: "
        << query.lastError().text();
    }

    con->conClose();
    return execution;
}

bool AppointmentController::updatePaymentInvoiceAP(SqlConnection *con, int id_cab_factura){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "CALL update_cabecera_factura(" + QString::number(id_cab_factura)+")");

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
       qDebug() <<"Error updating invoice " << id_cab_factura
        <<": " << query.lastError().text();
    }

    con->conClose();
    return execution;
}

void AppointmentController::getAllPaymentInvoicesAP(SqlConnection *con, std::vector<Factura>& facturas){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
        "SELECT DISTINCT\n"
        "CabFac.id_cab_fact,\n"
        "CabFac.fecha_cab_fact,\n"
        "CabFac.total_cab_fact,\n"
        "Pers.cod_persona,\n"
        "Pers.nombre,\n"
        "Pers.apellido\n"
        "FROM CabeceraFactura as CabFac\n"
        "INNER JOIN Persona as Pers on Pers.cod_persona = CabFac.cod_persona\n"
        "WHERE CabFac.id_cab_fact in(\n"
        "SELECT DISTINCT CabFac2.id_cab_fact\n"
        "FROM CabeceraFactura as CabFac2\n"
        "JOIN DetalleFactura as Detf ON CabFac2.id_cab_fact = Detf.id_cab_fact\n"
        "JOIN ServicioElegido as Serv ON Detf.id_deta_fact = Serv.id_deta_fact) or \n"
        "CabFac.id_cab_fact not in (\n"
        "SELECT DISTINCT id_cab_fact\n"
        "From DetalleFactura WHERE id_cab_fact is not null);" );

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
                    query.value("Pers.cod_persona").toString().toStdString(),
                    clienteActual

                )
            );
        }
    }else{
        qDebug() <<"Error getting all appoint invoices: "
                << query.lastError().text();
    }


    con->conClose();
}


bool AppointmentController::createEmptyInvoiceLineAP(SqlConnection *con, const DetalleFactura& linea){
    (*con).conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO DetalleFactura"
    "(total_deta_fact, id_cab_fact)"
    "VALUES(" + QString::number(linea.getTotalDetalleFact()) +
    ", " + QString::number(linea.getIdCabFactura()) + ")");

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error creating a empty invoice: "
        << query.lastError().text();
    }
    con->conClose();
    return execution;
}

bool AppointmentController::createInvoiceLineInfoAP(SqlConnection *con, int id_det_linea,
    int id_serv, int sesiones, const QString& fecha_serv)
{

    con->conOpen();
    QString sqlSentece;
    sqlSentece.append(
    "INSERT INTO ServicioElegido"
    "(id_deta_fact, id_serv, num_sesiones, fecha_serv)"
    "VALUES(" + QString::number(id_det_linea) + ", " + QString::number(id_serv) +
    ", " + QString::number(sesiones) + ", '" + fecha_serv + "');");

    QSqlQuery query;
    query.prepare(sqlSentece);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error creating chosen service: "
        << query.lastError().text();
    }

    con->conClose();
    return execution;

}




void AppointmentController::getAllInvoiceLines(SqlConnection *con, int cod_factura,
    std::vector<DetalleFactura>& lineas)
{
    con ->conOpen();

    ServicioElegido servicioActual;

    QString sqlSentence;
    sqlSentence.append(
    "SELECT\n"
    "Detf.id_deta_fact,"
    "COALESCE( concat(Servi.serv_titulo,\' \', Servi.serv_price), \'---\') as Descripcion,\n"
    "COALESCE( Servel.num_sesiones, -1) as Cantidad,\n"
    "COALESCE( Detf.total_deta_fact,-1.0) as TotalDetalle,\n"
    "COALESCE( Servel.fecha_serv, \'---\') as FechaServicio,\n"
    "COALESCE( concat(Pers.nombre,\' \', Pers.apellido), \'---\') as Nombre\n"
    "FROM DetalleFactura as Detf\n"
    "LEFT JOIN ServicioElegido as Servel on Detf.id_deta_fact = Servel.id_deta_fact\n"
    "LEFT JOIN Servicio as Servi on Servel.id_serv = Servi.id_serv\n"
    "LEFT JOIN CabeceraFactura as CabFact on Detf.id_cab_fact = CabFact.id_cab_fact\n"
    "LEFT JOIN Persona as Pers on CabFact.cod_persona = Pers.cod_persona\n"
    "WHERE Detf.id_cab_fact = " + QString::number(cod_factura) + ";");

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            servicioActual.setTituloServ(
                query.value("Descripcion").toString().toStdString() );
            servicioActual.setNumSesiones(
                query.value("Cantidad").toInt() );
            servicioActual.setFechaServ(
                query.value("FechaServicio").toString().toStdString());

            lineas.push_back(
                DetalleFactura(
                    query.value("Detf.id_deta_fact").toInt(),
                    query.value("TotalDetalle").toDouble(),
                    cod_factura,
                    PlanElegido(),
                    servicioActual,
                    query.value("Nombre").toString().toStdString()
                )
            );
        }
    }else{
        qDebug() << "Error getting lines from that header: " <<
            query.lastError().text() << "\n";
    }

    con->conClose();
}


bool AppointmentController::updateInvoiceLineInfoAP(SqlConnection *con,
    int id_det_linea){
    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "CALL update_detalle_servicio_factura(" + QString::number(id_det_linea) + ")");

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error updating line(appointment)" << id_det_linea
        <<": " << query.lastError().text();
    }

    con->conClose();
    return execution;
}



