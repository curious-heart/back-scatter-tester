#include "hv_connsettings.h"
#include "ui_hv_connsettings.h"

hv_connsettings::hv_connsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hv_connsettings)
{
    ui->setupUi(this);
}

hv_connsettings::~hv_connsettings()
{
    delete ui;
}
