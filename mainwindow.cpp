#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

QString loggedInUserName;
QStringList outputData;
int loggedInUserId;
QDate cd = QDate::currentDate();

//to populate data in Qtablewidget
void populateData(QString query, QTableWidget* table, QString titles){
    QSqlDatabase db = DBConnection::ConnectDb();
    QSqlQueryModel * model = new QSqlQueryModel();
    db.open();

    model->setQuery(query);
    table->setRowCount(model->rowCount());
    table->setColumnCount(model->columnCount());
    table->verticalHeader()->setVisible(false);
    table->setHorizontalHeaderLabels(titles.split(";"));
    for(int r =0; r < model->rowCount(); r++){
        for(int c = 0; c < model->columnCount(); c++){

            QString test = model->record(r).value(c).toString();
            QTableWidgetItem *item = new QTableWidgetItem(test);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            table->setItem(r,c,item);
            qDebug() << r << c << test;
        }
    }

    db.close();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    //buttons
    ui->BtnDashboard->setEnabled(false);
    ui->BtnRoom->setEnabled(false);
    ui->BtnStudent->setEnabled(false);
    ui->BtnAnalytics->setEnabled(false);
    ui->BtnExpansion->setEnabled(false);
    ui->BtnReport->setEnabled(false);
    ui->BtnStaff->setEnabled(false);

    //adminArea
    ui->LblNav2->setVisible(false);
    ui->BtnAnalytics->setVisible(false);
    ui->BtnExpansion->setVisible(false);
    ui->BtnReport->setVisible(false);
    ui->BtnStaff->setVisible(false);

    //logout
    ui->BtnLogOut->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnDashboard_clicked()
{
    //buttons
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px; \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");


    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();


    if(dashboarddata::getGenderChart()->isEmpty()){
        ui->LodingArea->show();
        ui->LblTitle->setText("Loading...");
        ui->LblTitle->repaint();
        dashboarddata::getDashboardData();


        QChart* genderChart = new QChart();
        genderChart->addSeries(dashboarddata::getGenderChart());

        QChartView* genderChartview = new QChartView(genderChart);
        genderChartview->setMaximumSize(ui->CrtGender->size());
        genderChartview->setParent(ui->CrtGender);


        QChart* revenueChart = new QChart();
        revenueChart->legend()->hide();
        revenueChart->addSeries(analyticsdata::getAnalyticsData());
        revenueChart->createDefaultAxes();

        QChartView* revenueChartView = new QChartView(revenueChart);
        revenueChartView->setRenderHint(QPainter::Antialiasing);
        revenueChartView->setMaximumSize(ui->CrtRevenue->size());
        revenueChartView->setParent(ui->CrtRevenue);

        QString* RoomData = dashboarddata::getRoomData();
        ui->LblTotalRooms->setText(RoomData[0]);
        ui->LblReservedRooms->setText(RoomData[1]);
        ui->LblAvailableRooms->setText(RoomData[2]);
        ui->LblTotalRooms_2->setText(RoomData[0]);
        ui->LblReservedRooms_2->setText(RoomData[1]);
        ui->LblAvailableRooms_2->setText(RoomData[2]);
        ui->LblTotalRooms_3->setText(RoomData[0]);
        ui->LblReservedRooms_3->setText(RoomData[1]);
        ui->LblAvailableRooms_3->setText(RoomData[2]);
        ui->LblBoysCount->setText(RoomData[3]);
        ui->LblGirlsCount->setText(RoomData[4]);
        ui->LblStaffCount->setText(RoomData[5]);

        QString studentsCountQuery = "SELECT University, COUNT(Id) AS Student_Count FROM Students GROUP BY University";
        QString buildingRoomDataQuery = "SELECT * FROM Building_Rooms";
        QString studentDataThisMonthQuery = "EXEC GetPaymentStatus @FromDate = '"+cd.toString("yyyy-MM-01")+"' , @ToDate = '"+cd.addMonths(1).toString("yyyy-MM-01")+"'";
        QString getStaffData = "SELECT UserName, TP, Email, Salary FROM Users WHERE ID <> 1";

        populateData(studentsCountQuery, ui->TblUniversityData, "University;Students");
        populateData(buildingRoomDataQuery, ui->TblBuildingsRooms, "Building Name;Single Rooms;Double Rooms;Rented Single Rooms; Rented Double Rooms");
        populateData(studentDataThisMonthQuery, ui->TblPaymentData, "Student;Room;Building;Number;University;Status");
        populateData(getStaffData, ui->TblStaff, "Name;Phone;Email;Salary");

        ui->LodingArea->hide();
    }
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");
    ui->LblTitle->setText("Dashboard");
    ui->DashobardArea->show();
}


void MainWindow::on_BtnRoom_clicked()
{
    //buttons
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Rooms");
    ui->RoomsArea->show();
}


void MainWindow::on_BtnStudent_clicked()
{
    //buttons
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Students");
    ui->StudentsArea->show();
}


void MainWindow::on_BtnAnalytics_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Analytics");
    ui->AnalyticsArea->show();
}


void MainWindow::on_BtnExpansion_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Expansions");
    ui->ExpansionsArea->show();
}


void MainWindow::on_BtnReport_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Reports");
    ui->ReportsArea->show();
}


void MainWindow::on_BtnStaff_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Staff");
    ui->StaffArea->show();
}


void MainWindow::on_BtnLogin_clicked()
{
    QString UserName = ui->TxtUserName->text();
    QString Password = ui->TxtPassword->text();
    ui->TxtUserName->clear();
    ui->TxtPassword->clear();
    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LodingArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->show();
    ui->LblTitle->setText("Loading...");
    ui->LblTitle->repaint();
    QString* UserData = Login::UserLogin(UserName, Password);
    int loginStatus = UserData[0].toInt();
    loggedInUserId = UserData[1].toInt();
    loggedInUserName = UserData[2];
    if(loginStatus == 1){

        //buttons
        ui->BtnDashboard->setEnabled(true);
        ui->BtnRoom->setEnabled(true);
        ui->BtnStudent->setEnabled(true);
//        ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");
//        ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px; \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
//        ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->LblUserName->setText("Hi,"+ loggedInUserName +"!");
        ui->BtnLogOut->setVisible(true);

        if(UserData[3] == "1"){
            //adminArea
            ui->LblNav2->setVisible(true);
            ui->BtnAnalytics->setVisible(true);
            ui->BtnExpansion->setVisible(true);
            ui->BtnReport->setVisible(true);
            ui->BtnStaff->setVisible(true);

            ui->BtnAnalytics->setEnabled(true);
            ui->BtnExpansion->setEnabled(true);
            ui->BtnReport->setEnabled(true);
            ui->BtnStaff->setEnabled(true);

        }

        ui->LoginArea->hide();
        ui->LodingArea->hide();
        MainWindow::on_BtnDashboard_clicked();
    }else{
        QMessageBox Msgbox;
        Msgbox.setText("Incorrect UserName or Password!!");
        Msgbox.exec();

        ui->LodingArea->hide();
        ui->LoginArea->show();
        ui->LblTitle->setText("Login");
        ui->LblTitle->repaint();
    }
}


void MainWindow::on_BtnLogOut_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Logout", "Are you sure?", QMessageBox::Yes | QMessageBox::No))
    {
        //buttons
        ui->BtnDashboard->setEnabled(false);
        ui->BtnRoom->setEnabled(false);
        ui->BtnStudent->setEnabled(false);
        ui->BtnAnalytics->setEnabled(false);
        ui->BtnExpansion->setEnabled(false);
        ui->BtnReport->setEnabled(false);
        ui->BtnStaff->setEnabled(false);

        //adminArea
        ui->LblNav2->setVisible(false);
        ui->BtnAnalytics->setVisible(false);
        ui->BtnExpansion->setVisible(false);
        ui->BtnReport->setVisible(false);
        ui->BtnStaff->setVisible(false);
        ui->DashobardArea->hide();
        ui->RoomsArea->hide();
        ui->StudentsArea->hide();
        ui->AnalyticsArea->hide();
        ui->ExpansionsArea->hide();
        ui->ReportsArea->hide();
        ui->StaffArea->hide();
        ui->LodingArea->hide();

        ui->LblUserName->setText("");
        ui->BtnLogOut->setVisible(false);
        ui->LblTitle->setText("Login");
        loggedInUserId = 0;
        loggedInUserName = "";

        ui->LoginArea->show();
    }

}


void MainWindow::on_TxtStudentId_textEdited(const QString &arg1)
{
    ui->BtnStudentSearch->setEnabled(true);
}



void MainWindow::on_CmbRange_currentTextChanged(const QString &arg1)
{
    if(arg1 == "This Month"){
        ui->DashobardArea->hide();
        ui->RoomsArea->hide();
        ui->StudentsArea->hide();
        ui->AnalyticsArea->hide();
        ui->ExpansionsArea->hide();
        ui->ReportsArea->hide();
        ui->StaffArea->hide();
        ui->LodingArea->hide();
        ui->LoginArea->hide();
        ui->LodingArea->show();
        ui->LblTitle->setText("Loading...");
        ui->LblTitle->repaint();

        QString studentDataThisMonthQuery = "EXEC GetPaymentStatus @FromDate = '"+cd.toString("yyyy-MM-01")+"' , @ToDate = '"+cd.addMonths(1).toString("yyyy-MM-01")+"'";
        populateData(studentDataThisMonthQuery, ui->TblPaymentData, "Student;Room;Building;Number;University;Status");
        ui->StudentsArea->show();
        ui->LblTitle->setText("Students");

    }else if(arg1 == "Last Month"){
        ui->DashobardArea->hide();
        ui->RoomsArea->hide();
        ui->StudentsArea->hide();
        ui->AnalyticsArea->hide();
        ui->ExpansionsArea->hide();
        ui->ReportsArea->hide();
        ui->StaffArea->hide();
        ui->LodingArea->hide();
        ui->LoginArea->hide();
        ui->LodingArea->show();
        ui->LblTitle->setText("Loading...");
        ui->LblTitle->repaint();

        QString studentDataThisMonthQuery = "EXEC GetPaymentStatus @FromDate = '"+cd.addMonths(-1).toString("yyyy-MM-01")+"' , @ToDate = '"+cd.toString("yyyy-MM-01")+"'";
        populateData(studentDataThisMonthQuery, ui->TblPaymentData, "Student;Room;Building;Number;University;Status");
        ui->StudentsArea->show();
        ui->LblTitle->setText("Students");

    }

}


void MainWindow::on_BtnNewAdmission_clicked()
{
    outputData.clear();
    outputData.append("1");
    PopUpWindow* p = new PopUpWindow(outputData);
    p->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    p->show();
}


void MainWindow::on_BtnNewAdmission_2_clicked()
{
    outputData.clear();
    outputData.append("2");
    PopUpWindow* p = new PopUpWindow(outputData);
    p->show();
}

