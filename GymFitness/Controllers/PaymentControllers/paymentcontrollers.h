#ifndef PAYMENTCONTROLLERS_H
#define PAYMENTCONTROLLERS_H

#include <QTableWidget>

#include <QString>
#include <vector>
#include <string>
#include <iomanip>

#include <Models/persona.h>
#include <Models/rol.h>
#include <Models/paqueteentreno.h>
#include <Models/factura.h>
#include <Models/detallefactura.h>
#include "sqlconnection.h"

class PaymentControllers
{
public:

    static PaymentControllers& getInstance(){
        static PaymentControllers instance;
        return instance;
    }

    void getTrainingPackages(SqlConnection *con, std::vector<PaqueteEntreno>& planesEntreno );


    //todo funcion para actualizar la cabecera vacía
    //INVOICES
    bool createEmptyPaymentInvoice(SqlConnection *con, const Factura& facturaNueva);

    bool updatePaymentInvoice(SqlConnection *con, int id_cab_fact);

    void getAllPaymentInvoices(SqlConnection *con, std::vector<Factura>& facturas);



    //INVOICE LINES
    bool createEmptyInvoiceLine(SqlConnection *con, const DetalleFactura& linea);

    bool createInvoiceLineInfo(SqlConnection *con,int id_det_linea,
        int id_paquete, int cantidad,
        const QString& fecha_pago, const QString& fecha_limite);

    bool updateInvoiceLineInfo(SqlConnection *con, int id_det_linea);


    void getAllInvoiceLines(SqlConnection *con, int cod_factura,
        std::vector<DetalleFactura>& lineas);


private:
    PaymentControllers(){};
};

#endif // PAYMENTCONTROLLERS_H
