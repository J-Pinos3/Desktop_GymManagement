#include "paqueteentreno.h"

PaqueteEntreno::PaqueteEntreno(int id_paquete, const std::string& descrip,
    double precio, int dias)
{
    this->id_paq = id_paquete;
    this->descripcion = descrip;
    this->precio = precio;
    this->dias = dias;
}


std::string PaqueteEntreno::getDescriptionPaquete() const{ return descripcion; }

int PaqueteEntreno::getIdPaquete() const { return id_paq; }

int PaqueteEntreno::getDiasPaquete() const { return dias; }

double PaqueteEntreno:: getPrecioPaquete() const { return precio; }


void PaqueteEntreno::setDescripcionPaquete(const std::string& descripcion) {
    this->descripcion = descripcion;
}

void PaqueteEntreno::setIdPaquete(int id){
    this->id_paq = id;
}

void PaqueteEntreno::setDiasPaquete(int dias){
    this->dias = dias;
}

void PaqueteEntreno::setPrecioPaquete(double precio){
    this->precio = precio;
}
