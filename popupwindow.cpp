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
    inputData = inData;
    ui->setupUi(this);
    switch(inData[0].toInt()) {
      case 1:
        ui->LblTitle->setText("New Admission");
        ui->NewAdmissionSuccess->hide();
        ui->CollectRental->hide();
        ui->Leaving->hide();
        ui->NewAdmission->show();
        if(true){
            QStringList neUser = { "Sanjana Sulakshana", "1002729", "Building|M|2", "041" };
            adminSuccess(neUser);
        }
        break;
      case 2:
        ui->LblTitle->setText("Collect Rental");
        ui->NewAdmission->hide();
        ui->NewAdmissionSuccess->hide();
        ui->Leaving->hide();
        ui->CollectRental->show();
        break;
        case 3:
          ui->LblTitle->setText("Leaving From Room");
          ui->NewAdmission->hide();
          ui->NewAdmissionSuccess->hide();
          ui->CollectRental->hide();
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
    ui->NewAdmission->hide();
    ui->CollectRental->hide();
    ui->Leaving->hide();
    ui->NewAdmissionSuccess->show();
    ui->LblName->setText(ui->LblName->text()+userData[0]);
    ui->LblAdmission->setText(ui->LblAdmission->text()+userData[1]);
    ui->LblBuilding->setText(ui->LblBuilding->text()+userData[2]);
    ui->LblRoomNo->setText(ui->LblRoomNo->text()+userData[3]);
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
        ui->LblTitle->setText("Loading...");
        ui->Loading->show();
    }else{
        ui->NewAdmission->hide();
        ui->CollectRental->hide();
        ui->Leaving->hide();
        ui->NewAdmissionSuccess->hide();
        ui->Loading->hide();
    }

}
