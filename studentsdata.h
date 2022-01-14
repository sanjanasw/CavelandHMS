#ifndef STUDENTSDATA_H
#define STUDENTSDATA_H
#include <QString>

#include "dbconnection.h"

class StudentsData
{
public:
    StudentsData();
    static QStringList AddNewUser(QStringList newData);
    static QStringList FindNewUser(QString Id);
};

#endif // STUDENTSDATA_H
