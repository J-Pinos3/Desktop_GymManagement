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


bool PaymentControllers::createEmptyPaymentInvoice(SqlConnection *con, const QString& cod_persona,
    const QString& fecha_pago, double total){

    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO CabeceraFactura"
    "(fecha_cab_fact, total_cab_fact, cod_persona)"
    "VALUES('" + fecha_pago + "', " + QString::number(total) + ", '" + cod_persona + "')" );

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


bool PaymentControllers::createInvoiceLine(SqlConnection *con,int sub_total, int cod_Factura, int id_invoice_line_detalle, int id_paquete,
    int cantidad, const QString& fecha_pago, const QString& fecha_limite){

    con->conOpen();

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
    "" + QString::number(cantidad) + ", '" + fecha_pago + "', '" +  fecha_pago + "') " );

   con->conClose();

    return false;
}
