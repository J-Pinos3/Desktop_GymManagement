#ifndef SERVICIOELEGIDO_H
#define SERVICIOELEGIDO_H

#include <string>

class ServicioElegido
{
public:
    ServicioElegido():id_serv_elegido(0), id_serv(0),
        num_sesiones(0), fecha_serv(""), titulo_serv(""){};

    int getIdServElegido() const;
    int getIdServicio() const;
    int getNumSesiones() const;
    std::string getFechaServ() const;
    std::string getTituloServ() const;

    void setIdServElegido(int id_serv_eleg);
    void setIdServicio(int id_servicio);
    void setNumSesiones(int num_ses);
    void setFechaServ(std::string fech_serv);
    void setTituloServ(std::string titulo_serv);

private:
    int id_serv_elegido;
    int id_serv;
    int num_sesiones;
    std::string fecha_serv;
    std::string titulo_serv;
};

#endif // SERVICIOELEGIDO_H
