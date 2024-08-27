#include "gymoperations.h"
#include "ui_gymoperations.h"

GymOperations::GymOperations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GymOperations)
{

    ui->setupUi(this);

    connect( ui->tblWidPaymentInvoice, SIGNAL(cellClicked(int,int)), this, SLOT(on_tblWidPaymentInvoice_cellActivated(int, int)) );
    connect( ui->tblWidPaymentLine,    SIGNAL(cellClicked(int,int)), this, SLOT(on_tblWidPaymentLine_cellActivated(int, int)) );

    setCustomersRoleDescription();
    listAllCustomers();
    getTrainingPackages();
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


//APPOINTMENTS TAB ALL EMPTY FOR THE MOMENT
void GymOperations::on_btnAppointSave_clicked()
{

}

void GymOperations::on_btnAppointCancel_clicked()
{

}

void GymOperations::on_btnAppointSearch_clicked()
{

}

void GymOperations::on_btnAppointAll_clicked()
{

}

//CHECKBOX APPOINT NEW STATECHANGED
void GymOperations::on_cbxAppointNew_stateChanged(int arg1)
{

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
            i,3, new QTableWidgetItem( "---" )
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


///↓ is not used because I've fixed the query
/// in the PaymentControllers::getAllInvoiceLines function
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

