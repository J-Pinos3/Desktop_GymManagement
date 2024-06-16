#ifndef GYMOPERATIONS_H
#define GYMOPERATIONS_H

#include <QWidget>

namespace Ui {
class GymOperations;
}

class GymOperations : public QWidget
{
    Q_OBJECT

public:
    explicit GymOperations(QWidget *parent = nullptr);
    ~GymOperations();

private:
    Ui::GymOperations *ui;
};

#endif // GYMOPERATIONS_H
