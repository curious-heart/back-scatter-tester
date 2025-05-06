#ifndef HV_CONNSETTINGS_H
#define HV_CONNSETTINGS_H

#include <QDialog>

namespace Ui {
class hv_connsettings;
}

class hv_connsettings : public QDialog
{
    Q_OBJECT

public:
    explicit hv_connsettings(QWidget *parent = nullptr);
    ~hv_connsettings();

private:
    Ui::hv_connsettings *ui;
};

#endif // HV_CONNSETTINGS_H
