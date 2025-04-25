/*
 * bsp_hwdefs.h.h
 *
 */
#ifndef _BSP_HWDEFS_H_
#define _BSP_HWDEFS_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

 /* FT900 libraries */
#include "ft900_uart_simple.h"
#include "ft900_sdhost.h"
#include "ft900_spi.h"
#include "ft900_gpio.h"
#include "ft900_rtc.h"
#include "ft900_interrupt.h"
#include "ft900_i2cm.h"
#include "ft900.h"
#include "ft900_delay.h"

/**********************
 *      MACROS
 **********************/

#define GPIO_UART0_TX (48)
#define GPIO_UART0_RX (49)
#define GPIO_UART1_TX (52)
#define GPIO_UART1_RX (53)

#define GPIO_SPIM_CLK (27)
#define GPIO_SPIM_SS0 (28)
#define GPIO_SPIM_MOSI (29)
#define GPIO_SPIM_MISO (30)

#define GPIO_SPIM_IO2 (31)
#define GPIO_SPIM_IO3 (32)

#define GPIO_SPIM_SS1 (33)
#define GPIO_SPIM_SS2 (34)

#define GPIO_FT800_INT (0)
#define GPIO_FT800_PWD (1)

#define GPIO_SD_CLK (19)
#define GPIO_SD_CMD (20)
#define GPIO_SD_DAT3 (21)
#define GPIO_SD_DAT2 (22)
#define GPIO_SD_DAT1 (23)
#define GPIO_SD_DAT0 (24)
#define GPIO_SD_CD (25)
#define GPIO_SD_WP (26)

 /** @brief LED gpio pin */
#define RGB_LED_POWER_ENABLE_PIN	58
#define RGB_LED_CLK_PIN	       56
#define RGB_LED_DATA_PIN	   57

/** @brief switch gpio pin */
#define SWITCH_ID0				6
#define SWITCH_ID1				7
#define SWITCH_ID2				8
#define SWITCH_ID3				9

/** @brief 8bit I2C address for the temperature sensor */
#define TEMP_SENSOR_ADDRESS	    (0x90)
#define TEMP_SENSOR_I2C0_SCL    44
#define TEMP_SENSOR_I2C0_SDA    45

/** @brief mic I2S pin */
#define MIC_I2S_SDAO            60
#define MIC_I2S_SDAI            61
#define MIC_I2S_BCLK            62
#define MIC_I2S_LRCLK           63
#define MIC_I2S_MCLK            64
#define MIC_CLK24_EN            65
#define MIC_CLK24_IN            66

/** @brief 7bit I2C address converted to 8 bit for light sensor*/
#define ALS_ADDRESS             (0x29 << 1)
#define ALS_I2C1_SCL            46
#define ALS_I2C1_SDA            47


 /* Timer 1 is been utilized in case of FT900 platform */
#define FT900_FT_MILLIS_TIMER (timer_select_b)
#define FT900_TIMER_MAX_VALUE (65536L)
#define FT900_TIMER_PRESCALE_VALUE (100)
#define FT900_TIMER_OVERFLOW_VALUE (1000)

#ifndef RTC_PRESENT
#ifdef FT900_PLATFORM_RTC_I2C
#define RTC_PRESENT (1)
#endif
#endif /* RTC_PRESENT */

typedef enum {
	dvr_als = 0, //0x00000001
	dvr_eve,
	dvr_i2c,
	dvr_led,
	dvr_mic,
	dvr_sd,
	dvr_temp,
	dvr_max
} DRIVER_FAILFLAG_BITNUM;

#endif // _BSP_HWDEFS_H_
