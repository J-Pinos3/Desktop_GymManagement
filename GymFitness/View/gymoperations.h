#ifndef GYMOPERATIONS_H
#define GYMOPERATIONS_H

#include <QWidget>


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

    void listAllCustomers();

private slots:

    void on_btnCustomerSearchIntro_clicked();

private:
    Ui::GymOperations *ui;
    std::vector<Persona> personas;
};

#endif // GYMOPERATIONS_H
