#ifndef FACTURA_H
#define FACTURA_H
#include <string>

class Factura
{
public:
    Factura(int id_cab_fac = 0, const std::string& fecha_cab_fac = "",
        double total_cab_fac = 0.0, const std::string& cod_pers = "");


    int getIdCabFactura() const;
    std::string getFechaCabFactura() const;
    double getTotalCabFactura() const;
    std::string getCodPersona() const;


    void setIdCabFactura(int id_cab_fac);
    void setFechaCabFactura(const std::string fech_cab_fac);
    void setTotalFactura(double total_cab_fac);
    void setCodPersona(const std::string cod_pers);

private:
    int id_cab_factura;
    std::string fecha_cab_factura;
    double total_cab_factura;
    std::string cod_persona;
};

#endif // FACTURA_H
