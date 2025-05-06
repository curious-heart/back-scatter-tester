#ifndef SYSCONFIGS_H
#define SYSCONFIGS_H

#include <QString>

#define ENUM_NAME_DEF(e) e,
#define MB_CUBE_CURRENT_UNIT_E \
    ENUM_NAME_DEF(MB_CUBE_CURRENT_UNIT_UA)\
    ENUM_NAME_DEF(MB_CUBE_CURRENT_UNIT_MA)\
    ENUM_NAME_DEF(MB_CUBE_CURRENT_UNIT_A)
typedef enum
{
    MB_CUBE_CURRENT_UNIT_E
}mb_cube_current_unit_e_t;

#define MB_DURA_UNIT_E \
    ENUM_NAME_DEF(MB_DURA_UNIT_MS) \
    ENUM_NAME_DEF(MB_DURA_UNIT_SEC) \
    ENUM_NAME_DEF(MB_DURA_UNIT_MIN)
typedef enum
{
    MB_DURA_UNIT_E
}mb_dura_unit_e_t;

#define UI_DISP_TUBE_OR_OILBOX_E \
    ENUM_NAME_DEF(UI_DISP_TUBE_NO) \
    ENUM_NAME_DEF(UI_DISP_OILBOX_NO)
typedef enum
{
    UI_DISP_TUBE_OR_OILBOX_E
}ui_disp_tube_or_oilbox_str_e_t;

typedef struct
{
    int log_level;

    int mb_srvr_address, mb_resp_wait_time_ms;
}sys_configs_struct_t;

extern sys_configs_struct_t g_sys_configs_block;

bool fill_sys_configs(QString *);

#endif // SYSCONFIGS_H
