#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H


class DetalleFactura
{
public:
    DetalleFactura(int id_det_fac = 0, double total_det_fac = 0.0,
        int id_cab_fac = 0);

    int getIdDetalleFact() const;
    double getTotalDetalleFact() const;
    int getIdCabFactura() const;

    void setIdDetalleFact(int id_det_fac);
    void setTotalDetalleFact(double total_det_fac);
    void setIdCabFactura(int id_cab_fac);

private:
    int id_deta_factura;
    double total_deta_factura;
    int id_cab_factura;
};

#endif // DETALLEFACTURA_H
