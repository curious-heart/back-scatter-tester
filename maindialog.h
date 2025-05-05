#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

#include "common_tools/common_tool_func.h"

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

private:
    Ui::MainDialog *ui;


    CToolKeyFilter m_key_filter;
};
#endif // MAINDIALOG_H
