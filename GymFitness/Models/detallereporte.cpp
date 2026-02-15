#include "detallereporte.h"

DetalleReporte::DetalleReporte(int id_deta_fact, double total_det_fac,
    const std::string& det_descrip, const std::string& nom_cli,
    const std::string& fech_report)
{
    this->id_deta_factura = id_deta_fact;
    this->total_deta_factura = total_det_fac;
    this->detalle = det_descrip;
    this->nombre = nom_cli;
    this->fecha = fech_report;
}


int DetalleReporte::getIdDetalleReporte() const{ return id_deta_factura; }

double DetalleReporte::getTotalDetalleReporte() const{ return total_deta_factura; }


void DetalleReporte::setIdDetalleReporte(int id_det_fac_repo){
    this->id_deta_factura = id_det_fac_repo;
}

void DetalleReporte::setTotalDetalleReporte(double total_det_fac_repo){
    this->total_deta_factura = total_det_fac_repo;
}


std::string DetalleReporte::getDetalleReporte() const{ return detalle; }

void DetalleReporte::setDetalleReporte(const std::string& detalleDescrip){
    this->detalle = detalleDescrip;
}


std::string DetalleReporte::getNombreCliente() const{ return nombre; }

void DetalleReporte::setNombreCliente(const std::string& nombreCli){
    this->nombre = nombreCli;
}


std::string DetalleReporte::getFecha() const{ return fecha; }

void DetalleReporte::setFecha(const std::string& fecha_repo){
    this->fecha = fecha_repo;
}

