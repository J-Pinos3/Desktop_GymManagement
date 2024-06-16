#include "gymoperations.h"
#include "ui_gymoperations.h"

GymOperations::GymOperations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GymOperations)
{
    ui->setupUi(this);
}

GymOperations::~GymOperations()
{
    delete ui;
}
