#ifndef GYMOPERATIONS_H
#define GYMOPERATIONS_H

#include <QWidget>
#include <QMessageBox>

#include <vector>
#include <string>

#include "Controllers/PersonControllers/personcontroller.h"
#include "Models/persona.h"
#include "Models/rol.h"
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

    void getValuesfromManageFields(QString& nombre, QString& apellido,
        QString& fechaRegistro, double& peso, int& rolId);

private slots:

    void on_btnCustomerSearchIntro_clicked();

    void on_btnAllCustomers_clicked();



    void on_btnManageSave_clicked();

    void on_cbxManageNew_stateChanged(int arg1);

    void on_btnManageCancel_clicked();

    void on_btnManageSearch_clicked();

    void on_cbxAppointNew_stateChanged(int arg1);

    void on_btnAppointSave_clicked();

    void on_btnAppointCancel_clicked();

    void on_btnAppointSearch_clicked();

    void on_btnAppointAll_clicked();

private:
    Ui::GymOperations *ui;
    std::vector<Persona> personas;
    std::vector<Rol> roles;
};

#endif // GYMOPERATIONS_H
