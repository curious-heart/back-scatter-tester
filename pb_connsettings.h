#ifndef PB_CONNSETTINGS_H
#define PB_CONNSETTINGS_H

#include <QDialog>

namespace Ui {
class pb_connsettings;
}

class pb_connsettings : public QDialog
{
    Q_OBJECT

public:
    explicit pb_connsettings(QWidget *parent = nullptr);
    ~pb_connsettings();

private:
    Ui::pb_connsettings *ui;
};

#endif // PB_CONNSETTINGS_H
