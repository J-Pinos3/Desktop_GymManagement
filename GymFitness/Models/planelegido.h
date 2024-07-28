#ifndef PLANELEGIDO_H
#define PLANELEGIDO_H

#include <string>

class PlanElegido
{
public:
    PlanElegido(int id_plan = 0, const std::string& codigo_pers = "",
    int id_paquete = 0, int cantidad_paquete = 0,
    const std::string& fech_pago = "", const std::string& fech_fin = "",
    const std::string& descrip = "");

    int getIdPlanElegido() const;
    std::string getCodigoPersona() const;
    int getIdPaquete() const;
    int getCantidadPaquete() const;
    std::string getFechaPago() const;
    std::string getFechaFin() const;
    std::string getDescripcionCmpleta() const;

    void setIdPlanElegido(int id_plan_eleg);
    void setCodigoPersona(std::string codigo);
    void setIdPaquete(int id_paquete);
    void setCantidadPaquete(int cantidad);
    void setFechaPago(std::string fecha_pago);
    void setFechaFin(std::string fecha_fin);
    void setDescripcionCompleta(std::string descrip);

private:
    int id_plan_elegido;
    std::string cod_persona;
    int id_paq;
    int cantidad_paq;
    std::string fecha_pago;
    std::string fecha_finalizacion;
    std::string descripcion_completa;
};

#endif // PLANELEGIDO_H
