#ifndef ANALYTICSDATA_H
#define ANALYTICSDATA_H

#include "dbconnection.h"

#include <QtCharts>

class analyticsdata
{
public:
    analyticsdata();
    static QLineSeries* getAnalyticsData();
};

#endif // ANALYTICSDATA_H
