/**
 * @file bsp_test.c
 * @brief Sample usage of IDP-5000-04A BSP
 *
 * @author Bridgetek
 *
 * @date 2025
 * 
 * MIT License
 *
 * Copyright (c) [2025] [Bridgetek Pte Ltd (BRTChip)]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "bsp_debug.h"
#include "bsp_hwdefs.h"
#include "eve_app.h"
#include "sdcard.h"
#include "rotary.h"
#include "rgbled.h"
#include "max31725.h"
#include "mic.h"
#include "als.h"

#define SW_BUILDDATE_STR __DATE__
#define SW_BUILDTIME_STR __TIME__
#define SW_TIMESTAMP_STR __DATE__ " " __TIME__
#define APP_TITLE_STR	 "IDP-5000-04A Application"

#define ENABLE_SD       1
#define ENABLE_EVE      1
#define ENABLE_LED      1
#define ENABLE_ROTARY   1
#define ENABLE_TEMP     1
#define ENABLE_MIC      1
#define ENABLE_ALS      1

static uint32_t dev_badflags = 0;

void init_bsp(void);
#if ENABLE_USBDBG
void tfp_putc(void* p, char c);
#endif
#if (ENABLE_TEMP || ENABLE_ALS)
bool i2c_init(void);
#endif

int main()
{
	init_bsp();

	while (true) {
#if ENABLE_MIC
		if ((dev_badflags & (1 << dvr_mic)) == 0)
		{
			uint32_t mic_data = mic_available();
			if (mic_data > 0)
				PR_INFO("mic data available\n");
		}
#endif
#if ENABLE_LED
		static uint8_t led_intensity = 0;
		led_intensity = (led_intensity + 16) & 0x1F;
		led_set_color(LED_GREEN, led_intensity);
#endif
#if ENABLE_ALS
		if ((dev_badflags & (1 << dvr_als)) == 0)
		{
			float lux;
			get_als_lux(&lux);
			PR_INFO("als lux %ld\n", (uint32_t)lux);
		}
#endif

		delayms(5000);
	}
}

void init_bsp(void)
{
	sys_reset_all();

	interrupt_enable_globally();

	sys_enable(sys_device_uart0);
	gpio_function(GPIO_UART0_TX, pad_uart0_txd); /* UART0 TXD */
	gpio_function(GPIO_UART0_RX, pad_uart0_rxd); /* UART0 RXD */
	uart_open(UART0, /* Device */
		1, /* Prescaler = 1 */
		UART_DIVIDER_115200_BAUD, /* Divider = 1302 */
		uart_data_bits_8, /* No. Data Bits */
		uart_parity_none, /* Parity */
		uart_stop_bits_1); /* No. Stop Bits */

#if ENABLE_USBDBG
	/* Init the tinyprintf module */
	init_printf(NULL, tfp_putc);
	/* Initialize the USB Debugging */
	usbdbg_init();
	delayms(1000);
#endif

	PR_INFO("\n%s\n", APP_TITLE_STR);
	PR_INFO("Build date: %s, %s\n", SW_BUILDDATE_STR, SW_BUILDTIME_STR);

#if ENABLE_ROTARY
	PR_INFO("rotary ID %d\n", read_rotary());
#endif

#if ENABLE_LED
	led_init();
	PR_INFO("LED initialised\n");
	led_set_color(LED_RED, LED_INTENSITY_HIGH);
	PR_INFO("LED red light\n");
#endif

#if (ENABLE_TEMP || ENABLE_ALS)
	if (!i2c_init())
	{
		dev_badflags |= (1 << dvr_i2c);
		PR_WARN("I2C initial fail\n");
	}
	else {
		PR_INFO("I2C initialised\n");
	}
#endif
#if ENABLE_TEMP
	if ((dev_badflags & (1 << dvr_i2c)) == 0)
	{
		if (!max31725_init())
		{
			dev_badflags |= (1 << dvr_temp);
			PR_ERROR("Temperature sensor initial fail\n");
		}
		else {
			PR_INFO("Temperature sensor initialised\n");
			float temp = max31725_deg_C();
			if (temp < -128.0) {
#if ENABLE_USBDBG
				PR_ERROR("ERROR: max31725_deg_C() = %ld deg\n", (uint32_t)temp); // Tinyprint not support %f
#else
				PR_ERROR("ERROR: max31725_deg_C() = %f deg\n", temp);
#endif
			}
			else {
#if ENABLE_USBDBG
				PR_INFO("max31725_deg_C() = %ld deg_C\n", (uint32_t)temp);
#else
				PR_INFO("max31725_deg_C() = %f deg_C\n", temp);
#endif
			}
		}
	}
	else
	{
		dev_badflags |= (1 << dvr_temp);
		PR_WARN("Temperature sensor is not initialised due to I2C error\n");
	}
#endif

#if ENABLE_ALS
	if ((dev_badflags & (1 << dvr_i2c)) == 0)
	{
		if (!als_init())
		{
			dev_badflags |= (1 << dvr_als);
			PR_WARN("ALS initial fail\n");
		}
		else {
			als_info_t info;
			get_als_info(&info);
			PR_INFO("ALS initialised, manufacturer ID 0x%x, part ID 0x%x\n", info.ManufacturerID, info.PartID);
		}
	}
	else
	{
		dev_badflags |= (1 << dvr_als);
		PR_WARN("ALS is not initialised due to I2C error\n");
	}
#endif

#if ENABLE_MIC
	if (!mic_init())
	{
		dev_badflags |= (1 << dvr_mic);
		PR_WARN("MIC initial fail\n");
	}
	else {
		PR_INFO("MIC initialised\n");
	}
#endif

#if ENABLE_SD
	initSdHost();
	if (!loadSdCard()) {
		dev_badflags |= (1 << dvr_sd);
		PR_WARN("FATFS mount fail\n");
	}
	else {
		PR_INFO("FATFS mounted\n");
	}
#endif /* ENABLE_SD */

#if ENABLE_EVE
	if (!Gpu_Init())
	{
		dev_badflags |= (1 << dvr_eve);
		PR_WARN("EVE initial fail\n");
	}
	else {
		PR_INFO("EVE initialised\n");
		Eve_Calibrate();
	}

#endif /* ENABLE_EVE */
}

#if ENABLE_USBDBG
void tfp_putc(void* p, char c)
{
	(void)(p);
	usbdbg_write_byte(c);
}
#endif

#if (ENABLE_TEMP || ENABLE_ALS)
bool i2c_init(void)
{
	bool ret_val = true;

	if (sys_disable(sys_device_i2c_master) == 0)
	{
		if (sys_enable(sys_device_i2c_master) == 0)
		{
#if ENABLE_TEMP
			/* Set GPIO44 to I2CM_SCL and GPIO45 to I2CM_SDA... */
			gpio_function(TEMP_SENSOR_I2C0_SCL, pad_i2c0_scl);
			gpio_pull(TEMP_SENSOR_I2C0_SCL, pad_pull_none);
			gpio_function(TEMP_SENSOR_I2C0_SDA, pad_i2c0_sda);
			gpio_pull(TEMP_SENSOR_I2C0_SDA, pad_pull_none);
#endif
#if ENABLE_ALS
			gpio_function(ALS_I2C1_SCL, pad_i2c1_scl);
			gpio_pull(ALS_I2C1_SCL, pad_pull_none);
			gpio_function(ALS_I2C1_SDA, pad_i2c1_sda);
			gpio_pull(ALS_I2C1_SDA, pad_pull_none);
#endif

			i2cm_init(I2CM_NORMAL_SPEED, 10000);
				/* Set the I2C Master pins to channel 0 first */
			sys_i2c_swop(0);
		}
		else
			ret_val = false;
	}
	else
		ret_val = false;

	return ret_val;
}
#endif


