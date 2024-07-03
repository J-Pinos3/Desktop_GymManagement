#include "gymoperations.h"
#include "ui_gymoperations.h"

GymOperations::GymOperations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GymOperations)
{
    /**
    * HERE THERE WILL BE A FUNCTION TO LIST ALL CUSTOMERS
    * ADD A FUNCTION THAT TAKES ROL ID AND RETURNS THE CORRESPONDING ROL'S DESCRIPTION
    */
    ui->setupUi(this);
}

GymOperations::~GymOperations()
{
    delete ui;
}


void GymOperations::listAllCustomers(){
    SqlConnection con;
    PersonController& personController = PersonController::getInstance();

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

        ui->tblWidCustomersIntro->setItem(
        i,4, new QTableWidgetItem( QString::number(personas[i].getRol()) )
        );
    }
    //añadir los campos de la tabla plan elegido

}

void GymOperations::on_btnCustomerSearchIntro_clicked()
{
    SqlConnection con;

    QString userCode = "";
    userCode = ui->txtPersonCodeSearchIntro->text();

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

    ui->tblWidCustomersIntro->setItem( 0, 4,
        new QTableWidgetItem( QString::number(currentUser.getRol()) )
    );

    //añadir los campos de la tabla plan elegido
}

