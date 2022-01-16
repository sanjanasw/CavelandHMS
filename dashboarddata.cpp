#include "dashboarddata.h"

QString* RoomData = new QString[6];
QPieSeries* series = new QPieSeries();


dashboarddata::dashboarddata()
{

}

void dashboarddata::getDashboardData(){
    //database connection
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery chartQuery;
            chartQuery.exec("SELECT COUNT(Id) AS Student_Count, Gender  FROM Students GROUP BY Gender");
            QSqlQuery roomCountQuery;
            roomCountQuery.exec("SELECT COUNT(DISTINCT Id) AS Room_Count FROM Rooms");
            QSqlQuery reservedRoomCountQuery;
            reservedRoomCountQuery.exec("SELECT COUNT(DISTINCT Room_Id) AS Reserved_Room_Count FROM Students");
            QSqlQuery staffCountQuery;
            staffCountQuery.exec("SELECT COUNT(Id) AS Staff_Count FROM Users WHERE User_Role = 0");

            if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                while (chartQuery.next()) {
                    int count = chartQuery.value(0).toInt();
                    QString gCount = chartQuery.value(0).toString();
                    QString gender = chartQuery.value(1).toString();
                    series->append(gender,count);
                    if(gender == "M"){
                        RoomData[3] = gCount;
                    }else{
                        RoomData[4] = gCount;
                    }
                }
                roomCountQuery.next();
                RoomData[0] = roomCountQuery.value(0).toString();
                reservedRoomCountQuery.next();
                RoomData[1] = reservedRoomCountQuery.value(0).toString();
                staffCountQuery.next();
                RoomData[5] = staffCountQuery.value(0).toString();

             }

             db.close();
        }
    }  catch (...) {

    }

}

QPieSeries* dashboarddata::getGenderChart(){
    return series;
}

QString* dashboarddata::getRoomData(){
    RoomData[2] = QString::number((RoomData[0].toInt()) - (RoomData[1].toInt()));
    return RoomData;
}

