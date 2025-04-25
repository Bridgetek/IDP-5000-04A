#include <stdio.h>
#include "bsp_debug.h"
#include "bsp_hwdefs.h"
#include "rgbled.h"

static RGBPixel_t pixel;
static void led_set(RGBPixel_t* p);

void led_init(void)
{
	gpio_function(RGB_LED_DATA_PIN, pad_gpio57);
	gpio_dir(RGB_LED_DATA_PIN, pad_dir_output);
	gpio_pull(RGB_LED_DATA_PIN, pad_pull_none);
	gpio_write(RGB_LED_DATA_PIN, 0);
	gpio_function(RGB_LED_CLK_PIN, pad_gpio56);
	gpio_dir(RGB_LED_CLK_PIN, pad_dir_output);
	gpio_pull(RGB_LED_CLK_PIN, pad_pull_none);
	gpio_write(RGB_LED_CLK_PIN, 0);
	memset(&pixel, 0, sizeof(pixel));
	led_set(&pixel);

	gpio_dir(RGB_LED_POWER_ENABLE_PIN, pad_dir_output);
	gpio_write(RGB_LED_POWER_ENABLE_PIN, 1);
}

/**
 *	A minimum delay just enough to get the LED to detect the clock and data pulses
 * @param t unused
 */
static	void delay(int t)
{
	asm_noop();
}

// data is sampled on low-to-high transition
static void spi_tx(uint8_t n)
{
	for (uint8_t i = 8; i > 0; i--, n <<= 1)
	{
		if (n & 0x80)
		{
			gpio_write(RGB_LED_DATA_PIN, 1);
		}
		else
		{
			gpio_write(RGB_LED_DATA_PIN, 0);
		}

		delay(1);
		gpio_write(RGB_LED_CLK_PIN, 1);
		delay(1);
		gpio_write(RGB_LED_CLK_PIN, 0);
		delay(1);
	}
}

static void led_set(RGBPixel_t* p)
{
	for (int i = 0; i < 4; i++)
	{
		spi_tx(0x00);    // 4 byte start-frame marker
	}

	spi_tx(p->i | 0xC0);
	spi_tx(p->b);
	spi_tx(p->g);
	spi_tx(p->r);

	for (int i = 0; i < 4; i++)
	{
		spi_tx(0xFF);
	}
}

void led_set_color(uint32_t color, uint8_t intensity)
{
	pixel.r = R(color);
	pixel.g = G(color);
	pixel.b = B(color);
	pixel.i = intensity;
	PR_INFO("R %x, G %x, B %x, i %x\n", pixel.r, pixel.g, pixel.b, pixel.i);

	led_set(&pixel);
}