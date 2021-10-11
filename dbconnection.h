#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include <QtSql>


class DBConnection
{
public:
    DBConnection();
public:
    static QSqlDatabase ConnectDb();
};

#endif // DBCONNECTION_H
