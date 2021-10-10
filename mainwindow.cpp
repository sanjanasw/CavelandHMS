#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnDashboard_clicked()
{
    //buttons
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px; \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Dashboard");
    ui->DashobardArea->show();
}


void MainWindow::on_BtnRoom_clicked()
{
    //buttons
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Rooms");
    ui->RoomsArea->show();
}


void MainWindow::on_BtnStudent_clicked()
{
    //buttons
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Students");
    ui->StudentsArea->show();
}


void MainWindow::on_BtnAnalytics_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Analytics");
    ui->AnalyticsArea->show();
}


void MainWindow::on_BtnExpansion_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Expansions");
    ui->ExpansionsArea->show();
}


void MainWindow::on_BtnReport_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Reports");
    ui->ReportsArea->show();
}


void MainWindow::on_BtnStaff_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->LogsArea->hide();
    ui->LblTitle->setText("Staff");
    ui->StaffArea->show();
}


void MainWindow::on_BtnLog_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 60px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LblTitle->setText("Logs");
    ui->LogsArea->show();
}

