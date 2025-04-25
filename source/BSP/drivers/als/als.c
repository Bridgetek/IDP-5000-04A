#include <stdio.h>
#include "bsp_debug.h"
#include "bsp_hwdefs.h"
#include "als.h"

/*Read write registers */
#define REG_ALS_CONTR				0x80
#define REG_ALS_MEAS_RATE  	 		0x85
#define REG_ALS_INTERRUPT 			0x8F
#define REG_ALS_THRES_UP_0 			0x97
#define REG_ALS_THRES_UP_1 			0x98
#define REG_ALS_THRES_LOW_0 		0x99
#define REG_ALS_THRES_LOW_1 		0x9A
#define REG_ALS_INTERRUPT_PERSIST	0x9E
/*Read only registers */
#define REG_PART_ID					0x86
#define REG_MANUFAC_ID				0x87
#define REG_ALS_DATA_CH1_0			0x88
#define REG_ALS_DATA_CH1_1			0x89
#define REG_ALS_DATA_CH0_0			0x8A
#define REG_ALS_DATA_CH0_1			0x8B
#define REG_ALS_STATUS				0x8C

/* Bit Masks */
#define BIT_ALS_GAIN_SETTING			2
#define MASK_ALS_GAIN_SETTING			(0x7 << BIT_ALS_GAIN_SETTING)
#define BIT_ALS_INTEGRATION_TIME		3
#define MASK_ALS_INTEGRATION_TIME		(0x7 << BIT_ALS_INTEGRATION_TIME)

/* PFactor =
 * Factor to compensate light loss due to aperture or window above the device (ALS count without aperture or window / ALS count with aperture)
 */
#define ALS_PFACTOR  1

bool read_als_channels(uint16_t* ch0, uint16_t* ch1)
{
	uint16_t rxWORD = 0;
	bool ret_val = true;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);

	if (i2cm_read(ALS_ADDRESS, REG_ALS_DATA_CH1_0, (uint8_t*)&rxWORD, 2) == 0)
	{
		*ch1 = rxWORD;

		if (i2cm_read(ALS_ADDRESS, REG_ALS_DATA_CH0_0, (uint8_t*)&rxWORD, 2) == 0)
			*ch0 = rxWORD;
		else
			ret_val = false;
	}
	else
		ret_val = false;

	return ret_val;
}

bool get_als_gain(uint8_t* gain)
{
	uint8_t data;
	bool ret_val = true;
	*gain = 1;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);

	if (i2cm_read(ALS_ADDRESS, REG_ALS_CONTR, &data, 1) == 0)
	{
		/* Bit [4..2] - Gain */
		data &= MASK_ALS_GAIN_SETTING;
		data >>= BIT_ALS_GAIN_SETTING;
		switch (data)
		{
		case 0:
			*gain = 1;
			break;
		case 1:
			*gain = 2;
			break;
		case 2:
			*gain = 4;
			break;
		case 3:
			*gain = 8;
			break;
		case 6:
			*gain = 48;
			break;
		case 7:
			*gain = 96;
			break;
		default:
			ret_val = false;
			break;
		}
	}
	else
	{
		ret_val = false;
	}

	return ret_val;
}

bool get_als_integration_time(float* time)
{
	uint8_t data;
	bool ret_val = true;
	*time = 1.0;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);
	if (i2cm_read(ALS_ADDRESS, REG_ALS_MEAS_RATE, &data, 1) == 0)
	{
		/* Bit [5..3] - Integration Time */
		data &= MASK_ALS_INTEGRATION_TIME;
		data >>= BIT_ALS_INTEGRATION_TIME;
		switch (data)
		{
		case 0:
			*time = 1.0;
			break;
		case 1:
			*time = 0.5;
			break;
		case 2:
			*time = 2.0;
			break;
		case 3:
			*time = 4.0;
			break;
		case 4:
			*time = 1.5;
			break;
		case 5:
			*time = 2.5;
			break;
		case 6:
			*time = 3.0;
			break;
		case 7:
			*time = 3.5;
			break;
		default:
			ret_val = false;
			break;
		}
	}
	else
	{
		ret_val = false;
	}

	return ret_val;
}

/**
 *
 *  @brief Initialise the sensor
 *  @return ture - OK, false - fail
 *
 */
bool als_init(void)
{
	uint8_t active_mode = 1;/* bit 0 - mode */
	bool ret_val = true;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);

	if (i2cm_write(ALS_ADDRESS, REG_ALS_CONTR, &active_mode, 1) != 0)
		ret_val = false;

	return ret_val;
}

/**
 *
 *  @brief Read the light sensor info
 *  @param info pointer to read into
 *  @return ture - OK, false - fail
 *
 */
bool get_als_info(als_info_t* info)
{
	uint16_t rxWORD = 0;
	bool ret_val = true;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);
	if (i2cm_read(ALS_ADDRESS, REG_PART_ID, (uint8_t*)&rxWORD, 2) == 0)
	{
		info->PartID = (uint8_t)(rxWORD & 0xFF);
		info->ManufacturerID = (uint8_t)(rxWORD >> 8);
	}
	else
		ret_val = false;

	return ret_val;
}

/**
 *
 *  @brief Read the lux
 *  @param lux pointer to read into
 *  @return ture - OK, false - fail
 *
 */
bool get_als_lux(float* lux)
{
	float ratio;
	uint8_t gain;
	float integration_time;
	uint16_t ch0, ch1;
	bool ret_val = true;
	if (get_als_gain(&gain))
	{
		if (get_als_integration_time(&integration_time))
		{
			if (read_als_channels(&ch0, &ch1))
			{
				ratio = (float)ch1 / (ch0 + ch1);

				if (ratio < 0.45)
					*lux = (1.7743 * ch0 + 1.1059 * ch1) / gain / integration_time / ALS_PFACTOR;
				else if (ratio < 0.64 && ratio >= 0.45)
					*lux = (4.2785 * ch0 - 1.9548 * ch1) / gain / integration_time / ALS_PFACTOR;
				else if (ratio < 0.85 && ratio >= 0.64)
					*lux = (0.5926 * ch0 + 0.1185 * ch1) / gain / integration_time / ALS_PFACTOR;
				else
					*lux = 0;
			}
			else
				ret_val = false;
		}
		else
			ret_val = false;
	}
	else
		ret_val = false;

	return ret_val;
}
