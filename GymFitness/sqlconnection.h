#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

class SqlConnection
{
public:
    SqlConnection();

    void conOpen();
    void conClose();

private:
    QSqlDatabase db;

};

#endif // SQLCONNECTION_H
