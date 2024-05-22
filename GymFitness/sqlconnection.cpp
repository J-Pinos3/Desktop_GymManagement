#include "sqlconnection.h"
#include <QMessageBox>

SqlConnection::SqlConnection()
{

}


void SqlConnection::conOpen(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("blindGuardian1");
    db.setPort(3307);
    db.setDatabaseName("gym_management");

    if( db.open() ){

        qDebug() << "Conexion exitosa con la bd";

    }else{
        qDebug() << "No se pudo realizar la conexion";
    }
}


void SqlConnection::conClose(){
    db.close();
    qDebug() << "Conexion Cerrada";
}
