#include "analyticsdata.h"

QLineSeries* series = new QLineSeries();

analyticsdata::analyticsdata()
{

}

QLineSeries* analyticsdata::getAnalyticsData(){
    //database connection
    QSqlDatabase db = DBConnection::ConnectDb();
    try {
        if(db.open()){
            QSqlQuery query;
            qDebug() << "Opened!!";
            query.exec("EXEC GetRevenueData");
            if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                while (query.next()) {
                    int x = query.value(0).toInt();
                    int y = query.value(1).toInt();
                    series->append(x,y);
                    qDebug() << x << y;
                }
            }

            db.close();
          }

    }  catch (...) {

    }
    return series;
}
