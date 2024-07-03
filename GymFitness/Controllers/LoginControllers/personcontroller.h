#ifndef PERSONCONTROLLER_H
#define PERSONCONTROLLER_H

#include <QString>
#include <vector>
#include <string>
#include <iomanip>
#include "sqlconnection.h"

class PersonController
{

public:
    static PersonController& getInstance(){
        static PersonController instance;
        return instance;
    }

private:
    PersonController(){};
};

#endif // PERSONCONTROLLER_H
