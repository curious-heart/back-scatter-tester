﻿#include <QSettings>

#include "logger/logger.h"
#include "common_tools/common_tool_func.h"
#include "sysconfigs/sysconfigs.h"

#undef ENUM_NAME_DEF
#define ENUM_NAME_DEF(e) <<e

static const char* gs_sysconfigs_file_fpn = "configs/configs.ini";

static const char* gs_ini_grp_sys_cfgs = "sys_cfgs";
static const char* gs_ini_key_log_level = "log_level";

static const char* gs_ini_grp_hv_modbus_conn = "hv_modbus_conn";
static const char* gs_ini_key_mb_srvr_address = "mb_srvr_address";
static const char* gs_ini_key_mb_resp_wait_time_ms = "mb_resp_wait_time_ms";


static const char* gs_ini_grp_expo_ctrl = "expo_ctrl";
static const char* gs_ini_key_cool_dura_factor = "cool_dura_factor";
static const char* gs_ini_key_extra_cool_time_ms = "extra_cool_time_ms";
static const char* gs_ini_key_expo_prepare_time_ms = "expo_prepare_tims_ms";
static const char* gs_ini_key_mb_consec_rw_wait_ms = "mb_consec_rw_wait_ms";
static const char* gs_ini_key_mb_err_retry_wait_ms = "mb_err_retry_wait_ms";
static const char* gs_ini_key_mb_one_cmd_round_time_ms = "mb_one_cmd_round_time_ms";

static const char* gs_ini_key_cube_volt_kv_min = "cube_volt_kv_min";
static const char* gs_ini_key_cube_volt_kv_max = "cube_volt_kv_max";
static const char* gs_ini_key_cube_current_ma_min = "cube_current_ma_min";
static const char* gs_ini_key_cube_current_ma_max = "cube_current_ma_max";
static const char* gs_ini_key_dura_sec_min = "dura_sec_min";
static const char* gs_ini_key_dura_sec_max = "dura_sec_max";
static const char* gs_ini_key_mb_reconnect_wait_sep_ms = "mb_reconnect_wait_sep_ms";
static const char* gs_ini_key_test_time_stat_grain_sec = "test_time_stat_grain_sec";

static const char* gs_ini_key_coil_current_a_min = "coil_current_a_min";
static const char* gs_ini_key_coil_current_a_max = "coil_current_a_max";

static const char* gs_ini_key_mb_cube_current_intf_unit = "mb_cube_current_intf_unit";
static const char* gs_ini_key_ui_current_unit = "ui_current_unit";

static const char* gs_ini_key_mb_dura_intf_unit = "mb_dura_intf_unit";
static const char* gs_ini_key_hidden_ui_mb_dura_unit = "hidden_ui_mb_dura_unit";

static const char* gs_ini_key_test_proc_monitor_period_ms = "test_proc_monitor_period_ms";

static const char* gs_ini_grp_ui_disp_cfg = "ui_disp_cfg";
static const char* gs_ini_key_distance_group_disp = "distance_group_disp";
static const char* gs_ini_key_sw_ver_disp = "sw_ver_disp";
static const char* gs_ini_key_hw_ver_disp = "hw_ver_disp";
static const char* gs_ini_key_hv_ctrl_board_no_disp = "hv_ctrl_board_no_disp";
static const char* gs_ini_key_tube_or_oilbox_no_disp = "tube_or_oilbox_no_disp";

const char* g_str_cube_volt = "管电压";
const char* g_str_cube_current = "管电流";
const char* g_str_current = "电流";
const char* g_str_expo_dura = "曝光时间";
const char* g_str_coil_current = "灯丝电流";
const char* g_str_volt_unit_kv = "kV";
const char* g_str_current_unit_a = "A";
const char* g_str_current_unit_ma = "mA";
const char* g_str_current_unit_ua = "uA";
const char* g_str_dura_unit_min = "min";
const char* g_str_dura_unit_s = "s";
const char* g_str_dura_unit_ms = "ms";
const char* g_str_and = "与";

sys_configs_struct_t g_sys_configs_block;

static const int gs_def_log_level = LOG_ERROR;
static const int gs_def_mb_srvr_address = 1;
static const int gs_def_mb_resp_wait_time_ms = 3000;

static const int gs_def_cube_volt_kv_min = 40;
static const int gs_def_cube_volt_kv_max = 90;
static const float gs_def_cube_current_ma_min = 0.5;
static const float gs_def_cube_current_ma_max = 5;
static const float gs_def_dura_sec_min = 0.5;
static const float gs_def_dura_sec_max = 1.4;

static const float gs_def_coil_current_a_min = 0;
static const float gs_def_coil_current_a_max = 2;

static const float gs_def_cool_dura_factor = 30;
static const int gs_def_extra_cool_time_ms = 2000;
static const int gs_def_expo_prepare_time_ms = 3500;
static const int gs_def_mb_consec_rw_wait_ms = 500;
static const int gs_def_mb_err_retry_wait_ms = 1000;
static const int gs_def_mb_reconnect_wait_sep_ms = 1000;
static const int gs_def_test_time_stat_grain_sec = 3;
static const int gs_def_mb_one_cmd_round_time_ms = 150;


static const int gs_def_test_proc_monitor_period_ms = 1000;

static const int gs_def_distance_group_disp = 1;
static const int gs_def_sw_ver_disp = 1;
static const int gs_def_hw_ver_disp = 1;
static const int gs_def_hv_ctrl_board_no_disp = 1;
static const ui_disp_tube_or_oilbox_str_e_t gs_def_tube_or_oilbox_no_disp = UI_DISP_OILBOX_NO;

static const char* gs_str_cfg_param_limit_error = "参数门限配置错误";
static const char* gs_str_plz_check = "请检查！";
static const char* gs_str_mb_intf_unit = "接口单位";
static const char* gs_str_mb_intf_unit_error = "接口单位配置错误";
static const char* gs_str_ui_unit_error = "ui显示单位配置错误";
static const char* gs_str_should_be_one_val_of = "应为如下值之一：";
static const char* gs_str_actual_val = "实际值";
static const char* gs_str_hidden_ui_mb_dura_unit = "GUI隐藏的曝光时间单位选项";
static const char* gs_str_cannot_be_the_same = "不能相等";

static const mb_cube_current_unit_e_t gs_def_mb_cube_current_intf_unit = MB_CUBE_CURRENT_UNIT_UA;
static const mb_cube_current_unit_e_t gs_def_ui_current_unit = MB_CUBE_CURRENT_UNIT_UA;

static const mb_dura_unit_e_t gs_def_mb_dura_intf_unit = MB_DURA_UNIT_MS;
static const mb_dura_unit_e_t gs_def_hidden_ui_mb_dura_unit = MB_DURA_UNIT_MIN;

static RangeChecker<int> gs_cfg_file_log_level_ranger((int)LOG_DEBUG, (int)LOG_ERROR, "",
                     EDGE_INCLUDED, EDGE_INCLUDED);

static RangeChecker<int> gs_cfg_file_value_ge0_int_ranger(0, 0, "",
                           EDGE_INCLUDED, EDGE_INFINITE);

static RangeChecker<float> gs_cfg_file_value_ge0_float_ranger(0, 0, "",
                       EDGE_INCLUDED, EDGE_INFINITE);

static RangeChecker<int> gs_cfg_file_value_gt0_int_ranger(0, 0, "",
                       EDGE_EXCLUDED, EDGE_INFINITE);

static RangeChecker<int> gs_cfg_file_value_01_int_ranger(0, 1, "",
                       EDGE_INCLUDED, EDGE_INCLUDED);

static RangeChecker<float> gs_cfg_file_value_gt0_float_ranger(0, 0, "",
                       EDGE_EXCLUDED, EDGE_INFINITE);

/*the __VA_ARGS__ should be empty or a type converter like (cust_type).*/
#define GET_INF_CFG_NUMBER_VAL(settings, key, type_func, var, def, factor, checker, ...)\
{\
    (var) = __VA_ARGS__((factor) * ((settings).value((key), (def)).type_func()));\
    if((checker) && !((checker)->range_check((var))))\
    {\
        (var) = (def);\
    }\
}

#define BEGIN_INT_RANGE_CHECK(low, up, low_inc, up_inc)\
{\
    RangeChecker<int> int_range_checker((low), (up), "", low_inc, up_inc);
#define END_INT_RANGE_CHECK \
}

bool fill_sys_configs(QString * ret_str_ptr)
{
    bool ret = true;

    QSettings settings(gs_sysconfigs_file_fpn, QSettings::IniFormat);

    /*--------------------*/
    settings.beginGroup(gs_ini_grp_sys_cfgs);
    GET_INF_CFG_NUMBER_VAL(settings, gs_ini_key_log_level, toInt,
                           g_sys_configs_block.log_level, gs_def_log_level,
                           1, &gs_cfg_file_log_level_ranger);
    settings.endGroup();

    /*--------------------*/
    settings.beginGroup(gs_ini_grp_hv_modbus_conn);
    GET_INF_CFG_NUMBER_VAL(settings, gs_ini_key_mb_srvr_address, toInt,
                           g_sys_configs_block.mb_srvr_address, gs_def_mb_srvr_address,
                           1, &gs_cfg_file_value_ge0_int_ranger);
    GET_INF_CFG_NUMBER_VAL(settings, gs_ini_key_mb_resp_wait_time_ms, toInt,
                           g_sys_configs_block.mb_resp_wait_time_ms, gs_def_mb_resp_wait_time_ms,
                           1, &gs_cfg_file_value_ge0_int_ranger);
    settings.endGroup();


    if(ret_str_ptr) *ret_str_ptr = "";
    return ret;
}
