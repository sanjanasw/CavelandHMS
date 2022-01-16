#include "login.h"

Login::Login()
{

}

//login to the system returns user data as a QString array
QString* Login::UserLogin(QString UserName, QString Password){
    QString* UserData = new QString[4];
    UserData[0] = "0";
    //database connection
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
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
        UserData[0] = "2";
    }  catch (...) {

    }
    return UserData;
}
