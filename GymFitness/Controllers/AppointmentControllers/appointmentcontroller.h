#ifndef APPOINTMENTCONTROLLER_H
#define APPOINTMENTCONTROLLER_H

#include <QTableWidget>

#include <QString>
#include <vector>
#include <string>
#include <iomanip>


#include <Models/persona.h>
#include <Models/rol.h>
#include <Models/paqueteentreno.h>
#include <Models/servicio.h>
#include <Models/factura.h>
#include <Models/detallefactura.h>
#include "sqlconnection.h"

class AppointmentController
{

public:
    static AppointmentController& getInstance(){
        static AppointmentController instance;
        return instance;
    }


    void getGymServices(SqlConnection *con, std::vector<Servicio>& servicios); //ya

    //INVOICES
    bool createEmptyPaymentInvoiceAP(SqlConnection *con, const Factura& factura); //ya

    bool updatePaymentInvoiceAP(SqlConnection *con, int id_cab_factura); //ya

    void getAllPaymentInvoicesAP(SqlConnection *con, std::vector<Factura>& facturas); //ya


    //INVOICE LINES
    bool createEmptyInvoiceLineAP(SqlConnection *con, const DetalleFactura& linea); //ya

    bool createInvoiceLineInfoAP(SqlConnection *con, int id_det_linea,
    int id_serv, int sesiones, const QString& fecha_serv); //ya

    bool updateInvoiceLineInfoAP(SqlConnection *con, int id_det_linea);

    void getAllInvoiceLines(SqlConnection *con, int cod_factura,
        std::vector<DetalleFactura>& lineas);


private:
    AppointmentController(){};
};

#endif // APPOINTMENTCONTROLLER_H
