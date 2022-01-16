#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbconnection.h"
#include "dashboarddata.h"
#include "login.h"
#include "analyticsdata.h"
#include "popupwindow.h"
#include "staff.h"
#include "expansions.h"

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QLineSeries>
#include <QMessageBox>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void loading(bool loading);
    void setupButtons();
    void populateCmbBuilding();
    void populateData(QString query, QTableWidget* table, QString titles);
    ~MainWindow();

private slots:
    void on_BtnDashboard_clicked();

    void on_BtnRoom_clicked();

    void on_BtnStudent_clicked();

    void on_BtnAnalytics_clicked();

    void on_BtnExpansion_clicked();

    void on_BtnStaff_clicked();

    void on_BtnLogin_clicked();

    void on_BtnLogOut_clicked();

    void on_TxtStudentId_textEdited();

    void on_CmbRange_currentTextChanged(const QString &arg1);

    void on_BtnNewAdmission_clicked();

    void on_BtnCollectRental_clicked();

    void on_BtnNewAdmission_3_clicked();

    void on_BtnStudentSearch_clicked();

    void on_BtnSatffSubmit_clicked();

    void on_BtnAddNewRoom_clicked();

    void on_BtnAddNewBuilding_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
