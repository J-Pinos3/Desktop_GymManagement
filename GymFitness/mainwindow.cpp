#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlconnection.h"
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

void MainWindow::on_btnLogearse_clicked()
{
    SqlConnection con;
    con.conOpen();
}


void MainWindow::on_btnRegistrarse_clicked()
{
    SqlConnection con;
    con.conOpen();

    //get data
    QString email = "", password = "";
    email = this->ui->txtUser->text();
    password = this->ui->txtPassword->text();

    QString sqlSentence;
    sqlSentence.append(
    "INSERT INTO Usuario"
    "(usuario, clave)"
    "VALUES('" + email + "', '" + password + "')"
    );

    QSqlQuery query;
    query.prepare(sqlSentence);

    if( query.exec() ){
        QMessageBox::information(this, tr("Saved"), tr("User created successfully"));
    }else{
        QMessageBox::information(this, tr("Error"), tr("User couldn't be created"));
    }


    con.conClose();
}

