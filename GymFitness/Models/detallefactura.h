#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H

#include <string>

#include "Models/planelegido.h"
#include "Models/servicioelegido.h"

class DetalleFactura
{
public:
    DetalleFactura(int id_det_fac = 0, double total_det_fac = 0.0,
        int id_cab_fac = 0, const PlanElegido& plan_eleg = PlanElegido(),
        const ServicioElegido& serv_eleg = ServicioElegido(),
        const std::string& nombre = "");



    int getIdDetalleFact() const;
    double getTotalDetalleFact() const;
    int getIdCabFactura() const;

    void setIdDetalleFact(int id_det_fac);
    void setTotalDetalleFact(double total_det_fac);
    void setIdCabFactura(int id_cab_fac);

    //para las citas
    std::string getNombrePaciente() const;
    void setNombrePaciente(const std::string& nombre);

    PlanElegido plan;
    ServicioElegido servicio;
private:
    int id_deta_factura;
    double total_deta_factura;
    int id_cab_factura;

    std::string nombre_paciente;
};

#endif // DETALLEFACTURA_H
