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
    QMessageBox msg = QMessageBox();
    email = this->ui->txtUser->text();
    password = this->ui->txtPassword->text();
    selectedRol = this->ui->cbxRoles->currentText();
    rolId = getCurrentSelectedRolId(selectedRol.toStdString());

    LoginController& loginController = LoginController::getInstance();


    QString cipheredPassword = QString::fromStdString( loginController.cipherMEssage( password.toStdString() ) );


    int count = loginController.logInUser(email, cipheredPassword, rolId, &con);

    msg.setWindowTitle("Iniciar Sesión");
    msg.setWindowIcon( QIcon(":/images/Images/GoldenGym3.png") );
    msg.setStyleSheet("color:black; background:white");

    if(count == 1){
        msg.setText("Bienvenido a Gold's Gym");  msg.setIcon(QMessageBox::Information);
        msg.exec();
        this->hide();
        GymOperations* gymOperations = new GymOperations();
        gymOperations->show();

    }else if(count > 1){
        msg.setText("Ese usuario ya existe");  msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }else{
        msg.setText("Usuario o contraseña incorrectos");  msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }



}


void MainWindow::on_btnRegistrarse_clicked()
{
    SqlConnection con;

    //get data
    int rolId = 0;
    QString email = "", password = "", selectedRol="";
    QMessageBox msg = QMessageBox();
    email = this->ui->txtUser->text();//or name
    password = this->ui->txtPassword->text();
    selectedRol = this->ui->cbxRoles->currentText();
    rolId = getCurrentSelectedRolId(selectedRol.toStdString());

    LoginController& loginController = LoginController::getInstance();

    QString cipheredPass = QString::fromStdString( loginController.cipherMEssage(password.toStdString())  );

    msg.setWindowTitle("Registrarse");
    msg.setWindowIcon( QIcon(":/images/Images/GoldenGym3.png") );
    msg.setStyleSheet("color:black; background:white");

    bool executionResult = loginController.registerUser(email, cipheredPass, rolId, &con);

    if( executionResult ){
        msg.setText("Usuario creado exitosamente");  msg.setIcon(QMessageBox::Information);
        msg.exec();
    }else{
        msg.setText("No se pudo crear el usuario");  msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}

