#ifndef PERSONCONTROLLER_H
#define PERSONCONTROLLER_H
#include <QTableWidget>

#include <QString>
#include <vector>
#include <string>
#include <iomanip>

#include <Models/persona.h>
#include "sqlconnection.h"


class PersonController
{

public:
    static PersonController& getInstance(){
        static PersonController instance;
        return instance;
    }


    //std::vector<Persona>
    void getAllUsers(SqlConnection *con, std::vector<Persona>& clientes);

    ///this functions searches user by its code
    ///only within the management tab
    Persona searchUser(SqlConnection *con, const QString& cod_persona);
private:
    PersonController(){};
};

#endif // PERSONCONTROLLER_H
