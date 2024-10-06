#include "detallefactura.h"

DetalleFactura::DetalleFactura(int id_det_fac, double total_det_fac,
        int id_cab_fac, const PlanElegido& plan_eleg, const ServicioElegido& serv_eleg)
{
    this->id_deta_factura = id_det_fac;
    this->total_deta_factura = total_det_fac;
    this->id_cab_factura = id_cab_fac;
    this->plan = plan_eleg;
    this->servicio = serv_eleg;
}


int DetalleFactura::getIdDetalleFact() const{ return id_deta_factura; }

double DetalleFactura::getTotalDetalleFact() const{ return total_deta_factura; }

int DetalleFactura::getIdCabFactura() const{ return id_cab_factura; }


void DetalleFactura::setIdDetalleFact(int id_det_fac){
    this->id_deta_factura = id_det_fac;
}

void DetalleFactura::setTotalDetalleFact(double total_det_fac){
    this->total_deta_factura = total_det_fac;
}

void DetalleFactura::setIdCabFactura(int id_cab_fac){
    this->id_cab_factura = id_cab_fac;
}
