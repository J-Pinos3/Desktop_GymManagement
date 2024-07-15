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
#include "sqlconnection.h"

class PaymentControllers
{
public:
    //todo CREAR EL MODELO DE DATOS FACTURA EN CODIGO C++
    static PaymentControllers& getInstance(){
        static PaymentControllers instance;
        return instance;
    }

    void getTrainingPackages(SqlConnection *con, std::vector<PaqueteEntreno>& planesEntreno );


    //INVOICES
    bool createEmptyPaymentInvoice(SqlConnection *con, const QString& cod_persona,
        const QString& fecha_pago, bool abono = false, int cantidad_abono = 0, double total = 0.0 );

    void getAllPaymentInvoices(SqlConnection *con, std::vector<!FACTURA!>& facturas);



    //INVOICE LINES
    bool createInvoiceLine(SqlConnection *con, int cod_Factura,int id_paquete, int cantidad,
        int sub_total, const QString& fecha_pago, const QString& fecha_limite);

    void getAllInvoiceLines(SqlConnection *con, int cod_factura);

/**¿¿¿????¡¿??
 * void getUserPaymentOrders(SqlConnection *con, std::vector<Factura>& pagosCliente);
*/
private:
    PaymentControllers(){};
};

#endif // PAYMENTCONTROLLERS_H
