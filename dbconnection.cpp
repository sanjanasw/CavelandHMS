#include "dbconnection.h"
#include <QtSql>

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

DBConnection::DBConnection()
{

}

QSqlDatabase DBConnection::ConnectDb()
{

        //db.setDatabaseName("Driver={ODBC Driver 17 for SQL Server};Server=tcp:cakeparadisedbserver.database.windows.net,1433;Database=CakeParadise_db;Uid={uname};Pwd={pass};Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");
        if(db.databaseName() == ""){
            db.setDatabaseName("DRIVER={sql server};Server=SHATTER;Database=CHMS;Trusted_Connection=yes;");
        }
        return db;
}

