#include "servicio.h"

int Servicio::getIdServicio() const{ return id_serv; }
std::string Servicio::getTituloServicio() const{ return serv_titulo; }
double Servicio::getPrecioServicio() const{ return precio;  }

void Servicio::setIdServicio(int id){
    this->id_serv = id;
}

void Servicio::setTituloPaquete(const std::string& titulo){
    titulo.empty() ? serv_titulo = "" : titulo;
}

void Servicio::setPrecioPaquete(double precio){
    this->precio = precio;
}
