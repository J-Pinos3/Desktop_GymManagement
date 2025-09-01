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
    sqlSentence.append(
    "SELECT\n"
    "Pers.cod_persona, Pers.nombre,\n"
    "Pers.apellido, Pers.peso,\n"
    "Pers.fecha_registro, Pers.id_rol,\n"
    "Ple.fecha_pago,\n"
    "Ple.fecha_finalizacion\n"
    "FROM CabeceraFactura as CabFac\n"
    "INNER JOIN Persona as Pers on Pers.cod_persona = CabFac.cod_persona\n"
    "INNER JOIN DetalleFactura as Detf on Detf.id_cab_fact = CabFac.id_cab_fact\n"
    "INNER JOIN PlanElegido as Ple on Ple.id_deta_fact = Detf.id_deta_fact\n"
    "ORDER BY Ple.fecha_finalizacion DESC;" );

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
                    query.value("fecha_pago").toString().toStdString(),
                    query.value("fecha_finalizacion").toString().toStdString(),
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
            if( query.value("cod_persona").toString().isNull() || query.value("cod_persona").toString().isEmpty() ){
                buscado.setCodigo("0000");

                buscado.setNombre("Anonimo");    buscado.setApellido("Anonimo");

                buscado.setFechaRegistro("2024-04-25");

                buscado.setPeso(0.0);   buscado.setRol(0);
            }
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

        buscado.setNombre("Anonimo");

        buscado.setApellido("Anonimo");

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
        "SELECT * FROM Persona WHERE cod_persona = '" + codigo + "'; ");

    }else if(codigo == ""){
        sqlSentence.append(
        "SELECT * FROM Persona WHERE nombre = '" + nombre + "';");

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
                    "","",
                    query.value("peso").toDouble(),
                    query.value("id_rol").toInt()

                )
            );
        }
        //añadir los campos de la tabla plan Elegido;
    }else{
    qDebug() <<"Error searchinng a customer: " << query.lastError().text();
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


bool PersonController::updateExistingCustomer(SqlConnection *con, const Persona& persona){

    con->conOpen();
    QString nombre = "", apellido = "", fecha_Nac = "", cod="";
    double peso = 0.0;
    nombre = QString::fromStdString( persona.getNombre() );
    apellido = QString::fromStdString( persona.getApellido() );
    fecha_Nac = QString::fromStdString( persona.getFechaRegistro() );
    cod = QString::fromStdString( persona.getCodigo() );
    peso = persona.getPeso();
    QString sqlSentence;
    sqlSentence.append(
    "UPDATE Persona\n"
    "SET nombre = '" + nombre + "',\n"
    "apellido = '"+ apellido + "',\n"
    "peso = "+ QString::number(peso) + ",\n"
    "fecha_registro = '"+ fecha_Nac + "' WHERE cod_persona='" + cod + "';"
    );

    QSqlQuery query;
    query.prepare(sqlSentence);
    bool execution = query.exec();

    if( !query.lastError().text().isNull() ){
        qDebug() <<"Error updating a customer: " << query.lastError().text();
    }
     qDebug() <<"Update customer result: " << execution;
    con->conClose();

    return execution;
}//UPDATE EXISTING CUSTOMER

