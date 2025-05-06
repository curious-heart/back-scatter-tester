#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

#include "common_tools/common_tool_func.h"

#include "serialportsetdlg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainDialog; }
QT_END_NAMESPACE

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();
    bool m_init_ok = false;

private slots:
    void on_dataCollConnSetPbt_clicked();

    void on_hvConnSetPbt_clicked();

private:
    Ui::MainDialog *ui;

    CToolKeyFilter m_key_filter;

    SerialPortSetDlg * m_pb_conn_settings_dlg = nullptr, * m_hv_conn_settings_dlg = nullptr;
};
#endif // MAINDIALOG_H
