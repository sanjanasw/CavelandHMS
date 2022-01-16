#ifndef EXPANSIONS_H
#define EXPANSIONS_H

#include "dbconnection.h"

#include <QtSql>

class expansions
{
public:
    expansions();
    static bool addNewRooms(int BuildingId, QString RoomType, QString Rental, QString RoomCount);
};

#endif // EXPANSIONS_H
