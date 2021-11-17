#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

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
    void PopUpWindow::loading(bool loading);
    ~PopUpWindow();

private slots:
    void on_BtnClose_clicked();

    void on_BtnNewAdmission_clicked();

private:
    Ui::PopUpWindow *ui;
};

#endif // POPUPWINDOW_H
