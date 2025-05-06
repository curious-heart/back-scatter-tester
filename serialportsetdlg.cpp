#include "serialportsetdlg.h"
#include "ui_serialportsetdlg.h"

SerialPortSetDlg::SerialPortSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPortSetDlg)
{
    ui->setupUi(this);
}

SerialPortSetDlg::~SerialPortSetDlg()
{
    delete ui;
}
