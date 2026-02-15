#include "servicioelegido.h"

int ServicioElegido::getIdServElegido() const{  return id_serv_elegido; }

int ServicioElegido::getIdServicio() const{ return id_serv; }

int ServicioElegido::getNumSesiones() const{ return num_sesiones; }

std::string ServicioElegido::getFechaServ() const{ return fecha_serv; }

std::string ServicioElegido::getTituloServ() const{ return titulo_serv; }

void ServicioElegido::setIdServElegido(int id_serv_eleg){
    this->id_serv_elegido = id_serv_eleg;
}

void ServicioElegido::setIdServicio(int id_servicio){
    this->id_serv = id_servicio;
}

void ServicioElegido::setNumSesiones(int num_ses){
    this->num_sesiones = num_ses;
}

void ServicioElegido::setFechaServ(std::string fech_serv){
    this->fecha_serv = fech_serv;
}

void ServicioElegido::setTituloServ(std::string titulo_serv){
    this->titulo_serv = titulo_serv;
}
