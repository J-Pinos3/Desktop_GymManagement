#ifndef REPORTCONTROLLER_H
#define REPORTCONTROLLER_H

#include <QString>
#include <vector>
#include <string>

#include <Models/factura.h>
#include <Models/detallereporte.h>
#include "sqlconnection.h"

class ReportController
{

public:
    static ReportController& getInstance(){
        static ReportController instance;
        return instance;
    }

    void getAllInvoices(SqlConnection *con,
        std::vector<Factura>& facturas);

    void getInvoiceLinesById(SqlConnection* con, int cod_factura,
    std::vector<DetalleReporte>& lineas );

private:
    ReportController(){};
};

#endif // REPORTCONTROLLER_H
