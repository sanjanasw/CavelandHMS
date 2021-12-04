#include "dbconnection.h"
#include <QtSql>

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

DBConnection::DBConnection()
{

}

QSqlDatabase DBConnection::ConnectDb()
{


        if(db.databaseName() == ""){
            //db.setDatabaseName("DRIVER={sql server};Server=SHATTER;Database=CHMS;Trusted_Connection=yes;");
            db.setDatabaseName("Driver={ODBC Driver 17 for SQL Server};Server=tcp:chms.database.windows.net,1433;Database=chms_db;Uid=sanjana;Pwd=Rajans4ever;Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");
        }
        return db;
}

