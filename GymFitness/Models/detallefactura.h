#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H

#include "Models/planelegido.h"

class DetalleFactura
{
public:
    DetalleFactura(int id_det_fac = 0, double total_det_fac = 0.0,
        int id_cab_fac = 0, const PlanElegido& plan_eleg = PlanElegido());

    int getIdDetalleFact() const;
    double getTotalDetalleFact() const;
    int getIdCabFactura() const;

    void setIdDetalleFact(int id_det_fac);
    void setTotalDetalleFact(double total_det_fac);
    void setIdCabFactura(int id_cab_fac);

    PlanElegido plan;
private:
    int id_deta_factura;
    double total_deta_factura;
    int id_cab_factura;

};

#endif // DETALLEFACTURA_H
