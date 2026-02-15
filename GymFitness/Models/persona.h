#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona
{
public:
    Persona(const std::string& codigo="", const std::string& nombre="",
    const std::string& apellido="", const std::string& fecha_registro="",
    const std::string& fecha_pago="",const std::string& fecha_fin="",
    double peso = 0, int rol = 0);

    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getFechaRegistro() const;
    std::string getFechaPago() const;
    std::string getFechaFin() const;
    double getPeso() const;
    int getRol() const;

    void setCodigo(std::string codigo);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setFechaRegistro(std::string fecha_registro);
    void setFechaPago(std::string fecha_pago);
    void setFechaFin(std::string fecha_fin);
    void setPeso(double peso);
    void setRol(int rolId);

private:
    std::string codigo;
    std::string nombre;
    std::string apellido;
    std::string fecha_registro;
    std::string fecha_pago;
    std::string fecha_fin;
    double peso;
    int rol;
};

bool checkStringLength(
    const int upperLimit,
    const int lowerLimit,
    const std::string& currentData);

///used for validating rol for the moment
bool checkIntValue(const int currentData);
///used for validating peso
bool checkDoubleValue(const double currentData);

#endif // PERSONA_H
