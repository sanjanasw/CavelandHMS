#ifndef EXPANSIONS_H
#define EXPANSIONS_H

#include "dbconnection.h"

#include <QtSql>
#include <QtDebug>
class expansions
{
public:
    expansions();
    static bool addNewRooms(int BuildingId, QString RoomType, QString Rental, QString RoomCount);
    static bool addNewBuilding(QString Building);
};

#endif // EXPANSIONS_H
