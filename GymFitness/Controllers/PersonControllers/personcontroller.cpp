#include "personcontroller.h"


void PersonController::getAllUsers(SqlConnection *con, std::vector<Persona>& clientes){
    con->conOpen();

    QString sqlSentence;
    sqlSentence.append("SELECT * FROM Persona");

    QSqlQuery query;
    query.prepare(sqlSentence);


    if(query.exec()){

        while( query.next() ){
            clientes.push_back(
                Persona(
                    query.value("cod_persona").toString().toStdString(),
                    query.value("nombre").toString().toStdString(),
                    query.value("apellido").toString().toStdString(),
                    query.value("fecha_registro").toString().toStdString(),
                    query.value("peso").toDouble(),
                    query.value("id_rol").toInt()
                    //añadir los campos de la tabla plan Elegido;
                )
            );
        }
    }


    con->conClose();
}


Persona PersonController::searchUser(SqlConnection *con, const QString& cod_persona){

    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "SELECT * FROM Usuario WHERE "
    "cod_persona = '" + cod_persona + "'");

    QSqlQuery query;
    query.prepare(sqlSentence);

    int results = 0;
    Persona buscado;

    if(query.exec()){
        while(query.next()){
            results++;
        }

        if(results == 1){
            buscado.setCodigo(
                query.value("cod_persona").toString().toStdString());

            buscado.setNombre(
                query.value("nombre").toString().toStdString());

            buscado.setApellido(
                query.value("apellido").toString().toStdString());

            buscado.setFechaRegistro(
                query.value("fecha_registro").toString().toStdString());

            buscado.setPeso(query.value("peso").toDouble());

            buscado.setRol( query.value("id_rol").toInt());
        }else{
            buscado.setCodigo("0000");

            buscado.setNombre("Jhon");

            buscado.setApellido("Doe");

            buscado.setFechaRegistro("2024-04-25");

            buscado.setPeso(0.0);

            buscado.setRol(0);
        }
    }

    con->conClose();
    return buscado;
}
