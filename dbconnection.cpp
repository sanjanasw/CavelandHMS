#include "dbconnection.h"

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

DBConnection::DBConnection()
{

}

//connect to the database
QSqlDatabase DBConnection::ConnectDb()
{
        if(db.databaseName() == ""){
            db.setDatabaseName("Driver={ODBC Driver 17 for SQL Server};Server={{Your Server}};Database=chms_db;Uid={{Your UserID}};Pwd={{Your Password}};Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");
        }
        return db;
}

