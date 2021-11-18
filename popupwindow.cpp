#include "popupwindow.h"
#include "ui_popupwindow.h"

QStringList inputData;

PopUpWindow::PopUpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopUpWindow)
{
    ui->setupUi(this);
}

PopUpWindow::PopUpWindow(QStringList inData) :
    ui(new Ui::PopUpWindow)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    inputData = inData;
    switch(inData[0].toInt()) {
      case 1:
        populateCmbBuilding();
        loading(false);
        ui->LblTitle->setText("New Admission");
        ui->NewAdmission->show();
        break;
      case 2:
        loading(false);
        ui->LblTitle->setText("Collect Rental");
        ui->CollectRental->show();
        break;
        case 3:
        loading(false);
          ui->LblTitle->setText("Leaving From Room");
          ui->Leaving->show();
          break;
      default:
        PopUpWindow::close();;
    }
}

PopUpWindow::~PopUpWindow()
{
    delete ui;
}

void PopUpWindow::on_BtnClose_clicked()
{
    PopUpWindow::close();
}

void PopUpWindow::adminSuccess(QStringList userData){
    loading(false);
    ui->LblName->setText(ui->LblName->text()+userData[0]);
    ui->LblAdmission->setText(ui->LblAdmission->text()+userData[1]);
    ui->LblRoomNo->setText(ui->LblRoomNo->text()+userData[2]);
    ui->LblRental->setText(ui->LblRental->text()+userData[3]);
    ui->LblTitle->setText("Admission Success");
    ui->NewAdmissionSuccess->show();
}


void PopUpWindow::on_BtnNewAdmission_clicked()
{
    PopUpWindow::close();
}

void PopUpWindow::loading(bool loading){
    if(loading){
        ui->NewAdmission->hide();
        ui->CollectRental->hide();
        ui->Leaving->hide();
        ui->NewAdmissionSuccess->hide();
        ui->Loading->show();
        ui->LblTitle->setText("Loading...");
        ui->LblTitle->repaint();
    }else{
        ui->NewAdmission->hide();
        ui->CollectRental->hide();
        ui->Leaving->hide();
        ui->NewAdmissionSuccess->hide();
        ui->Loading->hide();
    }

}

void PopUpWindow::populateCmbBuilding(){
    loading(true);
    ui->CmbBuliding->addItem("SELECT BUILDING");
    QSqlDatabase db = DBConnection::ConnectDb();
     try {
         if(db.open()){
             QSqlQuery query;
             query.exec("SELECT Name FROM Buildings");
             if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                 while (query.next()) {
                     ui->CmbBuliding->addItem(query.value(0).toString());
                 }
              }
         }
         db.close();
        }  catch (...) {

        }
}

void PopUpWindow::populateCmbRoom(int building){
    ui->CmbRoom->addItem("SELECT ROOM");
    QSqlDatabase db = DBConnection::ConnectDb();
     try {
         if(db.open()){
             QSqlQuery query;
             query.exec("SELECT Id FROM Rooms WHERE Building_id = " + QString::number(building) + ";");
             if (!db.driver()->hasFeature(QSqlDriver::QuerySize)) {
                 while (query.next()) {
                     ui->CmbRoom->addItem(query.value(0).toString());
                 }
              }
         }
         db.close();
        }  catch (...) {

        }
}



void PopUpWindow::on_CmbBuliding_currentIndexChanged(int index)
{
    if(index != 0){
        loading(true);
        populateCmbRoom(index);
        loading(false);
        ui->LblTitle->setText("New Admission");
        ui->NewAdmission->show();
    }
}


void PopUpWindow::on_BtnClose2_clicked()
{
    PopUpWindow::close();
}


void PopUpWindow::on_BtnAdmissionSubmit_clicked()
{
    loading(true);
    QStringList newData;
    newData.append(ui->TxtName->text());
    newData.append(ui->TxtNIC->text());
    newData.append(ui->TxtAddress->text());
    newData.append(ui->TxtNumber->text());
    newData.append(ui->TxtEmail->text());
    newData.append(ui->TxtUni->text());
    newData.append(ui->CmbRoom->currentText());
    QStringList newStudent = StudentsData::AddNewUser(newData);
    newData.clear();
    adminSuccess(newStudent);
    newStudent.clear();

}

