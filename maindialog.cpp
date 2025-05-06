#include "maindialog.h"
#include "ui_maindialog.h"

static const char* gs_str_hv_conn_settings_dlg_id_str = "hv_conn_settings";
static const char* gs_str_pb_conn_settings_dlg_id_str = "pb_conn_settings";

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog), m_key_filter(this, this)
{
    ui->setupUi(this);

    m_key_filter.add_keys_to_filter(Qt::Key_Escape);
    installEventFilter(&m_key_filter);


    m_hv_conn_settings_dlg = new SerialPortSetDlg(this, &m_dev_conn_params.hv_conn_params,
                                                  gs_str_hv_conn_settings_dlg_id_str,
                                                  ui->hvConnSetPbt->text());
    m_pb_conn_settings_dlg = new SerialPortSetDlg(this, &m_dev_conn_params.pb_conn_params,
                                                  gs_str_pb_conn_settings_dlg_id_str,
                                                  ui->dataCollConnSetPbt->text());
    m_init_ok = true;
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::on_dataCollConnSetPbt_clicked()
{
}


void MainDialog::on_hvConnSetPbt_clicked()
{
    int dlg_ret = m_hv_conn_settings_dlg->exec();

    if(QDialog::Accepted == dlg_ret && m_dev_conn_params.hv_conn_params.valid)
    {
        ui->hvConnSetDispEdit->setText(m_dev_conn_params.hv_conn_params.info_str);
    }
}


void MainDialog::on_pbConnSetPbt_clicked()
{
    int dlg_ret = m_pb_conn_settings_dlg->exec();

    if(QDialog::Accepted == dlg_ret && m_dev_conn_params.pb_conn_params.valid)
    {
        ui->pbConnSetDispEdit->setText(m_dev_conn_params.pb_conn_params.info_str);
    }
}

