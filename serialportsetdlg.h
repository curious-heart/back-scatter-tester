#ifndef SERIALPORTSETDLG_H
#define SERIALPORTSETDLG_H

#include <QString>
#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QSerialPort>

#include "config_recorder/uiconfigrecorder.h"

namespace Ui {
class SerialPortSetDlg;
}

class SerialPortSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortSetDlg(QWidget *parent = nullptr,
                              QString dlg_id_str = "", QString dlg_name_str = "",
                              QSerialPort::BaudRate baudrate = QSerialPort::Baud115200,
                              QSerialPort::DataBits databits = QSerialPort::Data8,
                              QSerialPort::Parity parity = QSerialPort::NoParity,
                              QSerialPort::StopBits stopbits = QSerialPort::OneStop);
    ~SerialPortSetDlg();

private slots:
    void on_sPortButtonBox_clicked(QAbstractButton *button);

private:
    Ui::SerialPortSetDlg *ui;
    QString m_dlg_id_str, m_dlg_name_str;

    typedef struct
    {
        int val;
        QString s;
    }combobox_item_struct_t;

    QSerialPort::BaudRate m_def_baudrate;
    QSerialPort::DataBits m_def_databits;
    QSerialPort::Parity m_def_parity;
    QSerialPort::StopBits m_def_stopbits;

    static const combobox_item_struct_t baudrate_list[], databits_list[],
                                        parity_list[], stopbits_list[];

    UiConfigRecorder * m_cfg_recorder = nullptr;
    qobj_ptr_set_t m_rec_ui_cfg_fin, m_rec_ui_cfg_fout;
};

#endif // SERIALPORTSETDLG_H
