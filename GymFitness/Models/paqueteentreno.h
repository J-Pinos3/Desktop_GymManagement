#ifndef PAQUETEENTRENO_H
#define PAQUETEENTRENO_H
#include <string>


class PaqueteEntreno
{
public:
    PaqueteEntreno(int id_paquete = 0, const std::string& descrip ="",
    double precio = 0, int dias = 0);


    std::string getDescriptionPaquete() const;
    int getIdPaquete() const;
    int getDiasPaquete() const;
    double getPrecioPaquete() const;

    void setDescripcionPaquete(const std::string& descripcion);
    void setIdPaquete(int id);
    void setDiasPaquete(int dias);
    void setPrecioPaquete(double precio);

private:
    int id_paq;
    std::string descripcion;
    double precio;
    int dias;
};

#endif // PAQUETEENTRENO_H
