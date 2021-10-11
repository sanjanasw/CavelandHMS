#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnection.h"
#include "login.h"
#include <QMessageBox>


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
    ui->BtnLog->setEnabled(false);
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->StaffArea->hide();
    ui->LogsArea->hide();
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
    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->LogsArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Staff");
    ui->StaffArea->show();
}


void MainWindow::on_BtnLog_clicked()
{
    ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
    ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

    ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");

    ui->DashobardArea->hide();
    ui->RoomsArea->hide();
    ui->StudentsArea->hide();
    ui->AnalyticsArea->hide();
    ui->ExpansionsArea->hide();
    ui->ReportsArea->hide();
    ui->StaffArea->hide();
    ui->LoginArea->hide();
    ui->LodingArea->hide();
    ui->LblTitle->setText("Logs");
    ui->LogsArea->show();
}


void MainWindow::on_BtnLogin_clicked()
{
    QString UserName = ui->TxtUserName->text();
    QString Password = ui->TxtPassword->text();
    ui->LoginArea->hide();
    ui->LodingArea->show();
    ui->LblTitle->setText("Loading...");
    ui->LblTitle->repaint();
    int loginStatus = Login::UserLogin(UserName, Password);
    if(loginStatus == 1){

        //buttons
        ui->BtnDashboard->setEnabled(true);
        ui->BtnRoom->setEnabled(true);
        ui->BtnStudent->setEnabled(true);
        ui->BtnAnalytics->setEnabled(true);
        ui->BtnExpansion->setEnabled(true);
        ui->BtnReport->setEnabled(true);
        ui->BtnStaff->setEnabled(true);
        ui->BtnLog->setEnabled(true);
        ui->BtnDashboard->setStyleSheet("QPushButton{ background-color: rgb(27, 43, 101); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;}");
        ui->BtnRoom->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px; \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->BtnStudent->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->BtnAnalytics->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->BtnExpansion->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->BtnReport->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->BtnStaff->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");
        ui->BtnLog->setStyleSheet("QPushButton{ background-color: rgb(8, 26, 81); \n color: rgb(255, 255, 255); \n border-top-left-radius: 10px; \n border-bottom-left-radius: 10px;  \n text-align: left;\npadding-left: 40px;} \n QPushButton:hover{background-color: rgb(27, 43, 101);}");

        ui->LoginArea->hide();
        ui->LodingArea->hide();
        ui->LblTitle->setText("Dashboard");
        ui->DashobardArea->show();
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

