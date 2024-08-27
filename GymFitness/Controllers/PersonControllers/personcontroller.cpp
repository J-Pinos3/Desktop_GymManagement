#include "personcontroller.h"

void PersonController::getRolesForCustomers(SqlConnection *con,
    std::vector<Rol>& roles){

    con->conOpen();

    QString sqlSentence;
    sqlSentence.append("SELECT * FROM Rol");

    QSqlQuery query;
    query.prepare(sqlSentence);
    if( query.exec() ){
        while( query.next() ){
            roles.push_back(
                Rol(
                    query.value(0).toInt(),
                    query.value(1).toString().toStdString()
                )
            );
        }
    }

    con->conClose();
}


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

                )
            );
        }
        //añadir los campos de la tabla plan Elegido;
    }


    con->conClose();
}//GET ALL USERS


Persona PersonController::searchUser(SqlConnection *con, const QString& cod_persona){

    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "SELECT * FROM Persona WHERE cod_persona = '" + cod_persona + "';");

    QSqlQuery query;
    query.prepare(sqlSentence);

    int results = 0;
    Persona buscado;

    if(query.exec()){
        while(query.next()){
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
        }

    }else{
    qDebug() <<"Error searching that user: "<< query.lastError().text();

        buscado.setCodigo("0000");

        buscado.setNombre("Jhon");

        buscado.setApellido("Doe");

        buscado.setFechaRegistro("2024-04-25");

        buscado.setPeso(0.0);

        buscado.setRol(0);
    }

    con->conClose();
    return buscado;
}//SEARCH USER


void PersonController::searchUsersWithFields(SqlConnection *con,
    std::vector<Persona>& clientes, const QString& nombre,
    const QString& apellido, const QString& codigo){

    con->conOpen();
    QString sqlSentence;

    if (nombre == ""){
        sqlSentence.append(
        "SELECT * FROM Persona WHERE "
        "apellido = '" + apellido + "' OR "
        "cod_persona = '" + codigo + "' ");

    }else if(apellido == ""){
        sqlSentence.append(
        "SELECT * FROM Persona WHERE "
        "nombre = '" + nombre + "' OR "
        "cod_persona = '" + codigo + "' ");

    }else if(codigo == ""){
        sqlSentence.append(
        "SELECT * FROM Persona WHERE "
        "nombre = '" + nombre + "' OR "
        "apellido = '" + apellido + "' ");

    }else if(nombre == "" && apellido == "" && codigo == "" ){
        sqlSentence.append( "SELECT * FROM Persona WHERE" );

    }else{
        sqlSentence.append(
        "SELECT * FROM Persona WHERE "
        "nombre = '" + nombre + "' AND "
        "apellido = '" + apellido + "' AND"
        "cod_persona = '" + codigo + "' ");
    }

    QSqlQuery query;
    query.prepare(sqlSentence);
    if(query.exec()){
        while(query.next()){
            clientes.push_back(
                Persona(
                    query.value("cod_persona").toString().toStdString(),
                    query.value("nombre").toString().toStdString(),
                    query.value("apellido").toString().toStdString(),
                    query.value("fecha_registro").toString().toStdString(),
                    query.value("peso").toDouble(),
                    query.value("id_rol").toInt()

                )
            );
        }
        //añadir los campos de la tabla plan Elegido;
    }


    con->conClose();
}//SEARCH USERS WITH FIELDS


bool PersonController::registerCustomer(SqlConnection *con, const QString& nombre,
    const QString& apellido, double peso, const QString& fechaRegistro, int rol){

    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO Persona"
    "(cod_persona, nombre, apellido,"
    "peso, fecha_registro, id_rol)"
    "VALUES(left(uuid(),10), '"+ nombre + "', '" + apellido + "', "
    ""+ QString::number(peso) +", '"+ fechaRegistro +"', "
    "" + QString::number(rol) + ")"
    );

    QSqlQuery query;
    query.prepare(sqlSentence);
    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error creating a customer: " << query.lastError().text();
    }
    con->conClose();
    return execution;
}//REGISTER CUSTOMER


