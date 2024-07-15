#ifndef APPOINTMENTCONTROLLER_H
#define APPOINTMENTCONTROLLER_H

#include <QTableWidget>

#include <QString>
#include <vector>
#include <string>
#include <iomanip>

#include <Models/persona.h>
#include <Models/rol.h>
#include <Models/paqueteentreno.h>
#include "sqlconnection.h"

class AppointmentController
{

public:
    static AppointmentController& getInstance(){
        static AppointmentController instance;
        return instance;
    }

private:
    AppointmentController(){};
};

#endif // APPOINTMENTCONTROLLER_H
