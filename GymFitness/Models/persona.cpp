#include "persona.h"

Persona::Persona(const std::string& codigo, const std::string& nombre,
    const std::string& apellido, const std::string& fecha_registro,
    int rol)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->apellido = apellido;
    this->fecha_registro = fecha_registro;
    this->rol = rol;
}
