#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlconnection.h"
#include <vector>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    getRoles();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getRoles(){
    SqlConnection con;
    con.conOpen();

    QString sqlSentence;
    sqlSentence.append(
    "SELECT * FROM Rol"
    );

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
            rolesList.append( QString::fromStdString(roles[i].getDescription()) );
        }

        if( !rolesList.isEmpty() ){
            this->ui->cbxRoles->addItems(rolesList);
        }

    }else{
        QMessageBox::information(this, tr("Error"), tr("Couldn't get roles"));
    }


    con.conClose();
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
    con.conOpen();

    int rolId = 0;
    QString email = "", password = "", selectedRol = "";
    email = this->ui->txtUser->text();
    password = this->ui->txtPassword->text();
    selectedRol = this->ui->cbxRoles->currentText();
    rolId = getCurrentSelectedRolId(selectedRol.toStdString());

    QString sqlSentence;
    sqlSentence.append(
    "SELECT * FROM Usuario WHERE "
    "usuario = '" + email +"', "+
    "clave = '" + password + "', "+
    "id_rol = " + QString::number(rolId) + "");

    QSqlQuery query;
    query.prepare(sqlSentence);

    if(query.exec()){
        int count = 0;
        while(query.next()){
            count++;
        }

        if(count == 1){
            QMessageBox::information(this, tr("Success"), tr("Welcome to Gold's Gym"));

        }else if(count > 1){
            QMessageBox::information(this, tr("Error"), tr("Duplicated User"));
        }else{
            QMessageBox::information(this, tr("Error"), tr("Wrong user or password"));
        }
    }

    con.conClose();
}


void MainWindow::on_btnRegistrarse_clicked()
{
    SqlConnection con;
    con.conOpen();

    //get data
    int rolId = 0;
    QString email = "", password = "", selectedRol="";
    email = this->ui->txtUser->text();//or name
    password = this->ui->txtPassword->text();
    selectedRol = this->ui->cbxRoles->currentText();
    rolId = getCurrentSelectedRolId(selectedRol.toStdString());


    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO Usuario"
    "(id_usuario, usuario, clave, id_rol)"
    "VALUES(left(uuid(),10), '" + email + "', '" + password + "', " + QString::number(rolId) +")"
    );

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        QMessageBox::information(this, tr("Saved"), tr("User created successfully"));
    }else{
        qDebug() << query.lastError().text();
        QMessageBox::information(this, tr("Error"), tr("User couldn't be created"));
    }


    con.conClose();
}

