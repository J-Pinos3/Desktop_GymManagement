#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Models/rol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getCurrentSelectedRolId(const std::string &descriptionRol);

private slots:
    void on_btnLogearse_clicked();

    void on_btnRegistrarse_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Rol> roles;
};
#endif // MAINWINDOW_H
