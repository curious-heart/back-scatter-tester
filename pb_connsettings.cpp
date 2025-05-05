#include "pb_connsettings.h"
#include "ui_pb_connsettings.h"

pb_connsettings::pb_connsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pb_connsettings)
{
    ui->setupUi(this);
}

pb_connsettings::~pb_connsettings()
{
    delete ui;
}
