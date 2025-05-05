﻿#include "maindialog.h"
#include "logger/logger.h"
#include "version_def/version_def.h"
#include "sysconfigs/sysconfigs.h"

#include <QString>
#include "qtsingleapplication/qtsingleapplication.h"

int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
            QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    static const char* ls_app_id_str = "back-acatter-tester: an application for X-ray back scatter scanner debug and test.";
    static const char* ls_hint_str = "程序已经启动";
    QtSingleApplication a(QString(ls_app_id_str), argc, argv);

    if(a.isRunning())
    {
        return !a.sendMessage(QString(ls_hint_str));
    }

    MainDialog w;
    if(!w.m_init_ok) return -1;

    QThread th;
    int ret;

    start_log_thread(th, (LOG_LEVEL)(g_sys_configs_block.log_level));

    QString title_str = QString("%1 %2").arg(a.applicationName(), APP_VER_STR);
    w.setWindowTitle(title_str);

    w.show();
    a.setActivationWindow(&w);

    ret = a.exec();

    end_log_thread(th);
    return ret;
}
