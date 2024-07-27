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

void PaymentControllers::getAllPaymentInvoices(SqlConnection *con, std::vector<Factura>& facturas){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append("SELECT * FROM CabeceraFactura");

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            facturas.push_back(
                Factura(
                    query.value("id_cab_fact").toInt(),
                    query.value("fecha_cab_fact").toString().toStdString(),
                    query.value("total_cab_factura").toDouble(),
                    query.value("cod_persona").toString().toStdString()
                )
            );
        }
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
    "', '" + fecha_limite + "') ");

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











