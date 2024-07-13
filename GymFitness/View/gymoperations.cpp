#include "gymoperations.h"
#include "ui_gymoperations.h"

GymOperations::GymOperations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GymOperations)
{

    ui->setupUi(this);

    setCustomersRoleDescription();
    listAllCustomers();
}

GymOperations::~GymOperations()
{
    delete ui;
}

void GymOperations::getValuesfromManageFields(QString& nombre, QString& apellido,
        QString& fechaRegistro, double& peso, int& rolId){


    nombre = ui->txtManageName->text().isNull() || ui->txtManageName->text().isEmpty()
        ? "" : ui->txtManageName->text();

    apellido = ui->txtManageLastName->text().isNull() || ui->txtManageLastName->text().isEmpty()
        ? "" : ui->txtManageLastName->text();

    fechaRegistro = ui->manageInscriptionDate->date().isNull() || ui->manageInscriptionDate->date().toString().isEmpty()
        ? "0000-00-00" :  ui->manageInscriptionDate->date().toString("yyyy-MM-dd");

    peso = ui->txtManageWeight->text().toDouble() < 0.0 ? 0.0 : ui->txtManageWeight->text().toDouble();

    rolId = 1;
}

void GymOperations::setCustomersRoleDescription(){
    SqlConnection con;
    PersonController& personController = PersonController::getInstance();

    personController.getRolesForCustomers(&con, roles);
}

void GymOperations::listAllCustomers(){

    QString userRoleDescription = "";
    std::vector<Rol>::iterator it = roles.begin();
    SqlConnection con;
    PersonController& personController = PersonController::getInstance();

    personas.clear();
    ui->tblWidCustomersIntro->clearContents();
    personController.getAllUsers(&con, personas);

    ui->tblWidCustomersIntro->setRowCount(personas.size());
    for(int i = 0; i < personas.size(); i++ ){
        ui->tblWidCustomersIntro->setItem(
        i,0, new QTableWidgetItem( QString::fromStdString(personas[i].getCodigo()) )
        );

        ui->tblWidCustomersIntro->setItem(
        i,1, new QTableWidgetItem( QString::fromStdString(personas[i].getNombre() + " " + personas[i].getApellido()) )
        );

        ui->tblWidCustomersIntro->setItem(
        i,2, new QTableWidgetItem( QString::number(personas[i].getPeso()) )
        );

        ui->tblWidCustomersIntro->setItem(
        i,3, new QTableWidgetItem( QString::fromStdString(personas[i].getFechaRegistro()) )
        );

        for(it; it != roles.end(); it++){
            if(it->getId() == personas[i].getRol()){
                userRoleDescription =  QString::fromStdString( (*it).getDescription() );
            }
        }

        ui->tblWidCustomersIntro->setItem(
        i,4, new QTableWidgetItem( userRoleDescription )
        );
    }
    //añadir los campos de la tabla plan elegido

}


void GymOperations::on_btnCustomerSearchIntro_clicked()
{
    QString userRoleDescription = "";
    std::vector<Rol>::iterator it = roles.begin();
    SqlConnection con;

    QString userCode = "";
    userCode = ui->txtPersonCodeSearchIntro->text();

    ui->tblWidCustomersIntro->clearContents();

    PersonController& personController = PersonController::getInstance() ;
    Persona currentUser = personController.searchUser(&con, userCode);

    ui->tblWidCustomersIntro->setRowCount(1);

    ui->tblWidCustomersIntro->setItem( 0, 0,
        new QTableWidgetItem( QString::fromStdString(currentUser.getCodigo()) )
    );

    ui->tblWidCustomersIntro->setItem( 0, 1,
        new QTableWidgetItem( QString::fromStdString(currentUser.getNombre() + " " + currentUser.getApellido()) )
    );

    ui->tblWidCustomersIntro->setItem( 0, 2,
        new QTableWidgetItem( QString::number( currentUser.getPeso() ) )
    );

    ui->tblWidCustomersIntro->setItem( 0, 3,
        new QTableWidgetItem( QString::fromStdString(currentUser.getFechaRegistro()) )
    );


    for(it; it != roles.end(); it++){
        if(it->getId() == currentUser.getRol()){
            userRoleDescription = QString::fromStdString( it->getDescription() );
        }
    }

    ui->tblWidCustomersIntro->setItem( 0, 4,
        new QTableWidgetItem( userRoleDescription )
    );

    //añadir los campos de la tabla plan elegido
}


void GymOperations::on_btnAllCustomers_clicked()
{
    listAllCustomers();
}


void GymOperations::on_btnManageSave_clicked()
{
    QString nombre = "", apellido = "", fechaRegistro = "";
    double peso = 0.0;
    int rolId= 1;

    SqlConnection con;
    PersonController& personController = PersonController::getInstance();

    //if cbx is checked, it means create a new user, so dont enter user code
    if( ui->cbxManageNew->isChecked() == true ){
        ui->txtManageCode->setReadOnly(true);//generate one

        getValuesfromManageFields(nombre, apellido, fechaRegistro, peso, rolId);
        //bool executionResult = personController.registerCustomer(&con, nombre, apellido, peso, fechaRegistro, rolId);
        qDebug() << fechaRegistro << "\n";
        //if(executionResult){
        if(true){
            QMessageBox::information(this, tr("Saved"), tr("Customer added successfully"));
            listAllCustomers();
        }else{
            QMessageBox::information(this, tr("Error"), tr("Customer couldn't be created"));
        }
    }else{
        //if not cbx is not checked, it means update or search user so enter user code
        ui->txtManageCode->setReadOnly(false);
    }
}

