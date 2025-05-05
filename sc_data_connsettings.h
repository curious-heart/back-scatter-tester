#ifndef SC_DATA_CONNSETTINGS_H
#define SC_DATA_CONNSETTINGS_H

#include <QDialog>

namespace Ui {
class sc_data_connsettings;
}

class sc_data_connsettings : public QDialog
{
    Q_OBJECT

public:
    explicit sc_data_connsettings(QWidget *parent = nullptr);
    ~sc_data_connsettings();

private:
    Ui::sc_data_connsettings *ui;
};

#endif // SC_DATA_CONNSETTINGS_H
