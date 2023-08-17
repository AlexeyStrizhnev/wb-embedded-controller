#pragma once
#include <stdint.h>

#define REGMAP(m) \
    /*     Addr     Name            RO/RW */ \
    m(     0x00,    INFO,           RO, \
        /* 0x00 */  uint16_t wbec_id; \
        /* 0x01 */  uint16_t board_rev; \
        /* 0x02 */  uint16_t fw_ver_major : 8; \
        /* -//- */  uint16_t fw_ver_minor : 8; \
        /* 0x03 */  uint16_t fw_ver_patch : 8; \
        /* -//- */  int16_t fw_ver_suffix : 8; \
        /* 0x04 */  uint16_t poweron_reason; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x10,    RTC_TIME,       RW, \
        /* 0x10 */  uint16_t seconds : 8; \
        /* -//- */  uint16_t minutes : 8; \
        /* 0x11 */  uint16_t hours : 8; \
        /* -//- */  uint16_t days : 8; \
        /* 0x12 */  uint16_t weekdays : 8; \
        /* -//- */  uint16_t months : 8; \
        /* 0x13 */  uint16_t years; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x20,    RTC_ALARM,      RW, \
        /* 0x20 */  uint16_t seconds : 8; \
        /* -//- */  uint16_t minutes : 8; \
        /* 0x21 */  uint16_t hours : 8; \
        /* -//- */  uint16_t days : 8; \
        /* 0x22 */  uint16_t en : 1; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x30,    RTC_CFG,        RW, \
        /* 0x30 */  uint16_t offset; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x40,    ADC_DATA,       RO, \
        /* 0x40 */  uint16_t v_in; \
        /* 0x41 */  uint16_t v_3_3; \
        /* 0x42 */  uint16_t v_5_0; \
        /* 0x43 */  uint16_t v_a1; \
        /* 0x44 */  uint16_t v_a2; \
        /* 0x45 */  uint16_t v_a3; \
        /* 0x46 */  uint16_t v_a4; \
        /* 0x47 */  int16_t temp; \
        /* 0x48 */  uint16_t vbus_console; \
        /* 0x49 */  uint16_t vbus_network; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x60,    ADC_CFG,        RW, \
        /* 0x60 */  uint16_t lowpass_rc_a1; \
        /* 0x61 */  uint16_t lowpass_rc_a2; \
        /* 0x62 */  uint16_t lowpass_rc_a3; \
        /* 0x63 */  uint16_t lowpass_rc_a4; \
        /* 0x64 */  uint16_t v_in_uvp; \
        /* 0x65 */  uint16_t v_in_ovp; \
        /* 0x66 */  uint16_t v_out_uvp; \
        /* 0x67 */  uint16_t v_out_ovp; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x80,    GPIO,           RW, \
        /* 0x80 */  uint16_t a1 : 1; \
        /* -//- */  uint16_t a2 : 1; \
        /* -//- */  uint16_t a3 : 1; \
        /* -//- */  uint16_t a4 : 1; \
        /* -//- */  uint16_t v_out : 1; \
        /* -//- */  uint16_t status_bat : 1; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0x90,    WDT,            RW, \
        /* 0x90 */  uint16_t timeout; \
        /* 0x91 */  uint16_t reset : 1; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0xA0,    POWER_CTRL,     RW, \
        /* 0xA0 */  uint16_t off : 1; \
        /* -//- */  uint16_t reboot : 1; \
        /* -//- */  uint16_t reset_pmic : 1; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0xB0,    IRQ_FLAGS,      RO, \
        /* 0xB0 */  uint16_t irqs; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0xB2,    IRQ_MSK,        RW, \
        /* 0xB2 */  uint16_t irqs; \
    ) \
    /*     Addr     Name            RO/RW */ \
    m(     0xB4,    IRQ_CLEAR,      RW, \
        /* 0xB4 */  uint16_t irqs; \
    ) \

// Общее число регистров в адресном пространстве
// Число должно быть больше или равно адресу последнего регистра
// Должно быть степенью двойки
// По этому числу происходит циклической автоинкремент адреса
#define REGMAP_TOTAL_REGS_COUNT         256

#define __REGMAP_STRUCTS(addr, name, rw, members)       struct __attribute__((packed)) REGMAP_##name { members };

REGMAP(__REGMAP_STRUCTS)
