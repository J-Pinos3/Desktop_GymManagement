#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>

class Servicio{

public:
    Servicio(int id_servicio = 0, const std::string& titulo = "",
    double precio = 0.0):
    id_serv(id_servicio), serv_titulo(titulo), precio(precio) {};

    int getIdServicio() const;
    std::string getTituloServicio() const;
    double getPrecioServicio() const;

    void setIdServicio(int id);
    void setTituloPaquete(const std::string& titulo);
    void setPrecioPaquete(double precio);

private:
    int id_serv;
    std::string serv_titulo;
    double precio;

};


#endif // SERVICIO_H
