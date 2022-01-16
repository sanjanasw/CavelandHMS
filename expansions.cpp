#include "expansions.h"

expansions::expansions()
{

}

//Return room adding status
bool expansions::addNewRooms(int BuildingId, QString RoomType, QString Rental, QString RoomCount){
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery newUser;
            if(newUser.exec("EXEC addnewrooms @Building_ID = "+QString::number(BuildingId)+", @Room_Type = '"+RoomType+"', @Rental = "+Rental+", @Rooms_Count = "+RoomCount+", @Counter = 1;")){
                return true;
            }
            db.close();
            return false;

        }
    }  catch (...) {
        return false;
    }
    return false;
}

