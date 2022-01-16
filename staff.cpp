#include "staff.h"

staff::staff()
{

}

// Add new user to the system
bool staff::AddNewUser(QStringList newData){
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery newUser;
            if(newUser.exec("EXEC newUser @Name = '"+newData[0]+"', @Pass = '"+newData[1]+"', @Nic_No = '"+newData[2]+"', @Address = '"+newData[3]+"', @Tp = '"+newData[4]+"', @Email = '"+newData[5]+"', @Salary = "+newData[6]+";")){
                return true;
            }
            db.close();
        }
    }  catch (...) {

    }
    return false;
}
