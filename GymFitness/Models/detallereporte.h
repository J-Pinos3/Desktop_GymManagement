#ifndef DETALLEREPORTE_H
#define DETALLEREPORTE_H

#include <string>

class DetalleReporte
{
public:
    DetalleReporte(int id_deta_fact = 0, double total_det_fac = 0.0,
        const std::string& det_descfrip = "",
        const std::string& nom_cli = "",
        const std::string& fech_report = "");

    int getIdDetalleReporte() const;
    double getTotalDetalleReporte() const;

    void setIdDetalleReporte(int id_det_fac_repo);
    void setTotalDetalleReporte(double total_det_fac_repo);

    std::string getDetalleReporte() const;
    void setDetalleReporte(const std::string& detalleDescrip);

    std::string getNombreCliente() const;
    void setNombreCliente(const std::string& nombreCli);

    std::string getFecha() const;
    void setFecha(const std::string& fecha_repo);

private:
    int id_deta_factura;
    double total_deta_factura;

    std::string detalle;
    std::string nombre;
    std::string fecha;
};

#endif // DETALLEREPORTE_H
