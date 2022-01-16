#ifndef STAFF_H
#define STAFF_H

#include "dbconnection.h"

#include <QString>

class staff
{
public:
    staff();
    static bool AddNewUser(QStringList newData);
};

#endif // STAFF_H
