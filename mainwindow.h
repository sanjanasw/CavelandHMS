#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BtnDashboard_clicked();

    void on_BtnRoom_clicked();

    void on_BtnStudent_clicked();

    void on_BtnAnalytics_clicked();

    void on_BtnExpansion_clicked();

    void on_BtnReport_clicked();

    void on_BtnStaff_clicked();

    void on_BtnLog_clicked();

    void on_BtnLogin_clicked();

    void on_BtnLogOut_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
