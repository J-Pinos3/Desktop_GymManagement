#ifndef GYMOPERATIONS_H
#define GYMOPERATIONS_H

#include <QWidget>
#include <QMessageBox>

#include <vector>
#include <string>

#include <QFile>
#include <QTextStream>

#include "Controllers/PersonControllers/personcontroller.h"
#include "Controllers/PaymentControllers/paymentcontrollers.h"
#include "Controllers/AppointmentControllers/appointmentcontroller.h"
#include "Controllers/ReportsControllers/reportcontroller.h"
#include "Models/persona.h"
#include "Models/rol.h"
#include "Models/paqueteentreno.h"
#include "Models/factura.h"
#include "Models/detallefactura.h"
#include "Models/servicio.h"
#include "View/dialogcalendar.h"

#include "sqlconnection.h"


namespace Ui {
class GymOperations;
}

class GymOperations : public QWidget
{
    Q_OBJECT

public:
    explicit GymOperations(QWidget *parent = nullptr);
    ~GymOperations();

    void setCustomersRoleDescription();
    void listAllCustomers();

    void listNewCustomer(QString name);

    void getTrainingPackages();

    int getCurrentSelectedPackageId(const std::string &descriptionPackage);

    void getAllGymServices();

    int getCurrentSelectedGymServiceId(const std::string &tituloServicio);

    void getValuesfromManageFields(QString& nombre, QString& apellido,
        QString& fechaRegistro, double& peso, int& rolId);

    void getAllPaymentInvoicesFromDB();

    void getInvoiceLinesByInvoiceId(const int currentHeaderId);

    void getEmptyLinesByInvoiceId(const int currentHeaderId);


    //invoices in appointment tab
    void getAllAppointmentInvoicesFromDB();

    void getAppointLinesByInvoiceId(const int currentHeaderId);


    //create pdf report
    void createPDf(const std::vector<DetalleReporte>& lineas);


    //adjust the sice of the table of invoices for report
    void adjustReportInvoiceTable(QTableWidget *tableWidget);

    //list pdf files to send via email
    void getInvoiceFiles();



    //save configurations  file
    void createAssistanceFile(QLabel* label);

    //save ASSISTANCE to assistance file
    void writeAssistanceFile(const QString& route, const QString name, const QString date );


public slots:
    //set appoint date
    void setChoosenDate(const QDate& date);

private slots:

    void on_btnCustomerSearchIntro_clicked();

    void on_btnAllCustomers_clicked();



    void on_btnManageSave_clicked();

    void on_cbxManageNew_stateChanged(int arg1);

    void on_btnManageCancel_clicked();

    void on_btnManageSearch_clicked();








    void on_btnPaymentNewInvoice_clicked();

    void on_btnPaymentAddLine_clicked();

    void on_btnSaveLine_clicked();

    void on_btnPaymentSaveAll_clicked();

    void on_btnPaymentAllInvoices_clicked();

    void on_tblWidPaymentInvoice_cellActivated(int row, int column);

    void on_tblWidPaymentLine_cellActivated(int row, int column);



    void on_btnAppointNewInvoice_clicked();

    void on_btnAppointAllInvoices_clicked();

    void on_btnAppointAdd_clicked();

    void on_btnSaveAppoint_clicked();

    void on_tblWidAppointInvoice_cellActivated(int row, int column);

    void on_tblWidAppointLine_cellActivated(int row, int column);

    void on_btnAppointSaveAll_clicked();

    void on_btnGenerateReport_clicked();



    void on_btnAllInvoicesReport_clicked();

    void on_tblAllInvoices_cellActivated(int row, int column);

    void on_btnSendEmail_clicked();

    void on_btnListFiles_clicked();

    void on_txtEmailAddress_textChanged(const QString &arg1);

    void on_btnAvailableDates_clicked();

    void on_btnSelectDirectory_clicked();


private:
    Ui::GymOperations *ui;
    std::vector<Persona> personas;
    std::vector<Rol> roles;
    std::vector<PaqueteEntreno> paquetes;
    std::vector<Factura> cabeceraFacturas;
    std::vector<DetalleFactura> detallesFactura;
    std::vector<Factura> citasFacturas;
    std::vector<DetalleFactura> citasDetalles;
    std::vector<Servicio> servicios;
    QList<QString> servicesList;
    std::vector<Factura> facturasReporte;
    std::vector<DetalleReporte> detallesReporte;
    QStringList facturasCorreo;
    QString emailAddressTo;
    DialogCalendar dialogCalendar;
    QString assistFileRoute;
    QString textoBtnMngSave;
};

#endif // GYMOPERATIONS_H
