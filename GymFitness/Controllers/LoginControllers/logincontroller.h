#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <QString>
#include <QComboBox>
#include <vector>
#include <string>
#include <QMessageBox>
#include <iomanip>
#include "mainwindow.h"
#include "Models/rol.h"
#include "sqlconnection.h"

#include <sstream>
#include <openssl/sha.h>
#include <openssl/err.h>
class LoginController
{
public:
    static LoginController& getInstance(){
        static LoginController instance;
        return instance;
    }

    void getRoles(SqlConnection *con, QComboBox *cbx,
        std::vector<Rol>& roles, QWidget *mainwindow);


    int logInUser( const QString& email, const QString& password, int rolId,
                SqlConnection *con);


    bool registerUser(const QString& email, const QString& password, int RolId,
                SqlConnection *con);


    std::string cipherMEssage(const std::string &sttr);
private:
    LoginController(){}
};

#endif // LOGINCONTROLLER_H
