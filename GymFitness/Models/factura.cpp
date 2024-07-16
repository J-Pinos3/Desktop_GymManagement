#include "factura.h"

Factura::Factura(int id_cab_fac , const std::string& fecha_cab_fac,
        double total_cab_fac, const std::string& cod_pers)
{
    this->id_cab_factura = id_cab_fac;
    this->fecha_cab_factura = fecha_cab_fac;
    this->total_cab_factura = total_cab_fac;
    this->cod_persona = cod_pers;
}


int Factura::getIdCabFactura() const{ return id_cab_factura; }

std::string Factura::getFechaCabFactura() const{ return fecha_cab_factura; }

double Factura::getTotalCabFactura() const{ return total_cab_factura; }

std::string Factura::getCodPersona() const{ return cod_persona; }


void Factura::setIdCabFactura(int id_cab_fac){
    this->id_cab_factura = id_cab_fac;
}

void Factura::setFechaCabFactura(const std::string fech_cab_fac){
    this->fecha_cab_factura = fech_cab_fac;
}

void Factura::setTotalFactura(double total_cab_fac){
    this->total_cab_factura = total_cab_fac;
}

void Factura::setCodPersona(const std::string cod_pers){
    this->cod_persona = cod_pers;
}
