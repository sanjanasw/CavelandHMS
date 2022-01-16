#ifndef STUDENTSDATA_H
#define STUDENTSDATA_H

#include "dbconnection.h"

#include <QString>

class StudentsData
{
public:
    StudentsData();
    static QStringList AddNewStudent(QStringList newData);
    static QStringList FindStudent(QString Id);
};

#endif // STUDENTSDATA_H
