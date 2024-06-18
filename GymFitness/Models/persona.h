#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona
{
public:
    Persona(const std::string& codigo="", const std::string& nombre="",
    const std::string& apellido="", const std::string& fecha_registro="",
    int rol = 0);

    std::string getCodigo() const;

private:
    std::string codigo;
    std::string nombre;
    std::string apellido;
    std::string fecha_registro;
    int rol;
};

#endif // PERSONA_H
