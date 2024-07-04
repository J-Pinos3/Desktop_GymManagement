#ifndef PERSONCONTROLLER_H
#define PERSONCONTROLLER_H
#include <QTableWidget>

#include <QString>
#include <vector>
#include <string>
#include <iomanip>

#include <Models/persona.h>
#include <Models/rol.h>
#include "sqlconnection.h"


class PersonController
{

public:
    static PersonController& getInstance(){
        static PersonController instance;
        return instance;
    }


    void getRolesForCustomers(SqlConnection *con, std::vector<Rol>& roles);


    void getAllUsers(SqlConnection *con, std::vector<Persona>& clientes);

    Persona searchUser(SqlConnection *con, const QString& cod_persona);

    bool registerCustomer(SqlConnection *con, const QString& nombre, const QString& apellido,
        double peso, const QString& fechaRegistro, int rol);

    void searchUsersWithFields(SqlConnection *con, std::vector<Persona>& clientes,
        const QString& nombre = "", const QString& apellido = "",
        const QString& codigo = "");
private:
    PersonController(){};
};

#endif // PERSONCONTROLLER_H
