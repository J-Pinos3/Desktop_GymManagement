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
    bool createEmptyPaymentInvoice(SqlConnection *con, const QString& cod_persona,
        const QString& fecha_pago, double total = 0.0 );

    void getAllPaymentInvoices(SqlConnection *con, std::vector<Factura>& facturas);



    //INVOICE LINES                                    codigo cabeza factura(invoice)
    bool createInvoiceLine(SqlConnection *con,int sub_total, int cod_Factura,
        int id_invoice_line_detalle,int id_paquete,int cantidad,
        const QString& fecha_pago, const QString& fecha_limite);

    void getAllInvoiceLines(SqlConnection *con, int cod_factura,
        std::vector<DetalleFactura>& lineas);

/**¿¿¿????¡¿??
 * void getUserPaymentOrders(SqlConnection *con, std::vector<Factura>& pagosCliente);
*/
private:
    PaymentControllers(){};
};

#endif // PAYMENTCONTROLLERS_H
