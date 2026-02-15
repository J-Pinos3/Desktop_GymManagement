#include "persona.h"

Persona::Persona(const std::string& codigo, const std::string& nombre,
    const std::string& apellido, const std::string& fecha_registro,
    const std::string& fecha_pago,const std::string& fecha_fin,
    double peso, int rol)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->apellido = apellido;
    this->peso = peso;
    this->fecha_registro = fecha_registro;
    this->fecha_pago = fecha_pago;
    this->fecha_fin = fecha_fin;
    this->rol = rol;
}

std::string Persona::getCodigo() const{ return codigo; }

std::string Persona::getNombre() const{ return nombre; }

std::string Persona::getApellido() const{ return apellido; }

std::string Persona::getFechaRegistro() const{ return fecha_registro; }

std::string Persona::getFechaPago() const{ return fecha_pago; }

std::string Persona::getFechaFin() const{ return fecha_fin; }


double Persona::getPeso() const{ return peso; }

int Persona::getRol() const{ return rol; }


void Persona::setCodigo(std::string codigo){

    if( checkStringLength(12, 3, codigo) ){
        this->codigo = codigo;
    }else{
        this->codigo = "00000";
    }

}

void Persona::setNombre(std::string nombre){
    if(checkStringLength(20, 3, nombre)){
        this->nombre = nombre;
    }else{
        this->nombre = "Bad Name";
    }
}

void Persona::setApellido(std::string apellido){
    if(checkStringLength(30, 3, apellido)){
        this->apellido = apellido;
    }else{
        this->apellido = "Bad LastName";
    }
}

void Persona::setFechaRegistro(std::string fecha_registro){
    if(checkStringLength(10,5, fecha_registro)){
        this->fecha_registro = fecha_registro;
    }else{
        this->fecha_registro = "Bad Date";
    }
}

void Persona::setFechaPago(std::string fecha_pago){
    if(checkStringLength(10,5, fecha_pago)){
        this->fecha_pago = fecha_pago;
    }else{
        this->fecha_pago = "Bad Date";
    }
}


void Persona::setFechaFin(std::string fecha_fin){
    if(checkStringLength(10,5, fecha_fin)){
        this->fecha_fin = fecha_fin;
    }else{
        this->fecha_fin = "Bad Date";
    }
}


void Persona::setPeso(double peso){
    if(checkDoubleValue(peso)){
        this->peso = peso;
    }else{
        this->peso = 0.0;
    }
}

void Persona::setRol(int rolId){
    if(checkIntValue(rolId)){
        this->rol = rolId;
    }else{
        this->rol = 0;
    }
}


bool checkStringLength(const int upperLimit, const int lowerLimit,
    const std::string& currentData){

    return (currentData.length() <= upperLimit &&
           currentData.length() >= lowerLimit);
}

bool checkIntValue(const int currentData){
    return !(currentData < 0);
}

bool checkDoubleValue(const double currentData){
    return !(currentData < 0.0);
}
