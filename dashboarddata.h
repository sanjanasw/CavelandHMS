#ifndef DASHBOARDDATA_H
#define DASHBOARDDATA_H

#include "dbconnection.h"

#include <QtCharts>
#include <QtSql>

class dashboarddata
{
public:
    dashboarddata();
    static void getDashboardData();
    static QPieSeries* getGenderChart();
    static QString* getRoomData();
};

#endif // DASHBOARDDATA_H
