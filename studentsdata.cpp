#include "studentsdata.h"

StudentsData::StudentsData()
{

}

QStringList StudentsData::AddNewUser(QStringList newData){
    QStringList newStudentsData;
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery newStudent;
            newStudent.exec("EXEC newAdmission @Name = '"+newData[0]+"', @Nic_No = '"+newData[1]+"', @Address = '"+newData[2]+"', @Tp = '"+newData[3]+"', @Email = '"+newData[4]+"', @University = '"+newData[5]+"', @Room_Id = "+newData[6]+";");
            if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                while (newStudent.next()) {
                    for(int i = 0; i < 7; i++){
                        newStudentsData.append(newStudent.value(i).toString());
                    }
                }
            }
            db.close();
            if(newStudentsData.length() < 3){
                newStudentsData.clear();
                newStudentsData.append("0");
            }
        }
    }  catch (...) {

    }
    return newStudentsData;
}

QStringList StudentsData::FindNewUser(QString Id){
    QStringList StudentsData;
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery newStudent;
            newStudent.exec("EXEC FindStudent @Id = "+Id+";");
            if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                StudentsData.append("4");
                while (newStudent.next()) {
                    for(int i = 0; i < 11; i++){
                        StudentsData.append(newStudent.value(i).toString());
                    }
                }
            }
            db.close();
            if(StudentsData.length() < 3){
                StudentsData.clear();
                StudentsData.append("0");
            }
        }
    }  catch (...) {

    }
    return StudentsData;

}
