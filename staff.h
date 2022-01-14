#ifndef STAFF_H
#define STAFF_H
#include <QString>

#include "dbconnection.h"

class staff
{
public:
    staff();
    static bool AddNewUser(QStringList newData);
};

#endif // STAFF_H
