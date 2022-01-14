#include "login.h"
#include "dbconnection.h"
#include <QtDebug>

Login::Login()
{

}

QString* Login::UserLogin(QString UserName, QString Password){
    QString* UserData = new QString[4];
    UserData[0] = "0";
    //database connection
    QSqlDatabase db = DBConnection::ConnectDb();
    qDebug() << "connecting..";
    try {
        if(db.open()){
            qDebug() << "connected";
            QSqlQuery query;
            QString queryStringP1 = "SELECT Id, UserName, User_Role FROM Users WHERE UserName = '";
            QString queryStringP2 = "' AND Password = '";
            QString queryStringP3 = "'";
            query.exec(queryStringP1+UserName+queryStringP2+Password+queryStringP3);
            if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                query.next();
                int id = query.value(0).toInt();
                QString name = query.value(1).toString();
                QString userType = query.value(2).toString();
                qDebug() << id << name;
                if(id>0){
                    UserData[0] = "1";
                    UserData[1] = id;
                    UserData[2] = name;
                    UserData[3] = userType;
                    return UserData;
                }else{
                    return UserData;
                }
             }
             db.close();
             return UserData;
        }
    }  catch (...) {

    }
    return UserData;
}
