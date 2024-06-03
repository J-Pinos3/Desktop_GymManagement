#include "logincontroller.h"

std::string LoginController::cipherMEssage(const std::string &sttr){
    unsigned char hash [SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, sttr.c_str(), sttr.size() );
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    }

    return ss.str();
}


void LoginController::getRoles(
    SqlConnection *con, QComboBox *cbx, std::vector<Rol>& roles,
    QWidget *mainwindow){

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


        QList<QString> rolesList;
        for(int i = 0; i < roles.size(); i++){
            rolesList.append( QString::fromStdString( roles[i].getDescription() ) );
        }

        if( !rolesList.isEmpty() ){
            cbx->addItems(rolesList);
        }

    }
    else{
        QMessageBox::information(mainwindow, "Error", "Couldn't get roles");
    }

    con->conClose();

}






int LoginController::logInUser( const QString& email,
                const QString& password, int rolId,
                SqlConnection *con){


    con->conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "SELECT * FROM Usuario WHERE "
    "usuario = '" + email + "' AND " +
    "clave = '" + password+ "' AND " +
    "id_rol = " + QString::number(rolId) + "" );

    int count = 0;

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        while( query.next() ){
            count++;
        }
    }else{
        qDebug() << query.lastError().text() << count;
    }

    con->conClose();
    return count;
}





bool LoginController::registerUser( const QString& email,
                const QString& password, int rolId,
                 SqlConnection *con  ){

    con->conOpen();
    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO Usuario"
    "(id_usuario, usuario, clave, id_rol)"
    "VALUES(left(uuid(),10), '" + email + "', '" + password + "', " + QString::number(rolId) +")"
    );

    QSqlQuery query;
    query.prepare(sqlSentence);

    bool execution = query.exec();
    if( !query.lastError().text().isNull() ){
        qDebug() << query.lastError().text();
    }

    con->conClose();

    return execution;
}
