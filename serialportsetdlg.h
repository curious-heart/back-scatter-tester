#ifndef SERIALPORTSETDLG_H
#define SERIALPORTSETDLG_H

#include <QDialog>

namespace Ui {
class SerialPortSetDlg;
}

class SerialPortSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortSetDlg(QWidget *parent = nullptr);
    ~SerialPortSetDlg();

private:
    Ui::SerialPortSetDlg *ui;
};

#endif // SERIALPORTSETDLG_H
