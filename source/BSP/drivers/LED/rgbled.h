#ifndef _RGBLED_H_
#define _RGBLED_H_

//@{
/** @brief Maximum intensity of brightness */
#define LED_INTENSITY_MAX		31u
/** @brief High intensity of brightness */
#define LED_INTENSITY_HIGH		LED_INTENSITY_MAX
/** @brief Medium intensity of brightness */
#define LED_INTENSITY_MEDIUM	16u
/** @brief Low intensity of brightness */
#define LED_INTENSITY_LOW		8u
/** @brief Zero brightness or OFF condition */
#define LED_INTENSITY_OFF		0u
//@}

#define R(c)	(uint8_t)((c & 0xFF0000) >> 16)
#define G(c)	(uint8_t)((c & 0x00FF00) >> 8)
#define B(c)	(uint8_t)((c & 0x0000FF) >> 0)

// some normal color code
#define LED_RED                    0xFF0000UL
#define LED_ORANGE                 0xFFA500UL
#define LED_YELLOW                 0xFFFF00UL
#define LED_GREEN                  0x00FF00UL
#define LED_BLUE                   0x0000FFUL
#define LED_INDIGO                 0x4B0082UL
#define LED_VIOLET                 0xEE82EEUL

typedef struct {
	uint8_t i; /* Intensity [0 - 31]*/
	uint8_t r;
	uint8_t g;
	uint8_t b;
}RGBPixel_t;

/**
 *
 *  @brief Initialise the RGB LED
 *  @return None
 *
 */
void led_init(void);

/**
 *
 *  @brief Set the LED colour with the given intensity
 *  @param color_name The colour value to set. Friendly names are defined in colornames.h
 *  @param intensity Varies from 0 - 31
 *  @return None
 *
 */
void led_set_color(uint32_t color, uint8_t intensity);

#endif //_RGBLED_H_
