#include "analyticsdata.h"

QLineSeries* series = new QLineSeries();

analyticsdata::analyticsdata()
{

}

//Return Revenue chart Qline series to draw that chart
QLineSeries* analyticsdata::getAnalyticsData(){
    //database connection
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery query;
            query.exec("EXEC GetRevenueData");
            if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                while (query.next()) {
                    int x = query.value(0).toInt();
                    int y = query.value(1).toInt();
                    series->append(x,y);
                }
            }

            db.close();
          }

    }  catch (...) {

    }
    return series;
}
