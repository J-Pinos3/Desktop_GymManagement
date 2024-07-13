#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlconnection.h"
#include "View/gymoperations.h"
#include <vector>
#include <string>
#include <QMessageBox>

#include "Controllers/LoginControllers/logincontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SqlConnection con;

    LoginController& loginController = LoginController::getInstance();
    loginController.getRoles(&con, this->ui->cbxRoles, roles, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::getCurrentSelectedRolId(const std::string &descriptionRol) {
    std::vector<Rol>::iterator it = roles.begin();
    for(it ;  it != roles.end(); it++){
        if(it->getDescription() == descriptionRol){
            return( (*it).getId() );
        }
    }
}


void MainWindow::on_btnLogearse_clicked()
{
    SqlConnection con;

    int rolId = 0;
    QString email = "", password = "", selectedRol = "";
    email = this->ui->txtUser->text();
    password = this->ui->txtPassword->text();
    selectedRol = this->ui->cbxRoles->currentText();
    rolId = getCurrentSelectedRolId(selectedRol.toStdString());

    LoginController& loginController = LoginController::getInstance();


    QString cipheredPassword = QString::fromStdString( loginController.cipherMEssage( password.toStdString() ) );


    int count = loginController.logInUser(email, cipheredPassword, rolId, &con);

    if(count == 1){
        QMessageBox::information(this, tr("Success"), tr("Welcome to Gold's Gym"));
        this->hide();
        GymOperations* gymOperations = new GymOperations();
        gymOperations->show();

    }else if(count > 1){
        QMessageBox::information(this, tr("Error"), tr("Duplicated User"));
    }else{
        QMessageBox::information(this, tr("Error"), tr("Wrong user or password"));
    }



}


void MainWindow::on_btnRegistrarse_clicked()
{
    SqlConnection con;

    //get data
    int rolId = 0;
    QString email = "", password = "", selectedRol="";
    email = this->ui->txtUser->text();//or name
    password = this->ui->txtPassword->text();
    selectedRol = this->ui->cbxRoles->currentText();
    rolId = getCurrentSelectedRolId(selectedRol.toStdString());

    LoginController& loginController = LoginController::getInstance();

    QString cipheredPass = QString::fromStdString( loginController.cipherMEssage(password.toStdString())  );

    bool executionResult = loginController.registerUser(email, cipheredPass, rolId, &con);

    if( executionResult ){
        QMessageBox::information(this, tr("Saved"), tr("User created successfully"));
    }else{

        QMessageBox::information(this, tr("Error"), tr("User couldn't be created"));
    }

}

