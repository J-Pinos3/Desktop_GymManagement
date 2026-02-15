#include "planelegido.h"

PlanElegido::PlanElegido(int id_plan, const std::string& codigo_pers,
    int id_paquete, int cantidad_paquete,
    const std::string& fech_pago, const std::string& fech_fin,
    const std::string& descrip)
{
    this->id_plan_elegido = id_plan;
    this->cod_persona = codigo_pers;
    this->id_paq = id_paquete;
    this->cantidad_paq = cantidad_paquete;
    this->fecha_pago = fech_pago;
    this->fecha_finalizacion = fech_fin;
    this->descripcion_completa = descrip;
}


int PlanElegido::getIdPlanElegido() const{ return id_plan_elegido; }

std::string PlanElegido::getCodigoPersona() const{ return cod_persona; }

int PlanElegido::getIdPaquete() const{ return id_paq; }

int PlanElegido::getCantidadPaquete() const{ return cantidad_paq; }

std::string PlanElegido::getFechaPago() const{ return fecha_pago; }

std::string PlanElegido::getFechaFin() const{ return fecha_finalizacion; }

std::string PlanElegido::getDescripcionCmpleta() const{ return descripcion_completa; }


void PlanElegido::setIdPlanElegido(int id_plan_eleg){
    this->id_plan_elegido = id_plan_eleg;
}

void PlanElegido::setCodigoPersona(std::string codigo){
    this->cod_persona = codigo;
}

void PlanElegido::setIdPaquete(int id_paquete){
    this->id_paq = id_paquete;
}

void PlanElegido::setCantidadPaquete(int cantidad){
    this->cantidad_paq = cantidad;
}

void PlanElegido::setFechaPago(std::string fecha_pago){
    this->fecha_pago = fecha_pago;
}

void PlanElegido::setFechaFin(std::string fecha_fin){
    this->fecha_finalizacion = fecha_fin;
}

void PlanElegido::setDescripcionCompleta(std::string descrip){
    this->descripcion_completa = descrip;
}
