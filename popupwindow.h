#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include "dbconnection.h"
#include "studentsdata.h"
#include "analyticsdata.h"

#include <QWidget>

namespace Ui {
class PopUpWindow;
}

class PopUpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PopUpWindow(QWidget *parent = nullptr);
    explicit PopUpWindow(QStringList inData);
    void adminSuccess(QStringList userData);
    void loading(bool loading);
    void populateCmbBuilding();
    void populateCmbRoom(int building);
    ~PopUpWindow();

private slots:
    void on_BtnClose_clicked();

    void on_BtnNewAdmission_clicked();

    void on_CmbBuliding_currentIndexChanged(int index);

    void on_BtnClose2_clicked();

    void on_BtnAdmissionSubmit_clicked();

    void on_BtnClose2_2_clicked();

    void on_BtnCollect_clicked();

    void on_BtnNewAdmission_3_clicked();

    void on_BtnClose2_3_clicked();

private:
    Ui::PopUpWindow *ui;
};

#endif // POPUPWINDOW_H
