#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>

class Servicio{

public:
    Servicio(): id_serv(0), serv_titulo(""), precio(0.0) {};

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
