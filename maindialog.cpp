#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog), m_key_filter(this, this)
{
    ui->setupUi(this);

    m_key_filter.add_keys_to_filter(Qt::Key_Escape);
    installEventFilter(&m_key_filter);

    m_init_ok = true;
}

MainDialog::~MainDialog()
{
    delete ui;
}

