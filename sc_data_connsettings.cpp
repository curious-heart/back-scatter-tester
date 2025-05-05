#include "sc_data_connsettings.h"
#include "ui_sc_data_connsettings.h"

sc_data_connsettings::sc_data_connsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sc_data_connsettings)
{
    ui->setupUi(this);
}

sc_data_connsettings::~sc_data_connsettings()
{
    delete ui;
}
