#include "gymoperations.h"
#include "ui_gymoperations.h"

#include "SmtpMime"

#include <QSettings>

#include <QPdfWriter>
#include <QPainter>

#include <QFont>
#include <QFileDialog>

GymOperations::GymOperations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GymOperations)
{

    ui->setupUi(this);

    connect( ui->tblWidPaymentInvoice, SIGNAL(cellClicked(int,int)), this, SLOT(on_tblWidPaymentInvoice_cellActivated(int, int)) );
    connect( ui->tblWidPaymentLine,    SIGNAL(cellClicked(int,int)), this, SLOT(on_tblWidPaymentLine_cellActivated(int, int)) );
    connect( ui->tblWidAppointInvoice, SIGNAL(cellClicked(int, int)), this, SLOT(on_tblWidAppointInvoice_cellActivated(int, int)) );
    connect( ui->tblWidAppointLine, SIGNAL(cellClicked(int,int)), this, SLOT(on_tblWidAppointLine_cellActivated(int, int)) );
    connect(ui->tblAllInvoices, SIGNAL(cellClicked(int,int)), this, SLOT(on_tblAllInvoices_cellActivated(int, int)) );

    setCustomersRoleDescription();
    listAllCustomers();
    getTrainingPackages();
    getAllGymServices();
}

GymOperations::~GymOperations()
{
    delete ui;
}

int GymOperations::getCurrentSelectedPackageId(const std::string &descriptionPackage){
    std::vector<PaqueteEntreno>::iterator it = paquetes.begin();
    for( it; it != paquetes.end(); it++ ){
        if(it->getDescriptionPaquete() == descriptionPackage){
            return it->getIdPaquete();
        }
    }
}

int GymOperations::getCurrentSelectedGymServiceId(const std::string &tituloServicio){
    std::vector<Servicio>::iterator it = servicios.begin();
    for(; it != servicios.end(); it++){
        if(it->getTituloServicio() == tituloServicio){
            return (*it).getIdServicio();
        }
    }

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


//INTRO TAB
void GymOperations::on_btnCustomerSearchIntro_clicked()
{
    QString userRoleDescription = "";
    std::vector<Rol>::iterator it = roles.begin();
    SqlConnection con;

    QString userCode = "";
    userCode = ui->txtPersonCodeSearchIntro->text();
    qDebug() << "\tUSER CODE: " <<  userCode <<"\n";

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


//MANAGEMENT TAB
void GymOperations::on_btnManageSave_clicked()
{
    QString nombre = "", apellido = "", fechaRegistro = "";
    double peso = 0.0;
    int rolId= 1;

    SqlConnection con;
    PersonController& personController = PersonController::getInstance();

    getValuesfromManageFields(nombre, apellido, fechaRegistro, peso, rolId);
    bool executionResult = personController.registerCustomer(&con, nombre, apellido, peso, fechaRegistro, rolId);
    qDebug() << fechaRegistro << "\n";
    if(executionResult){
        QMessageBox::information(this, tr("Saved"), tr("Customer added successfully"));
        listAllCustomers();
    }else{
        QMessageBox::information(this, tr("Error"), tr("Customer couldn't be created"));
    }

}

void GymOperations::on_btnManageCancel_clicked()
{
    ui->txtManageName->setText("");
    ui->txtManageLastName->setText("");
    ui->txtManageWeight->setText("0.0");
    ui->txtManageCode->setText("");
    ui->manageInscriptionDate->setDate( QDate::currentDate() );
}

void GymOperations::on_btnManageSearch_clicked()
{
    QString nombre = "", apellido = "", codigo = "", fechaRegistro = "";
    QString userRoleDescription = "";
    double peso = 0.0;
    int rolId= 1;

    std::vector<Rol>::iterator it = roles.begin();
    SqlConnection con;
    PersonController& personController = PersonController::getInstance();

    codigo = ui->txtManageCode->text();
    getValuesfromManageFields(nombre, apellido, fechaRegistro, peso, rolId);
    personas.clear();
    ui->tblWidManage->clearContents();
    personController.searchUsersWithFields(&con, personas, nombre, apellido, codigo);

    ui->tblWidManage->setRowCount(personas.size());

    for(size_t i = 0; i < personas.size(); i++){
        ui->tblWidManage->setItem(
        i, 0, new QTableWidgetItem( QString::fromStdString(personas[i].getCodigo()) ));

        ui->tblWidManage->setItem(
        i, 1, new QTableWidgetItem( QString::fromStdString(personas[i].getNombre() + " " + personas[i].getApellido()) ));

        ui->tblWidManage->setItem(
        i, 2, new QTableWidgetItem( QString::number(personas[i].getPeso()) ));

        ui->tblWidManage->setItem(
        i, 3, new QTableWidgetItem( QString::fromStdString(personas[i].getFechaRegistro()) ));

        for( ; it != roles.end(); it++){
            if( (*it).getId() == personas[i].getRol() ){
                userRoleDescription = QString::fromStdString( it->getDescription() );
            }
        }

        ui->tblWidManage->setItem(
        i, 4, new QTableWidgetItem(userRoleDescription));
    }
    //añadir los campos de la tabla plan elegido
}


//CHECKBOX MANAGE NEW SIGNAL STATECHANGED
void GymOperations::on_cbxManageNew_stateChanged(int arg1)
{
    //if cbx is checked, it means create a new user, so dont enter user code
    if(arg1 == Qt::Checked){
        ui->txtManageCode->setReadOnly(true);
    }else{
    //if cbx is unchecked, it means search or update a user data, so do enter user code
        ui->txtManageCode->setReadOnly(false);
    }
}





//PAYMENTS TAB
void GymOperations::on_btnPaymentNewInvoice_clicked()
{
    SqlConnection con;
    Factura nuevaFactura;
    PaymentControllers paymentController = PaymentControllers::getInstance();

    nuevaFactura.setFechaCabFactura(
        this->ui->paymentDatePay->date().isNull() || this->ui->paymentDatePay->date().toString().isEmpty()
        ? "0000-00-00" : this->ui->paymentDatePay->date().toString("yyyy-MM-dd").toStdString()
    );

    nuevaFactura.setTotalFactura(0.0);
    nuevaFactura.setCodPersona(this->ui->txtPaymentUserCode->text().toStdString());

    bool executionResult = paymentController.createEmptyPaymentInvoice(&con, nuevaFactura);

    if(executionResult){
        QMessageBox::information(this, "Saved", "Empty invoice created Succesfully");
        /// TODO once created the payment invoice, get its data into the table
    }else{
        QMessageBox::information(this, "Error", "Couldn't create empty invoice");
    }
}

void GymOperations::on_btnPaymentAddLine_clicked()
{
    QMessageBox msg = QMessageBox();
    SqlConnection con;
    int currentInvoice = 0;
    currentInvoice = this->ui->invoiceNumber->text().toInt();
    DetalleFactura nuevoDetalle(0, 0.0, currentInvoice );
    PaymentControllers paymentController = PaymentControllers::getInstance();

    bool executionResult = paymentController.createEmptyInvoiceLine(&con,nuevoDetalle);

    //bool executionEmptyChosenPlan = paymentController.createEmptyLineInfo(&con);

    if(executionResult){

        msg.setWindowTitle("Saved");
        msg.setText("Empty invoice line created Succesfully");
        msg.setIcon(QMessageBox::Information);
        msg.setStyleSheet("color:white;background:black");
        msg.exec();
        //QMessageBox::information(this, "Saved", "Empty invoice line created Succesfully");

        getInvoiceLinesByInvoiceId(currentInvoice);

    }else{
        msg.setWindowTitle("Error");
        msg.setText("Couldn't create empty invoice line");
        msg.setIcon(QMessageBox::Warning);
        msg.setStyleSheet("color:white;background:black");
        msg.exec();
        //QMessageBox::information(this, "Error", "Couldn't create empty invoice line");
    }

}


void GymOperations::on_btnSaveLine_clicked()
{
    SqlConnection con;
    int currentInvoiceLineId = 0;
    PaymentControllers paymentController = PaymentControllers::getInstance();
    QString selectedPackage = this->ui->cbxPaymentPackage->currentText();
    QStringList tokens = selectedPackage.split(", ");

    QString packageDescription = tokens[0];
    QRegularExpression sep("días");
    int packageDays = tokens[1].remove(sep).toInt();

    int currentInvoice = 0;
    currentInvoice = this->ui->invoiceNumber->text().toInt();

    QDate paymentDate = this->ui->paymentDatePay->date() ;
    QDate limitDate = this->ui->paymentDatePay->date().addDays(packageDays);

    QString formatedPaymentDate = QString::number( paymentDate.year() ) +
            "-" + QString::number( paymentDate.month() ) +
            "-" + QString::number( paymentDate.day() );

    QString formatedLimitDate = QString::number( limitDate.year() ) +
            "-" + QString::number( limitDate.month() ) +
            "-" + QString::number( limitDate.day() );

    //qDebug() << "PaymentDate: " << paymentDate <<" LimitDate: " << limitDate <<"\n";
    //PaymentDate:  "Fri Aug 9 2024"  LimitDate:  "Sat Aug 10 2024" this output when used QDate[Object].toString
    //else just get the numbers
    currentInvoiceLineId = this->ui->invoiceInfoLineNumber->text().toInt();

    int packageId = getCurrentSelectedPackageId(packageDescription.toStdString());
    qDebug() << "\n\t--------------------------\n"
    << currentInvoiceLineId << " ** " << packageId << "\n"
    << this->ui->sbPaymentQuantity->text().toInt() << "\n"
    << formatedPaymentDate << " ** " << formatedLimitDate
    << "\n\t--------------------------\n\n";

    bool executionResult = paymentController
        .createInvoiceLineInfo(&con,
        currentInvoiceLineId,
        packageId,
        this->ui->sbPaymentQuantity->text().toInt(),
        formatedPaymentDate, formatedLimitDate
        );

    if(executionResult){
        QMessageBox::information(this, tr("Saved"), "Line info created Succesfully");
        //update this current line

        bool updateLineResult = paymentController
        .updateInvoiceLineInfo(&con, currentInvoiceLineId);
        if(updateLineResult){
            QMessageBox::information(this, "Saved", "Line total updated succesfully");
        }else{
            QMessageBox::information(this, "Error", "Couldn't update the total of this line");
        }

        getInvoiceLinesByInvoiceId(currentInvoice);
        /// TODO once created the invoice line, get its data into the table
    }else{
        QMessageBox::information(this, "Error", "Couldn't create line info");
    }

}


void GymOperations::on_btnPaymentSaveAll_clicked()
{
    SqlConnection con;
    int currentHeader = 0;
    PaymentControllers paymentController = PaymentControllers::getInstance();
    currentHeader = this->ui->invoiceNumber->text().toInt();

    bool executionResult = paymentController.updatePaymentInvoice(&con, currentHeader);
    if( executionResult ){
        QMessageBox::information(this, "Saved", "Invoice Header update succesfully");
        getAllPaymentInvoicesFromDB();
    }else{
        QMessageBox::information(this, "Error", "Couldn't update header with its lines");
    }
    //This function should call teh stored procedure to update the invoice header
}


void GymOperations::getTrainingPackages(){
    SqlConnection con;
    PaymentControllers paymentController = PaymentControllers::getInstance();

    paymentController.getTrainingPackages(&con, paquetes);

    QList<QString> packagesList;
    if( !paquetes.empty() ){
        for(int i = 0; i < paquetes.size(); i++){
            packagesList.append(
             QString::fromStdString(paquetes[i].getDescriptionPaquete()) +
             ", " + QString::number(paquetes[i].getDiasPaquete()) +
             "días, USD" + QString::number( paquetes[i].getPrecioPaquete() ) + " $."
            );
        }
    }

    if( !packagesList.isEmpty() ){
        this->ui->cbxPaymentPackage->addItems( packagesList );
    }

}


void GymOperations::getAllPaymentInvoicesFromDB(){
    SqlConnection con;
    PaymentControllers paymentController = PaymentControllers::getInstance();

    cabeceraFacturas.clear();
    paymentController.getAllPaymentInvoices(&con, cabeceraFacturas);

    ui->tblWidPaymentInvoice->clearContents();
    ui->tblWidPaymentInvoice->setRowCount( cabeceraFacturas.size() );

    for(size_t i =0; i < cabeceraFacturas.size(); i++){
        ui->tblWidPaymentInvoice->setItem(
            i,0, new QTableWidgetItem( QString::number( cabeceraFacturas[i].getIdCabFactura() ) )
        );

        ui->tblWidPaymentInvoice->setItem(
            i,1, new QTableWidgetItem( QString::fromStdString( cabeceraFacturas[i].getFechaCabFactura() ) )
        );

        ui->tblWidPaymentInvoice->setItem(
            i,2, new QTableWidgetItem( QString::fromStdString( cabeceraFacturas[i].getCodPersona() ) )
        );

        ui->tblWidPaymentInvoice->setItem(
            i,3, new QTableWidgetItem(
                QString::fromStdString( cabeceraFacturas[i].cliente.getNombre() + " " + cabeceraFacturas[i].cliente.getApellido()  )
            )
        );

        ui->tblWidPaymentInvoice->setItem(
            i,4, new QTableWidgetItem( QString::number( cabeceraFacturas[i].getTotalCabFactura() ) )
        );

        ui->tblWidPaymentInvoice->setItem(
            i,5, new QTableWidgetItem( QString::number( 000.11 ) )
        );
    }
}


void GymOperations::on_btnPaymentAllInvoices_clicked()
{
    getAllPaymentInvoicesFromDB();
}


void GymOperations::getInvoiceLinesByInvoiceId(const int currentHeaderId){
    //todo also call this function after the user selecs 1 invoice from the
    //top table
    SqlConnection con;
    PaymentControllers paymentController = PaymentControllers::getInstance();

    detallesFactura.clear();
    paymentController.getAllInvoiceLines(&con, currentHeaderId,
    detallesFactura);

    ui->tblWidPaymentLine->clearContents();
    ui->tblWidPaymentLine->setRowCount( detallesFactura.size() );

    const int ERROR_FLAG = -1;

    for(size_t i = 0; i < detallesFactura.size(); i++){
        qDebug() << detallesFactura[i].getIdDetalleFact() << " *** "
            << currentHeaderId << " *** "
            << detallesFactura[i].getTotalDetalleFact() << "\n";

        ui->tblWidPaymentLine->setItem(
            i, 0, new QTableWidgetItem( detallesFactura[i].getIdDetalleFact() <= 0
            ? QString::number(ERROR_FLAG) : QString::number(detallesFactura[i].getIdDetalleFact() ))
        );

        ui->tblWidPaymentLine->setItem(
            i, 1, new QTableWidgetItem( QString::fromStdString(
            detallesFactura[i].plan.getDescripcionCmpleta() == "" ? "---" : detallesFactura[i].plan.getDescripcionCmpleta() )  )
        );

        ui->tblWidPaymentLine->setItem(
            i, 2, new QTableWidgetItem( detallesFactura[i].plan.getCantidadPaquete() < 0
            ? QString::number(ERROR_FLAG) : QString::number( detallesFactura[i].plan.getCantidadPaquete() ))
        );

        ui->tblWidPaymentLine->setItem(
            i, 3, new QTableWidgetItem( detallesFactura[i].getTotalDetalleFact() < 0.0
            ? QString::number(ERROR_FLAG) : QString::number(detallesFactura[i].getTotalDetalleFact() ))
        );

        ui->tblWidPaymentLine->setItem(
            i, 4, new QTableWidgetItem( QString::fromStdString(
            detallesFactura[i].plan.getFechaPago() == "" ? "0000-00-00" : detallesFactura[i].plan.getFechaPago()  )  )
        );

        ui->tblWidPaymentLine->setItem(
            i, 5, new QTableWidgetItem( QString::fromStdString(
            detallesFactura[i].plan.getFechaFin() == "" ? "0000-00-00" : detallesFactura[i].plan.getFechaFin()  )  )
        );

    }
}


///↓ is not used because I've fixed the query in the PaymentControllers::getAllInvoiceLines function
void GymOperations::getEmptyLinesByInvoiceId(const int currentHeaderId){
    SqlConnection con;
    PaymentControllers paymentController = PaymentControllers::getInstance();

    detallesFactura.clear();
    paymentController.getEmptyInvoiceLines(&con, currentHeaderId, detallesFactura);

    ui->tblWidPaymentLine->clearContents();
    ui->tblWidPaymentLine->setRowCount( detallesFactura.size() );

    for(size_t i = 0; i < detallesFactura.size(); i++){

        ui->tblWidPaymentLine->setItem(
            i, 0, new QTableWidgetItem( QString::number(detallesFactura[i].getIdDetalleFact()) )
        );

        ui->tblWidPaymentLine->setItem(
            i, 1, new QTableWidgetItem( QString::fromStdString(detallesFactura[i].plan.getDescripcionCmpleta()) )
        );

        ui->tblWidPaymentLine->setItem(
            i, 2, new QTableWidgetItem( QString::number(detallesFactura[i].plan.getCantidadPaquete()) )
        );

        ui->tblWidPaymentLine->setItem(
            i, 3, new QTableWidgetItem( QString::number(detallesFactura[i].getTotalDetalleFact()) )
        );

        ui->tblWidPaymentLine->setItem(
            i, 4, new QTableWidgetItem( QString::fromStdString(detallesFactura[i].plan.getFechaPago()) )
        );

        ui->tblWidPaymentLine->setItem(
            i, 5, new QTableWidgetItem( QString::fromStdString(detallesFactura[i].plan.getFechaFin()) )
        );

    }

}


void GymOperations::on_tblWidPaymentInvoice_cellActivated(int row, int column)
{
    QString currentCabeceraTxt = ui->tblWidPaymentInvoice->item(row,0)->text();
    QString userCodeTxt = ui->tblWidPaymentInvoice->item(row,2)->text();
    QString paymentTotalTxt = ui->tblWidPaymentInvoice->item(row,4)->text();
    QString partialPaymentTxt = ui->tblWidPaymentInvoice->item(row,5)->text();


    currentCabeceraTxt.isNull() || currentCabeceraTxt.isEmpty() ?
        ui->invoiceNumber->setText("---") : ui->invoiceNumber->setText(currentCabeceraTxt);

    userCodeTxt.isNull() || userCodeTxt.isEmpty() ?
        ui->txtPaymentUserCode->setText("---") : ui->txtPaymentUserCode->setText(userCodeTxt);

    paymentTotalTxt.isNull() || paymentTotalTxt.isEmpty() ?
        ui->txtPaymentAmount->setText("00.0") : ui->txtPaymentAmount->setText(paymentTotalTxt);

    partialPaymentTxt.isNull() || partialPaymentTxt.isEmpty() ?
        ui->txtPaymentPartialPay->setText("00.0") : ui->txtPaymentPartialPay->setText(partialPaymentTxt);

    getInvoiceLinesByInvoiceId( ui->invoiceNumber->text().toInt() );
    if(detallesFactura.size() <= 0 ){
        getEmptyLinesByInvoiceId( ui->invoiceNumber->text().toInt() );
    }

}


void GymOperations::on_tblWidPaymentLine_cellActivated(int row, int column)
{

    QString invoiceLineId = ui->tblWidPaymentLine->item(row, 0)->text();
    QString paqDescription = ui->tblWidPaymentLine->item(row, 1)->text();
    QString paqQuantity = ui->tblWidPaymentLine->item(row, 2)->text();
    QString lineTotal = ui->tblWidPaymentLine->item(row, 3)->text();
    QString paymentDoneDate = ui->tblWidPaymentLine->item(row, 4)->text();

    invoiceLineId.isNull() || invoiceLineId.isEmpty() ?
        ui->invoiceInfoLineNumber->setText("---") : ui->invoiceInfoLineNumber->setText(invoiceLineId);

    paqQuantity.isNull() || paqQuantity.isEmpty() ?
        ui->sbPaymentQuantity->setValue(0) : ui->sbPaymentQuantity->setValue( paqQuantity.toInt() );

    lineTotal.isNull() || lineTotal.isEmpty() ?
        ui->txtPaymentAmount->setText("00.0") : ui->txtPaymentAmount->setText( lineTotal );

    paymentDoneDate.isNull() || paymentDoneDate.isEmpty() || paymentDoneDate.contains("---") ?
        ui->paymentDatePay->setDate( QDate::fromString("2001/01/01", "yyyy-MM-dd") )
        :  ui->paymentDatePay->setDate( QDate::fromString(paymentDoneDate, "yyyy-MM-dd") );
}


void GymOperations::getAllGymServices(){
    SqlConnection con;
    AppointmentController appointmentController = AppointmentController::getInstance();

    appointmentController.getGymServices(&con, servicios);
    //QList<QString> servicesList;
    if( !servicios.empty() ){
        for( int i = 0; i < servicios.size(); i++ ){
            servicesList.append(
                QString::fromStdString( servicios[i].getTituloServicio() ) +
                ", USD" + QString::number( servicios[i].getPrecioServicio() )
                + " $."
            );
        }
    }

    if( !servicesList.empty() ){
        this->ui->combxAppointService->addItems(servicesList);
    }
}

//APPOINTMENTS TAB


void GymOperations::on_btnAppointNewInvoice_clicked()
{
    QMessageBox msg = QMessageBox();
    SqlConnection con;
    Factura nuevaFactura;

    QDateTime appoDate = this->ui->appointDate->dateTime();
    QString dateString = appoDate.toString("yyyy-MM-dd  HH:mm:ss");
    dateString = dateString.sliced(0, dateString.indexOf(" ") );

                        //2024-09-22
    qDebug() << "Appointment String Date: " << dateString <<
    "\nAppointment Date: " << this->ui->appointDate->dateTime().toString(); //Sun Sep 22 19:46:00 2024


    AppointmentController appointmentController = AppointmentController::getInstance();
    nuevaFactura.setFechaCabFactura( dateString.toStdString() );
    nuevaFactura.setTotalFactura(0.0);
    nuevaFactura.setCodPersona( this->ui->txtAppointUserCode->text().toStdString() );


    bool executionResult = appointmentController.createEmptyPaymentInvoiceAP(&con, nuevaFactura);
    if(executionResult){
        msg.setWindowTitle("Saved"); msg.setText("Empty invoice created succesfully");
        msg.setIcon( QMessageBox::Information );
        msg.setStyleSheet("color:white; background:black");
        msg.exec();

    }else{
        msg.setWindowTitle("Error"); msg.setText("Couldn't create empty invoice");
        msg.setIcon( QMessageBox::Warning );
        msg.setStyleSheet("color:white; background:black");
        msg.exec();
    }
}


void GymOperations::getAllAppointmentInvoicesFromDB(){
    SqlConnection con;
    AppointmentController appointmentController = AppointmentController::getInstance();

    citasFacturas.clear();
    appointmentController.getAllPaymentInvoicesAP(&con, citasFacturas);

    ui->tblWidAppointInvoice->clearContents();
    ui->tblWidAppointInvoice->setRowCount( citasFacturas.size() );

    for(size_t i = 0; i < citasFacturas.size(); i++){
        ui->tblWidAppointInvoice->setItem(
            i,0, new QTableWidgetItem( QString::number( citasFacturas[i].getIdCabFactura() ) )
        );

        ui->tblWidAppointInvoice->setItem(
            i,1, new QTableWidgetItem( QString::fromStdString( citasFacturas[i].getFechaCabFactura() ) )
        );

        ui->tblWidAppointInvoice->setItem(
            i,2, new QTableWidgetItem( QString::fromStdString( citasFacturas[i].getCodPersona() ) )
        );

        ui->tblWidAppointInvoice->setItem(
            i, 3, new QTableWidgetItem(
                QString::fromStdString( citasFacturas[i].cliente.getNombre() + " " + citasFacturas[i].cliente.getApellido() )
            )
        );

        ui->tblWidAppointInvoice->setItem(
            i,4, new QTableWidgetItem( QString::number( citasFacturas[i].getTotalCabFactura() ) )
        );

        ui->tblWidAppointInvoice->setItem(
            i, 5, new QTableWidgetItem( QString::number(0.00) )
        );
    }
}


void GymOperations::getAppointLinesByInvoiceId(const int currentHeaderId){
    SqlConnection con;
    AppointmentController appointmentController = AppointmentController::getInstance();

    citasDetalles.clear();
    appointmentController.getAllInvoiceLines(&con, currentHeaderId,
    citasDetalles);

    ui->tblWidAppointLine->clearContents();
    ui->tblWidAppointLine->setRowCount( citasDetalles.size() );

    const int ERROR_FLAG = -1;

    for( size_t i = 0; i < citasDetalles.size(); i++){
        ui->tblWidAppointLine->setItem(
            i,0, new QTableWidgetItem( citasDetalles[i].getIdDetalleFact() <= 0
            ? QString::number(ERROR_FLAG) : QString::number(citasDetalles[i].getIdDetalleFact()) )
        );

        ui->tblWidAppointLine->setItem(
            i, 1, new QTableWidgetItem(
                QString::fromStdString(
                citasDetalles[i].servicio.getTituloServ() == "" ? "---" : citasDetalles[i].servicio.getTituloServ()) )
        );

        ui->tblWidAppointLine->setItem(
            i, 2, new QTableWidgetItem( citasDetalles[i].servicio.getNumSesiones() < 0
            ? QString::number(ERROR_FLAG) : QString::number( citasDetalles[i].servicio.getNumSesiones() ))
        );

        ui->tblWidAppointLine->setItem(
            i,3, new QTableWidgetItem ( citasDetalles[i].getTotalDetalleFact() < 0.0
            ? QString::number(ERROR_FLAG) : QString::number(citasDetalles[i].getTotalDetalleFact()) )
        );

        ui->tblWidAppointLine->setItem(
            i,4, new QTableWidgetItem (
            QString::fromStdString( citasDetalles[i].getNombrePaciente() )
            )
        );

        ui->tblWidAppointLine->setItem(
            i,5, new QTableWidgetItem (
            QString::fromStdString( citasDetalles[i].servicio.getFechaServ() )
            )
        );

    }
}


void GymOperations::on_btnAppointAllInvoices_clicked()
{
    getAllAppointmentInvoicesFromDB();
}


void GymOperations::on_btnAppointAdd_clicked()
{
    QMessageBox msg = QMessageBox();
    SqlConnection con;
    int currentInvoice = 0;
    currentInvoice = ui->appointInvoiceNumber->text().toInt();
    DetalleFactura nuevoDetalle(0, 0.0, currentInvoice);

    AppointmentController appointmentController = AppointmentController::getInstance();

    bool executionResult = appointmentController.createEmptyInvoiceLineAP(&con, nuevoDetalle);

    if(executionResult){
        msg.setWindowTitle("Saved");
        msg.setText("Empty appointment created succesfully");
        msg.setIcon(QMessageBox::Information);
        msg.setStyleSheet("color:white; background:black");
        msg.exec();

        getAppointLinesByInvoiceId(currentInvoice);

    }else{
        msg.setWindowTitle("Error");
        msg.setText("Couldn't create an empty appointment");
        msg.setIcon(QMessageBox::Warning);
        msg.setStyleSheet("color:white; background:black");
        msg.exec();
    }
}


void GymOperations::on_btnSaveAppoint_clicked()
{
    QMessageBox msg = QMessageBox();
    SqlConnection con;
    int currentInvoiceLineId = 0;
    int numSesiones = 0;
    int currentInvoice = 0;
    AppointmentController appointmentController = AppointmentController::getInstance();

    QString selectedService = this->ui->combxAppointService->currentText();
    QString packageTitle = selectedService.split(", ")[0];
    currentInvoiceLineId = this->ui->appointNumber->text().toInt();

    QDateTime appointDate = this->ui->appointDate->dateTime();
    QString dateAppointment = appointDate.toString("yyyy-MM-dd HH:mm:ss");

    currentInvoice = this->ui->appointInvoiceNumber->text().toInt();

    numSesiones = this->ui->sbAppointQuantity->text().toInt();
    int serviceId = getCurrentSelectedGymServiceId(packageTitle.toStdString()) ;
    /*qDebug() << "\n\t--------------------------\n"
     * << currentInvoiceLineId << " ---- " << serviceId << "\n" << packageTitle << " ---- " << appointDate.toString("yyyy-MM-dd HH:mm:ss"); */

    bool executionResult = appointmentController
    .createInvoiceLineInfoAP(&con,currentInvoiceLineId,
    serviceId, numSesiones, dateAppointment);

    if(executionResult){
        msg.setWindowTitle("Saved");
        msg.setText("Appoint created succesfully");
        msg.setIcon(QMessageBox::Information);
        msg.setStyleSheet("color:white; background:black");
        msg.exec();

        //añadir la función para actualizar el detalle (cita)
        bool updateAppointResult = appointmentController
        .updateInvoiceLineInfoAP(&con, currentInvoiceLineId);
        if( updateAppointResult ){
            msg.setWindowTitle("Saved");
            msg.setText("Appoint total updated succesfully");
            msg.setIcon(QMessageBox::Information);
            msg.setStyleSheet("color:white; background:black");
            msg.exec();
        }else{
            msg.setWindowTitle("Error");
            msg.setText("Couldn't update the total of this appointment");
            msg.setIcon(QMessageBox::Information);
            msg.setStyleSheet("color:white; background:black");
            msg.exec();
        }
        //añadir la función para traer todas las citas (lineas - detalles) para esta factura
        getAppointLinesByInvoiceId(currentInvoice);
    }else{
        msg.setWindowTitle("Error");
        msg.setText("Couldn't create an appoint");
        msg.setIcon(QMessageBox::Critical);
        msg.setStyleSheet("color:white; background:black");
        msg.exec();
    }
}


void GymOperations::on_tblWidAppointInvoice_cellActivated(int row, int column)
{
    QString currentCabeceraTxt = ui->tblWidAppointInvoice->item(row,0)->text();
    QString userCodeTxt = ui->tblWidAppointInvoice->item(row,2)->text();
    QString paymentTotal = ui->tblWidAppointInvoice->item(row,4)->text();

    currentCabeceraTxt.isNull() || currentCabeceraTxt.isEmpty() ?
    ui->appointInvoiceNumber->setText("---") : ui->appointInvoiceNumber->setText( currentCabeceraTxt );

    userCodeTxt.isNull() || userCodeTxt.isEmpty() ?
    ui->txtAppointUserCode->setText("---") : ui->txtAppointUserCode->setText(userCodeTxt);

    paymentTotal.isNull() || paymentTotal.isEmpty() ?
    ui->appointPayAmmount->setText("0.00") : ui->appointPayAmmount->setText(paymentTotal) ;

    getAppointLinesByInvoiceId(currentCabeceraTxt.toInt());
}


void GymOperations::on_tblWidAppointLine_cellActivated(int row, int column)
{
    QString invoiceLineId = ui->tblWidAppointLine->item(row,0)->text();
    QString servDescription = ui->tblWidAppointLine->item(row,1)->text();
    QString numSessions = ui->tblWidAppointLine->item(row,2)->text();
    QString lineTotal = ui->tblWidAppointLine->item(row,3)->text();
    QDateTime sessionDate = QDateTime::fromString(
        ui->tblWidAppointLine->item(row,5)->text(),
        "yyyy-MM-dd HH:mm:ss");


    invoiceLineId.isNull() || invoiceLineId.isEmpty() ?  ui->appointNumber->setText("---") : ui->appointNumber->setText(invoiceLineId);

    numSessions.isNull() || numSessions.isEmpty() || (numSessions.toInt() == -1) ?
        ui->sbAppointQuantity->setValue(0) : ui->sbAppointQuantity->setValue(numSessions.toInt());

    lineTotal.isNull() || lineTotal.isEmpty() || (lineTotal.toInt() == -1) ?
        ui->appointPayAmmount->setText( "$ 0.00" ) : ui->appointPayAmmount->setText( lineTotal );

    //sessionDate.replace("-","/")        ;
    //sessionDate.isNull() || sessionDate.isEmpty() ? ui->appointDate->setDateTime(QDateTime::currentDateTime()) : ui->appointDate->setDateTime( QDateTime::fromString(sessionDate) );

    int serviceIndex = 0;


    QStringList serviceTitle = servDescription.split(' ');

    try {
        for(int i = 0; i < servicesList.size();i++){

            if( serviceTitle.size() >= 2 && servicesList[i].contains(serviceTitle[2]) ){

                serviceIndex = i;
                break;
            }else{
                serviceIndex = 0;
            }
        }
    } catch ( std::out_of_range ex) {
        qDebug() << "Error showing empty appoint line " <<   ex.what() << "\n";
    }


    ui->combxAppointService->setCurrentIndex(serviceIndex);



    ui->appointDate->setDateTime(sessionDate);  //ui->appointDate->setDateTime( QDateTime::fromString(sessionDate) );

    //qDebug() << serviceIndex << "\t" << serviceTitle[2];
        //descfription in combobox is shown as: Sesión de Fisioterapia, USD25 $.
    //qDebug() << "Description: " << servDescription << "\n"//Sesión de Nutricionismo 25.00 << "Session Date: " << sessionDate << "\n\n";//2024/09/23 11:30:45


}


void GymOperations::on_btnAppointSaveAll_clicked()
{
    SqlConnection con;
    int currentHeader = 0;
    AppointmentController appointmentController = AppointmentController::getInstance();
    currentHeader = ui->appointInvoiceNumber->text().toInt();

    bool executionResult = appointmentController.updatePaymentInvoiceAP(&con, currentHeader);

    if(executionResult){
        QMessageBox::information(this,"Saved","Invoice Header updated succesfully");
        getAllAppointmentInvoicesFromDB();
    }else{
        QMessageBox::information(this,"Error","Couldn't update header with its lines");
    }
}

//reportery
void GymOperations::createPDf(const std::vector<DetalleReporte>& lineas)
{
    QString nombre = QString::fromStdString( lineas[0].getNombreCliente() );


    // Ruta donde se guardará el PDF
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Guardar PDF", "", "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    // Crear el escritor PDF
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(96);  // DPI del PDF
    pdfWriter.setPageMargins(QMargins(0,0,0,0), QPageLayout::Millimeter);

    // Crear un pintor para dibujar en el PDF
    QPainter painter(&pdfWriter);
    QPixmap gymLogo(":images/Images/GoldsGym1.png");

    QPageSize pageSize = QPageSize(QPageSize::A4);
    QRect pageRect = pageSize.rectPixels(pdfWriter.resolution());

    int headerHeight = 200;
    double totalPrice = 0.0;
    QString totalPriceStr;

    painter.fillRect(0,0, pageRect.width()+1, headerHeight,  QColor("black"));

    painter.drawPixmap(2, 2,220,190, gymLogo);


    int startY = headerHeight+50; //posicion inicial para los detalles
    int lineHeight = 20; //ancho de cada linea de detalle

    int columnaId = 38;
    int columnaDetalle = 250;
    int columnaTotal = 70;
    int columnaFecha= 120;

    painter.setFont( QFont("Arial",14, QFont::Bold) );

    QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");
    QString message = "Fecha: " + currentDate;
    painter.drawText(20, startY, message);

    startY += 20;
    QString nombreCliente = "Cliente: " + QString::fromStdString( lineas[0].getNombreCliente() );
    painter.drawText(20, startY, nombreCliente);

    startY += 30;

    painter.setFont( QFont("Arial",11, QFont::Normal) );
    //cabecera de la tabla
    painter.drawText(20, startY, columnaId, lineHeight, Qt::AlignLeft, "ID");
    painter.drawText(20+columnaId, startY, columnaDetalle, lineHeight, Qt::AlignLeft, "Producto");
    painter.drawText(20+columnaId+columnaDetalle, startY,columnaFecha,
        lineHeight, Qt::AlignLeft, "Fecha");
    painter.drawText(20+columnaId+columnaDetalle+columnaFecha, startY, columnaTotal,
        lineHeight, Qt::AlignLeft, "Sub Total");

    //mover startY para mostrar los detalles
    startY += lineHeight +10;

    for(const auto& detalle : lineas){
        QString id= QString::number( detalle.getIdDetalleReporte() );
        QString detalleReporte = QString::fromStdString( detalle.getDetalleReporte() );
        QString subTotal = QString::number( detalle.getTotalDetalleReporte() );
        QString fecha = QString::fromStdString( detalle.getFecha() );
        fecha = fecha.mid(0,10);
        subTotal+=".00";
        totalPrice += detalle.getTotalDetalleReporte() ;

        painter.drawText(20, startY, columnaId, lineHeight, Qt::AlignCenter, id);
        painter.drawText(20+columnaId, startY, columnaDetalle,
            lineHeight, Qt::AlignLeft, detalleReporte);
        painter.drawText(20+columnaId+columnaDetalle, startY,
            columnaFecha, lineHeight, Qt::AlignLeft, fecha);
        painter.drawText(20+columnaId+columnaDetalle+columnaFecha, startY, columnaTotal,
            lineHeight, Qt::AlignLeft, subTotal);

        startY += lineHeight;
    }

    startY += 10;
    totalPriceStr = QString::number(totalPrice) + ".00";
    painter.drawText(20+columnaId+columnaDetalle+columnaFecha, startY,
    columnaTotal, lineHeight, Qt::AlignLeft, totalPriceStr);
    painter.end();




    /*
    const QString fileName("C:/Users/Usuario/Downloads/mydoc.pdf");
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&pdfWriter);
    */

}

void GymOperations::on_btnGenerateReport_clicked()
{
    if( !detallesReporte.empty() ){
        createPDf(detallesReporte);
    }

}



void GymOperations::on_btnAllInvoicesReport_clicked()
{
    SqlConnection con;
    ReportController reportController = ReportController::getInstance();

    facturasReporte.clear();
    reportController.getAllInvoices(&con, facturasReporte);

    ui->tblAllInvoices->clearContents();
    ui->tblAllInvoices->setRowCount( facturasReporte.size() );

    for(size_t i = 0; i < facturasReporte.size(); i++){
        ui->tblAllInvoices->setItem(
            i, 0, new QTableWidgetItem( QString::number(facturasReporte[i].getIdCabFactura()) )
        );

        ui->tblAllInvoices->setItem(
            i, 1, new QTableWidgetItem( QString::fromStdString(facturasReporte[i].getFechaCabFactura()) )
        );

        ui->tblAllInvoices->setItem(
            i, 2, new QTableWidgetItem( QString::fromStdString(facturasReporte[i].getCodPersona()) )
        );

        ui->tblAllInvoices->setItem(
            i, 3, new QTableWidgetItem(
                QString::fromStdString( facturasReporte[i].cliente.getNombre() + " " + facturasReporte[i].cliente.getApellido() )
            )
        );

        ui->tblAllInvoices->setItem(
            i, 4, new QTableWidgetItem( QString::number( facturasReporte[i].getTotalCabFactura() ) )
        );
    }

    adjustReportInvoiceTable( ui->tblAllInvoices );
}


void GymOperations::adjustReportInvoiceTable(QTableWidget *tableWidget){
    int filas = tableWidget->rowCount();
    for(int fila = 0; fila < filas; fila++){
        QTableWidgetItem* col0 = tableWidget->item(fila, 0);
        if( col0 ){
            col0->setTextAlignment(Qt::AlignCenter);
        }

        QTableWidgetItem* col4 = tableWidget->item(fila, 4);
        if( col4 ){
            col4->setTextAlignment(Qt::AlignCenter);
        }
    }

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void GymOperations::on_tblAllInvoices_cellActivated(int row, int column)
{
    int currentCabeceraID = ui->tblAllInvoices->item(row,0)->text().toInt();
    qDebug()<< "Id chosen for report: " << currentCabeceraID << "\n";

    SqlConnection con;
    ReportController reportController = ReportController::getInstance();

    detallesReporte.clear();
    reportController.getInvoiceLinesById(&con, currentCabeceraID, detallesReporte);

    ui->tblInvoiceLines->clearContents();
    ui->tblInvoiceLines->setRowCount( detallesReporte.size() );

    const int ERROR_FLAG = -1;

    for(size_t i = 0; i < detallesReporte.size(); i++){
        ui->tblInvoiceLines->setItem(
            i, 0, new QTableWidgetItem( detallesReporte[i].getIdDetalleReporte() < 0
            ? QString::number(ERROR_FLAG) : QString::number(detallesReporte[i].getIdDetalleReporte()) )
        );

        ui->tblInvoiceLines->setItem(
            i, 1, new QTableWidgetItem( detallesReporte[i].getTotalDetalleReporte() < 0.0
            ? QString::number(ERROR_FLAG) : QString::number( detallesReporte[i].getTotalDetalleReporte() ) )
        );

        ui->tblInvoiceLines->setItem(
            i, 2, new QTableWidgetItem(
                QString::fromStdString(
                    detallesReporte[i].getDetalleReporte() == "" ? "---"
                    : detallesReporte[i].getDetalleReporte()) )
        );

        QString fecha = QString::fromStdString(
                detallesReporte[i].getFecha() );
        fecha = fecha.mid(0,10);

        ui->tblInvoiceLines->setItem(
            i, 3, new QTableWidgetItem(
            fecha == "" ? "---" : fecha
                /* QString::fromStdString( detallesReporte[i].getFecha()
                 == "" ? "---": detallesReporte[i].getFecha()) */
            )
        );

        ui->tblInvoiceLines->setItem(
            i, 4, new QTableWidgetItem(
                QString::fromStdString(
                    detallesReporte[i].getNombreCliente() == "" ? "---"
                    : detallesReporte[i].getNombreCliente()) )
        );
    }

}


//EMAIL TABS
void GymOperations::on_btnSendEmail_clicked()
{
    //https://www.youtube.com/watch?v=62Mzbt8QqLE
    QSettings settings("../GymFitness/config.ini", QSettings::Format::IniFormat);
    //settings.setValue("Group1/mail","jfkik@gmail.com");
    //settings.setValue("Group1/password","vsd");


    QString correo = settings.value("Group1/mail").toString();
    QString password = settings.value("Group1/password").toString();

    if( correo.isEmpty() || password.isEmpty() ){
        qDebug() << "Couldn't find credentials for gmail";
    }
    qDebug() << "Correo: " << correo << "Password: " << password<< "\n";


    MimeMessage message;

    EmailAddress sender(correo, "Jose Pinos");
    message.setSender(sender);

    EmailAddress to("Reverb1@outlook.es", "Pepito Alejandro");
    message.addRecipient(to);

    message.setSubject("Hola Mundo");

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText("Hi,\nThis is a simple email message.\n");

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";

    }

    smtp.login(correo, password);
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "Failed to login!";

    }

    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "Failed to send mail!";

    }

    smtp.quit();


}







