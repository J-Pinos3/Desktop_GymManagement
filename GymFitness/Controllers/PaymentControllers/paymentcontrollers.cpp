#include "paymentcontrollers.h"

void PaymentControllers::getTrainingPackages(SqlConnection *con,
    std::vector<PaqueteEntreno>& planesEntreno ){

    con->conOpen();

    QString sqlSentence;
    sqlSentence.append("SELECT * FROM paquete");

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            planesEntreno.push_back(
                PaqueteEntreno(
                    query.value("id_paq").toInt(),
                    query.value("paq_descripcion").toString().toStdString(),
                    query.value("paq_price").toDouble(),
                    query.value("paq_days").toInt()
                )
            );
        }
    }

    con->conClose();
}


bool PaymentControllers::createEmptyPaymentInvoice(SqlConnection *con, const Factura& facturaNueva){

    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO CabeceraFactura"
    "(fecha_cab_fact, total_cab_fact, cod_persona)"
    "VALUES('" + QString::fromStdString( facturaNueva.getFechaCabFactura() ) +
    "', " + QString::number(facturaNueva.getTotalCabFactura()) +
    ", '" + QString::fromStdString( facturaNueva.getCodPersona()+ "')" ));

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error creating a empty invoice: "
        << query.lastError().text();
    }

    con->conClose();
    return execution;
}//CREATE EMPTY INVOICE

bool PaymentControllers::updatePaymentInvoice(SqlConnection *con, int id_cab_fact){
    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "CALL update_cabecera_factura(" + QString::number(id_cab_fact) +")" );

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error updating invoice " << id_cab_fact
        <<": " << query.lastError().text();
    }

    con->conClose();
    return execution;
}


//not used -- this query brings all invoices, combining training plans and gym services
void PaymentControllers::getAllInvoices(SqlConnection *con, std::vector<Factura>& facturas){

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
    "INNER JOIN Persona as Pers on Pers.cod_persona = CabFac.cod_persona"
    );

    Persona clienteActual;
    QSqlQuery query;
    query.prepare(sqlSentence);
    if( query.exec() ){

        while( query.next() ){
            clienteActual.setNombre(
                query.value("Pers.nombre").toString().toStdString()  );
            clienteActual.setApellido(
                query.value("Pers.apellido").toString().toStdString()  );

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
        qDebug() << "Error getting all payment invoices: "
                 << query.lastError().text()<<"\n";
    }


    con->conClose();

}


//this query brings invoices from training plans
void PaymentControllers::getAllPaymentInvoices(SqlConnection *con, std::vector<Factura>& facturas){
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
    "JOIN PlanElegido as PE on Detf.id_deta_fact = PE.id_deta_fact) or \n"
    "CabFac.id_cab_fact not in (\n"
    "SELECT DISTINCT id_cab_fact\n"
    "FROM DetalleFactura WHERE id_cab_fact is not null);");


    Persona clienteActual;
    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            clienteActual.setNombre(
                query.value("Pers.nombre").toString().toStdString()    );
            clienteActual.setApellido(
                query.value("Pers.apellido").toString().toStdString()    );
            facturas.push_back(
                Factura(
                    query.value("CabFac.id_cab_fact").toInt(),
                    query.value("CabFac.fecha_cab_fact").toString().toStdString(),
                    query.value("CabFac.total_cab_fact").toDouble(),
                    query.value("Pers.cod_persona").toString().toStdString(),
                    clienteActual
                )
            );
            qDebug() <<  "Factura de Planes: "
                     <<  query.value("Pers.nombre").toString() <<"  " << query.value("Pers.apellido").toString()
                     << query.value("CabFac.id_cab_fact").toInt() << "\n";
        }
    }else{
        qDebug() <<"Error getting training payment invoices: "
                << query.lastError().text();
    }

    con->conClose();
}//GET ALL PAYMENT INVOICES


bool PaymentControllers::createEmptyInvoiceLine(SqlConnection *con, const DetalleFactura& linea){
    con->conOpen();

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
        qDebug() <<"Error creating an empty line: "
        << query.lastError().text();
    }
    con->conClose();
    return execution;
}//CREATE EMPTY INVOICE LINE


bool PaymentControllers::createInvoiceLineInfo(SqlConnection *con, int id_det_linea,
    int id_paquete, int cantidad,
    const QString& fecha_pago, const QString& fecha_limite){
    ///fecha_limite is determinated with code = fecha_pago + paqueteEntreno.dias
    ///the total of detalle factura is determinated with precio_paquete *  cantidad;
    ///plan elegido is an extension of [DetalleFactura]
    ///
    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO PlanElegido"
    "(id_deta_fact, id_paq, catidad_paq, fecha_pago, fecha_finalizacion)"
    "VALUES(" + QString::number(id_det_linea) + ", " + QString::number(id_paquete) +
    ", " + QString::number(cantidad) + ", '" + fecha_pago +
    "', '" + fecha_limite + "'); ");

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if(!query.lastError().text().isNull()){
        qDebug() <<"Error creating chosen plan: "
        << query.lastError().text();
    }
    con->conClose();
    return execution;

    /* PREVIOUS VERSION
        //@last_id_from_det_fac replaces id_invoice_line_detalle
       QString sqlSentence;
       sqlSentence.append(
        "BEGIN;"
        "INSERT INTO DetalleFactura"
        "(total_deta_fact, id_cab_fact)"
        "VALUES(" + QString::number(sub_total) + ", '" + QString::number(cod_Factura) + "')"
        "SET @last_id_from_det_fac = LAST_INSERT_ID()"
        "INSERT INTO PlanElegido"
        "(id_deta_fact, id_paq, catidad_paq, fecha_pago, fecha_finalizacion)"
        "VALUES(@last_id_from_det_fac, " + QString::number(id_paquete) + ", "
        "" + QString::number(cantidad) + ", '" + fecha_pago + "', '" +  fecha_limite + "') " );
    */
}


bool PaymentControllers::updateInvoiceLineInfo(SqlConnection *con, int id_det_linea){
    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "CALL update_detalle_factura(" + QString::number(id_det_linea) +")");

    QSqlQuery query;
    query.prepare(sqlSentence);
    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error updating line " << id_det_linea
        <<": " << query.lastError().text();
    }

    con->conClose();
    return execution;
}

//not used directly
bool PaymentControllers::createEmptyLineInfo(SqlConnection *con){

    con->conOpen();
    //LAST_INSERT_ID is the id of the just created invoice line
    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO PlanElegido"
    "(id_deta_fact, id_paq, catidad_paq, fecha_pago, fecha_finalizacion)"
    "VALUES( LAST_INSERT_ID(), 1, 0, '2001-01-01', '2001-01-01';" );

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();

    if(!query.lastError().text().isNull()){
        qDebug() <<"Error creating empty plan(line info): "
        << query.lastError().text();
    }

    con->conClose();
    return execution;
}



void PaymentControllers::getAllInvoiceLines(
        SqlConnection *con, int cod_factura,
        std::vector<DetalleFactura>& lineas){


    con->conOpen();
    PlanElegido planActual;

    QString sqlSentence;
    sqlSentence.append(
    "SELECT\n"
    "Detf.id_deta_fact,"
    "COALESCE( concat(Paq.paq_descripcion,\' \', Paq.paq_price), \'---\') as Descripcion,\n"
    "COALESCE(Ple.catidad_paq, -1) as Cantidad,\n"
    "COALESCE(Detf.total_deta_fact, -10.00) as TotalDetalle,\n"
    "COALESCE(Ple.fecha_pago, \'---\') as FechaPago,\n"
    "COALESCE(Ple.fecha_finalizacion, \'---\') as FechaFin\n"
    "FROM DetalleFactura as Detf\n"
    "LEFT JOIN PlanElegido as Ple on Detf.id_deta_fact = Ple.id_deta_fact\n"
    "LEFT JOIN Paquete as Paq on Ple.id_paq = Paq.id_paq\n"
    "WHERE Detf.id_cab_fact = " + QString::number(cod_factura) + ";");

    /*
    sqlSentence.append(
        "SELECT\n"
        "Detf.id_deta_fact, concat(Paq.paq_descripcion,\' \', Paq.paq_price) as Descripcion,\n"
        "Ple.catidad_paq, Detf.total_deta_fact, Ple.fecha_pago, Ple.fecha_finalizacion\n"
        "FROM DetalleFactura as Detf\n"
        "INNER JOIN PlanElegido as Ple on Detf.id_deta_fact = Ple.id_deta_fact\n"
        "INNER JOIN Paquete as Paq on Ple.id_paq = Paq.id_paq\n"
        "WHERE Detf.id_cab_fact = " + QString::number(cod_factura) + ";");
        */

    QSqlQuery query;
    query.prepare(sqlSentence);

    if(query.exec()){
        while( query.next() ){
            planActual.setDescripcionCompleta(
                query.value("Descripcion").toString().toStdString()  );
            planActual.setCantidadPaquete(
                query.value("Cantidad").toString().toInt()  );
            planActual.setFechaPago(
                query.value("FechaPago").toString().toStdString() );
            planActual.setFechaFin(
                query.value("FechaFin").toString().toStdString()  );

            lineas.push_back(
                DetalleFactura(
                    query.value("Detf.id_deta_fact").toString().toInt(),
                    query.value("TotalDetalle").toString().toDouble(),
                    cod_factura,
                    planActual
                )
            );

            qDebug() << query.value("Descripcion").toString() << " --- "
            << query.value("Cantidad").toString().toInt()
             << "  ---  " << planActual.getCantidadPaquete() << " ---\n"
            << " --- " << query.value("Detf.id_deta_fact").toString().toInt() << "\n" ;
        }
    }else{
         qDebug() <<"Error getting lines from that header " <<": " << query.lastError().text();
    }

    con->conClose();
}



void PaymentControllers::getFilteredPaymentInvoices(SqlConnection *con, std::vector<Factura>& facturasFiltradas,
    const QString& fechaInicio, const QString& cod_persona){

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
    "WHERE(\n"
        "CabFac.id_cab_fact in (\n"
        "SELECT DISTINT CabFac2.id_cab_fact\n"
        "FROM CabeceraFactura as CabFac2\n"
        "JOIN DetalleFactura as Detf ON CabFac2.id_cab_fact = Detf.id_cab_fact\n"
        "JOIN PlanElegido as PE ON Detf.id_deta_fact = PE.id_deta_fact) or \n"
        "CabFac.id_cab_fact not in (\n"
        "SELECT DISTINCT id_cab_fact\n"
        "FROM DetalleFactura WHERE id_cab_fact is not null)\n"
        ")\n"   );

    if(cod_persona == ""){
        sqlSentence += "and (CabFac.fecha_cab_fact between '" + fechaInicio + "' and CURDATE());";
    }else{
        sqlSentence += "and (Pers.cod_persona = '" + cod_persona + "');";
    }


    Persona clienteActual;
    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            clienteActual.setNombre(
                query.value("Pers.nombre").toString().toStdString()    );
            clienteActual.setApellido(
                query.value("Pers.apellido").toString().toStdString()    );
            facturasFiltradas.push_back(
                Factura(
                    query.value("CabFac.id_cab_fact").toInt(),
                    query.value("CabFac.fecha_cab_fact").toString().toStdString(),
                    query.value("CabFac.total_cab_fact").toDouble(),
                    query.value("Pers.cod_persona").toString().toStdString(),
                    clienteActual
                )
            );
            qDebug() <<  "Factura de Planes FILTRADA: "
                     <<  query.value("Pers.nombre").toString() <<"  " << query.value("Pers.apellido").toString()
                     << query.value("CabFac.id_cab_fact").toInt() << "\n";
        }
    }else{
        qDebug() <<"Error getting training payment invoices: "
                << query.lastError().text();
    }


    con->conClose();
}





///↓ is not used because I've fixed the query
/// in the PaymentControllers::getAllInvoiceLines function
void PaymentControllers::getEmptyInvoiceLines(
    SqlConnection *con, int cod_factura,
    std::vector<DetalleFactura>& lineas ){

    con->conOpen();

    PlanElegido planActualVacio;
    QString sqlSentence;
    sqlSentence.append(
    "SELECT * from DetalleFactura WHERE id_cab_fact = "
    + QString::number(cod_factura) + ";");

    QSqlQuery query;
    query.prepare(sqlSentence);


    if( query.exec() ){
        while( query.next() ){
            planActualVacio.setDescripcionCompleta("---");
            planActualVacio.setCantidadPaquete(0);
            planActualVacio.setFechaPago("2001-01-01");
            planActualVacio.setFechaFin("2001-01-01");

            lineas.push_back(
                DetalleFactura(
                    query.value("id_deta_fact").toString().toInt(),
                    query.value("total_deta_fact").toString().toDouble(),
                    cod_factura,
                    planActualVacio
                )
            );
        }
    }else{
        qDebug() <<"Error getting lines from that header " <<": " << query.lastError().text();
    }


    con->conClose();
}






