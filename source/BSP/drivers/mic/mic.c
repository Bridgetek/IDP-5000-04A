#include <stdio.h>
#include "bsp_debug.h"
#include "bsp_hwdefs.h"
#include "mic.h"

#define MICROPHONE_BUFFER_SIZE 			8*1024
#define MICROPHONE_HALF_BUFFER_SIZE 	(MICROPHONE_BUFFER_SIZE >> 1)

static uint8_t microphone_data[MICROPHONE_BUFFER_SIZE];
static uint32_t write_index = 0;
static uint32_t read_index = 0;

static void microphone_isr(void)
{
	/* If the FIFO is empty... */
	if (i2s_is_interrupted(MASK_I2S_IE_FIFO_RX_HALF_FULL))
	{
		uint16_t  count = i2s_get_rx_count();
		if (write_index >= MICROPHONE_BUFFER_SIZE)
		{
			write_index = 0;
		}
		i2s_read(microphone_data + write_index, count);
		write_index = write_index + count;
		i2s_clear_int_flag(MASK_I2S_IE_FIFO_RX_HALF_FULL);
#ifdef DUMP_DATA
		{
			uint32_t* arr = (uint32_t*)(microphone_data + write_index);
			int len_avail = count;
			len_avail /= 4;
			for (int i = 0; i < 64; i += 16)
			{
				for (int j = 0; j < 16; j++)
					PR_INFO("%08X ", *(arr + i + j));
				PR_INFO("\n");
			}
			PR_INFO("\n\n");
		}
#endif
	}
}

/**
 *  @brief Initialize the mic
 *  @return ture - OK, false - fail
 */
bool mic_init(void)
{
	bool ret_val = true;

	interrupt_disable_globally();
	if (sys_enable(sys_device_i2s) == 0)
	{
		gpio_function(MIC_I2S_SDAO, pad_i2s_sdao);
		gpio_function(MIC_I2S_SDAI, pad_i2s_sdai);
		gpio_function(MIC_I2S_BCLK, pad_i2s_bclk);
		gpio_function(MIC_I2S_LRCLK, pad_i2s_lrclk);
		gpio_function(MIC_I2S_MCLK, pad_i2s_mclk);
		gpio_function(MIC_CLK24_IN, pad_i2s_clk24);

		i2s_init(i2s_mode_master,
			i2s_length_16,
			i2s_format_i2s,
			i2s_padding_0,
			i2s_master_input_clk_24mhz,
			i2s_bclk_div_16,
			i2s_mclk_div_2,
			i2s_bclk_per_channel_16);

		//Enable CLK24_EN
		gpio_function(MIC_CLK24_EN, pad_gpio65);
		gpio_dir(MIC_CLK24_EN, pad_dir_output);
		gpio_write(MIC_CLK24_EN, 1);

		/* Set up the ISR for the I2S device... */
		i2s_clear_int_flag(0xFFFF);
		i2s_enable_int(MASK_I2S_IE_FIFO_RX_HALF_FULL);
		interrupt_attach(interrupt_i2s, (uint8_t)interrupt_i2s, microphone_isr);
		/* Start streaming audio */
		i2s_start_rx();
		interrupt_enable_globally();

		write_index = 0;
		read_index = 0;
	}
	else
		ret_val = false;

	return ret_val;
}

/**
 *  @brief De-intialize microphone
 *  @return ture - OK, false - fail
 *
 */
bool mic_exit()
{
	bool ret_val = true;

	if (sys_enable(sys_device_i2s) == 0)
	{
		if (interrupt_detach(interrupt_i2s) != 0)
			ret_val = false;
	}
	else
		ret_val = false;

	return ret_val;
}

/**
 *  @brief get available bytes
 *  @return length
 */
uint32_t mic_available()
{
	uint32_t len_avail;
	CRITICAL_SECTION_BEGIN
		len_avail = (write_index >= read_index) ? (write_index - read_index) : (MICROPHONE_BUFFER_SIZE - read_index + write_index);
	CRITICAL_SECTION_END
		PR_INFO("wr:%ld, rd:%ld, len:%ld\n", write_index, read_index, len_avail);
		return len_avail;
}
/**
 *
 *  @brief read out the samples
 *  @param buff to read in
 *  @param len number of bytes to read
 *  @return length
 *
 */
uint32_t mic_read(uint8_t* buff, uint32_t len)
{
	uint32_t residue = 0;
	uint32_t total_len = len;

	if ((len == 0) || (buff == NULL))
	{
		return 0;
	}
	CRITICAL_SECTION_BEGIN
		if (read_index >= MICROPHONE_BUFFER_SIZE)
		{
			read_index = 0;
		}
	if ((read_index + len) >= MICROPHONE_BUFFER_SIZE)
	{
		residue = read_index + len - MICROPHONE_BUFFER_SIZE;
		len -= residue;
	}
	asm_memcpy16((uint16_t*)(microphone_data + read_index), buff, len);
	read_index = read_index + len;
	if (residue)
	{
		asm_memcpy16((uint16_t*)(microphone_data + read_index), (uint16_t*)(buff + len), residue);
		read_index += residue;
	}
	CRITICAL_SECTION_END
		return total_len;
}