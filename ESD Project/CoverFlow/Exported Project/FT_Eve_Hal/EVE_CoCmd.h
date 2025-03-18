/**
 * This source code ("the Software")is provided by Bridgetek Pte Ltd
 * ("Bridgetek")subject to the licence terms set out
 *   http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar)in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 */

#ifndef EVE_CO_CMD__H
#define EVE_CO_CMD__H

#include "EVE_HalDefs.h"
#include "EVE_GpuDefs.h"

/*
Commands are organized as follows:
- System commands
- I/O commands
- Render state commands
- Widget rendering commands
- Complex widget commands
*/

#ifndef ESD_FUNCTION
#define ESD_FUNCTION(name, ...)
#endif
#ifndef ESD_RENDER
#define ESD_RENDER(name, ...)
#endif
#ifndef ESD_PARAMETER
#define ESD_PARAMETER(name, ...)
#endif

/* Change to `eve_pragma_error` to strictly disable use of unsupported commands */
#define EVE_COCMD_UNSUPPORTED(cmd, res) eve_pragma_warning("Coprocessor command " #cmd " is not supported on this platform")(res)

/**********************************************************************
***********************************************************************
**********************************************************************/

/* Reusable templates for basic commands to save on compiled code space */
/* d: uint32_t, w: uint16_t */
/* z: nul-terminated string, z_s: nul-terminated string with known length */
EVE_HAL_EXPORT void EVE_CoCmd_d(EVE_HalContext *phost, uint32_t cmd);
EVE_HAL_EXPORT void EVE_CoCmd_dd(EVE_HalContext *phost, uint32_t cmd, uint32_t d0);
EVE_HAL_EXPORT void EVE_CoCmd_ddd(EVE_HalContext *phost, uint32_t cmd, uint32_t d0, uint32_t d1);
EVE_HAL_EXPORT void EVE_CoCmd_dddd(EVE_HalContext *phost, uint32_t cmd, uint32_t d0, uint32_t d1, uint32_t d2);
EVE_HAL_EXPORT void EVE_CoCmd_ddddd(EVE_HalContext *phost, uint32_t cmd, uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3);
EVE_HAL_EXPORT void EVE_CoCmd_ddww(EVE_HalContext *phost, uint32_t cmd,
    uint32_t d0, uint16_t w1, uint16_t w2);
EVE_HAL_EXPORT void EVE_CoCmd_ddwww(EVE_HalContext *phost, uint32_t cmd,
    uint32_t d0, uint16_t w1, uint16_t w2, uint16_t w3);
EVE_HAL_EXPORT void EVE_CoCmd_dddwwww(EVE_HalContext *phost, uint32_t cmd,
    uint32_t d0, uint32_t d1,
    uint16_t w2, uint16_t w3, uint16_t w4, uint16_t w5);
EVE_HAL_EXPORT void EVE_CoCmd_dwwdd(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint32_t d2, uint32_t d3);
EVE_HAL_EXPORT void EVE_CoCmd_dwwdwwd(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint32_t d2,
    uint16_t w3, uint16_t w4, uint32_t d5);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwdw(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3,
    uint32_t d4, uint16_t w5);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwdww(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3,
    uint32_t d4, uint16_t w5, uint16_t w6);
EVE_HAL_EXPORT void EVE_CoCmd_dwwww(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwww(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3, uint16_t w4);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwd(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3, uint32_t d4);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwwww(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3,
    uint16_t w4, uint16_t w5, uint16_t w6);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwwwww(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3,
    uint16_t w4, uint16_t w5, uint16_t w6, uint16_t w7);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwwwz(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3,
    uint16_t w4, uint16_t w5, const char *s);
EVE_HAL_EXPORT void EVE_CoCmd_dwwwwwwz_s(EVE_HalContext *phost, uint32_t cmd,
    uint16_t w0, uint16_t w1, uint16_t w2, uint16_t w3,
    uint16_t w4, uint16_t w5, const char *s, uint32_t len);

/** Write a display list instruction. Example: EVE_CoCmd_dl(DISPLAY()); */
static inline void EVE_CoCmd_dl(EVE_HalContext *phost, uint32_t dl)
{
	EVE_CoCmd_d(phost, dl);
}

#define EVE_MULTI_TARGET_CHECK(cmd, condition)
#define EVE_MULTI_TARGET_CHECK_RETURN(cmd, condition, res)

EVE_HAL_EXPORT void EVE_CoDlImpl_resetDlState(EVE_HalContext *phost);
EVE_HAL_EXPORT void EVE_CoDlImpl_resetCoState(EVE_HalContext *phost);

#define EVE_CO_SCRATCH_HANDLE (EVE_CHIPID >= EVE_FT810 ? phost->CoScratchHandle : 15)

/**********************************************************************
***********************************************************************
**********************************************************************/

/**
 * @brief Send CMD_DLSTART
 *
 * @param phost
 */
static inline void EVE_CoCmd_dlStart(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_DLSTART);
	EVE_CoDlImpl_resetDlState(phost);
}

/**
 * @brief Send CMD_SWAP
 *
 * @param phost
 */
static inline void EVE_CoCmd_swap(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_SWAP);
}

ESD_FUNCTION(EVE_CoCmd_interrupt, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(ms, Type = int32_t, Default = 0)
/**
 * @brief Send CMD_INTERRUPT
 *
 * @param phost Pointer to Hal context
 * @param ms Delay before interrupt triggers, in milliseconds. The interrupt is guaranteed not to fire before this delay. If ms is zero, the interrupt fires immediately
 */
static inline void EVE_CoCmd_interrupt(EVE_HalContext *phost, uint32_t ms)
{
	EVE_CoCmd_dd(phost, CMD_INTERRUPT, ms);
}

/**
 * @brief Send CMD_COLDSTART
 *
 * @param phost Pointer to Hal context
 */
static inline void EVE_CoCmd_coldStart(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_COLDSTART);
	EVE_CoDlImpl_resetCoState(phost);
}

/**
 * @brief Send CMD_GETMATRIX
 *
 * @param phost Pointer to Hal context
 * @param m output parameters; 6 values; written with matrix coeffcients a, b, c, d, e, f
 */
EVE_HAL_EXPORT bool EVE_CoCmd_getMatrix(EVE_HalContext *phost, int32_t *m);

/**
 * @brief CMD_SETROTATE
 *
 * @param phost Pointer to Hal context
 * @param r new rotation value 0-7
 */
EVE_HAL_EXPORT void EVE_CoCmd_setRotate(EVE_HalContext *phost, uint32_t r);


ESD_FUNCTION(EVE_CoCmd_sync, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
/**
 * @brief Send CMD_SYNC
 *
 * @param phost
 */
static inline void EVE_CoCmd_sync(EVE_HalContext *phost)
{
	EVE_MULTI_TARGET_CHECK(CMD_SYNC, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_d(phost, CMD_SYNC);
}



#define EVE_CoCmd_clearCache(phost) EVE_COCMD_UNSUPPORTED(CMD_CLEARCACHE, false)
#define EVE_CoCmd_nop(phost) EVE_COCMD_UNSUPPORTED(CMD_NOP, false)



#define EVE_CoCmd_hsf(phost, hsf) EVE_COCMD_UNSUPPORTED(CMD_HSF, false)
#define EVE_CoCmd_apiLevel(phost, level) EVE_COCMD_UNSUPPORTED(CMD_APILEVEL, false)
#define EVE_CoCmd_wait(phost, us) EVE_COCMD_UNSUPPORTED(CMD_WAIT, false)
#define EVE_CoCmd_return(phost) EVE_COCMD_UNSUPPORTED(CMD_RETURN, false)
#define EVE_CoCmd_callList(phost, a) EVE_COCMD_UNSUPPORTED(CMD_CALLLIST, false)
#define EVE_CoCmd_newList(phost, a) EVE_COCMD_UNSUPPORTED(CMD_NEWLIST, false)
#define EVE_CoCmd_endList(phost) EVE_COCMD_UNSUPPORTED(CMD_ENDLIST, false)
#define EVE_CoCmd_pclkFreq(phost, ftarget, rounding) EVE_COCMD_UNSUPPORTED(CMD_PCLKFREQ, 0)


/**********************************************************************
***********************************************************************
**********************************************************************/

/**
 * @brief Send CMD_MEMCRC
 *
 * @param phost Pointer to Hal context
 * @param ptr starting address of the memory block
 * @param num number of bytes in the source memory block
 * @param result output parameter; written with the CRC-32 after command execution
 * @return bool Returns false in case of error
 */
EVE_HAL_EXPORT bool EVE_CoCmd_memCrc(EVE_HalContext *phost, uint32_t ptr, uint32_t num, uint32_t *result);

/**
 * @brief Send CMD_REGREAD
 *
 * @param phost Pointer to Hal context
 * @param ptr address of register to read
 * @param result output parameter; written with the register value
 * @return bool Returns false in case of error
 */
EVE_HAL_EXPORT bool EVE_CoCmd_regRead(EVE_HalContext *phost, uint32_t ptr, uint32_t *result);

/**
 * @brief Send CMD_MEMWRITE.
 *
 * You must write the specified number of bytes using one
 * or more of any EVE_Cmd_wr... function call after calling this command,
 * and pad the written data to align at 4 bytes
 *
 * @param phost Pointer to Hal context
 * @param ptr Destination on RAM_G
 * @param num number of bytes to copy
 */
static inline void EVE_CoCmd_memWrite(EVE_HalContext *phost, uint32_t ptr, uint32_t num)
{
	EVE_CoCmd_ddd(phost, CMD_MEMWRITE, ptr, num);
}

/**
 * @brief Send CMD_MEMWRITE, followed by a single 32-bit value.
 *
 * Convenience function to write one 32-bit value through the coprocessor.
 * Useful in combination with EVE_Cmd_waitRead32 to add synchronization points into the command buffer.
 *
 * @param phost Pointer to Hal context
 * @param ptr Destination on RAM_G
 * @param value Value to write
 */
static inline void EVE_CoCmd_memWrite32(EVE_HalContext *phost, uint32_t ptr, uint32_t value)
{
	EVE_CoCmd_dddd(phost, CMD_MEMWRITE, ptr, 4, value);
}

ESD_FUNCTION(EVE_CoCmd_memSet, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(ptr, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
ESD_PARAMETER(value, Type = uint32_t, Default = 0)
ESD_PARAMETER(num, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
/**
 * @brief Send CMD_MEMSET
 *
 * @param phost Pointer to Hal context
 * @param ptr starting address of the memory block
 * @param value value to be written to memory
 * @param num number of bytes in the memory block
 */
static inline void EVE_CoCmd_memSet(EVE_HalContext *phost, uint32_t ptr, uint32_t value, uint32_t num)
{
	EVE_CoCmd_dddd(phost, CMD_MEMSET, ptr, value, num);
}

ESD_FUNCTION(EVE_CoCmd_memZero, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(ptr, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
ESD_PARAMETER(num, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
/**
 * @brief Send CMD_MEMZERO
 *
 * @param phost Pointer to Hal context
 * @param ptr Destination on RAM_G
 * @param num number of bytes to clear
 */
static inline void EVE_CoCmd_memZero(EVE_HalContext *phost, uint32_t ptr, uint32_t num)
{
	EVE_CoCmd_ddd(phost, CMD_MEMZERO, ptr, num);
}

ESD_FUNCTION(EVE_CoCmd_memCpy, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(dest, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
ESD_PARAMETER(src, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
ESD_PARAMETER(num, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
/**
 * @brief Send CMD_MEMCPY
 *
 * @param phost Pointer to Hal context
 * @param dest address of the destination memory block
 * @param src address of the source memory block
 * @param num number of bytes to copy
 */
static inline void EVE_CoCmd_memCpy(EVE_HalContext *phost, uint32_t dest, uint32_t src, uint32_t num)
{
	EVE_CoCmd_dddd(phost, CMD_MEMCPY, dest, src, num);
}

ESD_FUNCTION(EVE_CoCmd_append, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(ptr, Type = uint32_t, Default = 0) // MEMORY_ADDRESS
ESD_PARAMETER(num, Type = uint32_t, Default = 0, Min = 0, Max = 2048)
/**
 * @brief Send CMD_APPEND
 *
 * @param phost  Pointer to Hal context
 * @param ptr Start of source commands in main memory
 * @param num Number of bytes to copy. This must be a multiple of 4
 */
static inline void EVE_CoCmd_append(EVE_HalContext *phost, uint32_t ptr, uint32_t num)
{
	EVE_CoCmd_ddd(phost, CMD_APPEND, ptr, num);
}

/**
 * @brief Send CMD_SNAPSHOT
 *
 * @param phost Pointer to Hal context
 * @param ptr Snapshot destination address, in RAM_G
 */
static inline void EVE_CoCmd_snapshot(EVE_HalContext *phost, uint32_t ptr)
{
	EVE_CoCmd_dd(phost, CMD_SNAPSHOT, ptr);
}

/**
 * @brief Send CMD_INFLATE. Data must follow this command
 *
 * @param phost Pointer to Hal context
 * @param ptr Destination address
 */
static inline void EVE_CoCmd_inflate(EVE_HalContext *phost, uint32_t ptr)
{
	EVE_CoCmd_dd(phost, CMD_INFLATE, ptr);
}

/**
 * @brief Inflates data from program memory to RAM_G
 *
 * @param phost Pointer to Hal context
 * @param dst Image address
 * @param src Desination on RAM_G
 * @param size size of `src` in bytes
 * @return Returns false on coprocessor fault
 */
EVE_HAL_EXPORT bool EVE_CoCmd_inflate_progMem(EVE_HalContext *phost, uint32_t dst, eve_progmem_const uint8_t *src, uint32_t size);

/**
 * @brief Get the end memory address of data inflated by CMD_INFLATE
 *
 * @param phost Pointer to Hal context
 * @param result memory address
 */
EVE_HAL_EXPORT bool EVE_CoCmd_getPtr(EVE_HalContext *phost, uint32_t *result);

/**
 * @brief Send CMD_LOADIMAGE. Data must follow this command
 *
 * @param phost Pointer to Hal context
 * @param ptr Destination address
 * @param options Command option
 */
static inline void EVE_CoCmd_loadImage(EVE_HalContext *phost, uint32_t ptr, uint32_t options)
{
	EVE_CoCmd_ddd(phost, CMD_LOADIMAGE, ptr, options);
}

/**
 * @brief Load image from program memory
 *
 * @param phost Pointer to Hal context
 * @param dst Image address
 * @param src Desination on RAM_G
 * @param size size of `src` in bytes
 * @param format Output parameter format returns loaded bitmap format on success
 * @return bool Returns false on coprocessor fault
 */
EVE_HAL_EXPORT bool EVE_CoCmd_loadImage_progMem(EVE_HalContext *phost, uint32_t dst, eve_progmem_const uint8_t *src, uint32_t size, uint32_t *format);

/**
 * @brief Get the image properties decompressed by CMD_LOADIMAGE
 *
 * @param phost Pointer to Hal context
 * @param ptr Source address of bitmap
 * @param w Width of bitmap, in pixels
 * @param h Height of bitmap, in pixels
 */
EVE_HAL_EXPORT bool EVE_CoCmd_getProps(EVE_HalContext *phost, uint32_t *ptr, uint32_t *w, uint32_t *h);


/**
 * @brief Send CMD_SNAPSHOT2
 *
 * @param phost Pointer to Hal context
 * @param fmt Output bitmap format, one of RGB565, ARGB4 or 0x20
 * @param ptr Snapshot destination address, in RAM_G
 * @param x x-coordinate of snapshot area top-left, in pixels
 * @param y y-coordinate of snapshot area top-left, in pixels
 * @param w width of snapshot area, in pixels
 * @param h height of snapshot area, in pixels
 */
static inline void EVE_CoCmd_snapshot2(EVE_HalContext *phost, uint32_t fmt, uint32_t ptr, int16_t x, int16_t y, int16_t w, int16_t h)
{
	EVE_MULTI_TARGET_CHECK(CMD_SNAPSHOT2, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_dddwwww(phost, CMD_SNAPSHOT2, fmt, ptr, x, y, w, h);
}

/**
 * @brief Send CMD_MEDIAFIFO. See EVE_MediaFifo interface for easier FIFO access
 *
 * @param phost Pointer to Hal context
 * @param ptr starting address of the memory block, 4-byte aligned
 * @param size number of bytes in the source memory block, 4-byte aligned
 */
static inline void EVE_CoCmd_mediaFifo(EVE_HalContext *phost, uint32_t ptr, uint32_t size)
{
	EVE_MULTI_TARGET_CHECK(CMD_MEDIAFIFO, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_ddd(phost, CMD_MEDIAFIFO, ptr, size);
}

/**
 * @brief Send CMD_VIDEOSTART
 *
 * @param phost
 */
static inline void EVE_CoCmd_videoStart(EVE_HalContext *phost)
{
	EVE_MULTI_TARGET_CHECK(CMD_VIDEOSTART, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_d(phost, CMD_VIDEOSTART);
}

/**
 * @brief CMD_VIDEOFRAME
 *
 * @param phost Pointer to Hal context
 * @param dst Main memory location to load the frame data
 * @param ptr Completion pointer
 */
static inline void EVE_CoCmd_videoFrame(EVE_HalContext *phost, uint32_t dst, uint32_t ptr)
{
	EVE_MULTI_TARGET_CHECK(CMD_VIDEOFRAME, EVE_CHIPID >= EVE_FT810);
	if (EVE_CHIPID == EVE_BT815 || EVE_CHIPID == EVE_BT816)
		EVE_CoCmd_dddd(phost, CMD_MEMWRITE, 3182934, 1, OPT_NODL); // WORKAROUND CMD_VIDEOFRAME
	else if (EVE_CHIPID == EVE_BT817 || EVE_CHIPID == EVE_BT818)
		EVE_CoCmd_dddd(phost, CMD_MEMWRITE, 3182920, 1, OPT_NODL); // WORKAROUND CMD_VIDEOFRAME
	EVE_CoCmd_ddd(phost, CMD_VIDEOFRAME, dst, ptr);
}


#define FLASH_ERROR_NOTATTACHED 0xE001
#define FLASH_ERROR_HEADERMISSING 0xE002
#define FLASH_ERROR_HEADERCRCFAILED 0xE003
#define FLASH_ERROR_FIRMWAREMISMATCH 0xE004
#define FLASH_ERROR_FULLSPEEDFAILED 0xE005


#define EVE_CoCmd_flashErase(phost) EVE_COCMD_UNSUPPORTED(CMD_FLASHERASE, false)
#define EVE_CoCmd_flashErase_flush(phost) EVE_COCMD_UNSUPPORTED(CMD_FLASHERASE, false)
#define EVE_CoCmd_flashWrite(phost, ptr, num) EVE_COCMD_UNSUPPORTED(CMD_FLASHWRITE, false)
#define EVE_CoCmd_flashRead(phost, dest, src, num) EVE_COCMD_UNSUPPORTED(CMD_FLASHREAD, false)
#define EVE_CoCmd_flashRead_flush(phost, dest, src, num) EVE_COCMD_UNSUPPORTED(CMD_FLASHREAD, false)
#define EVE_CoCmd_flashUpdate(phost, dest, src, num) EVE_COCMD_UNSUPPORTED(CMD_FLASHUPDATE, false)
#define EVE_CoCmd_flashDetach(phost) EVE_COCMD_UNSUPPORTED(CMD_FLASHDETACH, false)
#define EVE_CoCmd_flashAttach(phost) EVE_COCMD_UNSUPPORTED(CMD_FLASHATTACH, 0)
#define EVE_CoCmd_flashFast(phost, result) EVE_COCMD_UNSUPPORTED(CMD_FLASHFAST, 0)
#define EVE_CoCmd_flashSpiDesel(phost) EVE_COCMD_UNSUPPORTED(CMD_FLASHSPIDESEL, false)
#define EVE_CoCmd_flashSpiTx(phost, num) EVE_COCMD_UNSUPPORTED(CMD_FLASHSPITX, false)
#define EVE_CoCmd_flashSpiRx(phost, ptr, num) EVE_COCMD_UNSUPPORTED(CMD_FLASHSPIRX, false)
#define EVE_CoCmd_flashSource(phost, ptr) EVE_COCMD_UNSUPPORTED(CMD_FLASHSOURCE, false)
#define EVE_CoCmd_appendF(phost, ptr, num) EVE_COCMD_UNSUPPORTED(CMD_APPENDF, false)
#define EVE_CoCmd_videoStartF(phost) EVE_COCMD_UNSUPPORTED(CMD_VIDEOSTARTF, false)
#define EVE_CoCmd_loadImage_flash(phost, dst, src, format) EVE_COCMD_UNSUPPORTED(CMD_FLASHSOURCE, false)
#define EVE_CoCmd_inflate_flash(phost, dst, src, format) EVE_COCMD_UNSUPPORTED(CMD_FLASHSOURCE, false)



#define EVE_CoCmd_inflate2(phost, ptr, options) EVE_COCMD_UNSUPPORTED(CMD_INFLATE2, false)



#define EVE_CoCmd_getImage(phost, source, fmt, w, h, palette) EVE_COCMD_UNSUPPORTED(CMD_GETIMAGE, false)
#define EVE_CoCmd_fontCache(phost, font, ptr, num) EVE_COCMD_UNSUPPORTED(CMD_FONTCACHE, false)
#define EVE_CoCmd_fontCacheQuery(phost, total, used) EVE_COCMD_UNSUPPORTED(CMD_FONTCACHEQUERY, false)


/**********************************************************************
***********************************************************************
**********************************************************************/

ESD_FUNCTION(EVE_CoCmd_bgColor, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(c, Type = esd_rgb32_t, Default = 0) // COLOR
/**
 * @brief Send CMD_BGCOLOR
 *
 * @param phost Pointer to Hal context
 * @param c New background color
 */
static inline void EVE_CoCmd_bgColor(EVE_HalContext *phost, uint32_t c)
{
#if EVE_DL_OPTIMIZE
	if (phost->CoBgColor != c)
	{
#endif
		EVE_CoCmd_dd(phost, CMD_BGCOLOR, c);
#if EVE_DL_OPTIMIZE
		phost->CoBgColor = c;
	}
#endif
}

ESD_FUNCTION(EVE_CoCmd_fgColor, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(c, Type = esd_rgb32_t, Default = 0) // COLOR
/**
 * @brief Send CMD_FGCOLOR
 *
 * @param phost Pointer to Hal context
 * @param c New foreground color, as a 24-bit RGB number
 */
static inline void EVE_CoCmd_fgColor(EVE_HalContext *phost, uint32_t c)
{
#if EVE_DL_OPTIMIZE
	if (phost->CoFgColor != c)
	{
#endif
		EVE_CoCmd_dd(phost, CMD_FGCOLOR, c);
#if EVE_DL_OPTIMIZE
		phost->CoFgColor = c;
	}
#endif
}

/**
 * @brief Send CMD_BITMAP_TRANSFORM. Blocking call if a pointer is passed to `result`
 *
 * @param phost Pointer to Hal context
 * @param x0 Point X0 screen coordinate, in pixels
 * @param y0 Point Y0 screen coordinate, in pixels
 * @param x1 Point X1 screen coordinate, in pixels
 * @param y1 Point Y1 screen coordinate, in pixels
 * @param x2 Point X2 screen coordinate, in pixels
 * @param y2 Point Y2 screen coordinate, in pixels
 * @param tx0 Point X0 bitmap coordinate, in pixels
 * @param ty0 Point Y0 bitmap coordinate, in pixels
 * @param tx1 Point X1 bitmap coordinate, in pixels
 * @param ty1 Point Y1 bitmap coordinate, in pixels
 * @param tx2 Point X2 bitmap coordinate, in pixels
 * @param ty2 Point Y2 bitmap coordinate, in pixels
 * @param result Optional parameter `result` is set to -1 on success, 0 on failure
 * @return bool Returns false on coprocessor error
 */
EVE_HAL_EXPORT bool EVE_CoCmd_bitmapTransform(EVE_HalContext *phost, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t tx0, int32_t ty0, int32_t tx1, int32_t ty1, int32_t tx2, int32_t ty2, uint16_t *result);

ESD_FUNCTION(EVE_CoCmd_loadIdentity, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
/**
 * @brief Send CMD_LOADIDENTITY
 *
 * @param phost Pointer to Hal context
 */
static inline void EVE_CoCmd_loadIdentity(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_LOADIDENTITY);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = false; /* Identity */
#endif
}

ESD_FUNCTION(EVE_CoCmd_translate, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(tx, Type = int32_t, Default = 0)
ESD_PARAMETER(ty, Type = int32_t, Default = 0)
/**
 * @brief Send CMD_TRANSLATE
 *
 * @param phost Pointer to Hal context
 * @param tx x scale factor, in signed 16.16 bit fixed-point form.
 * @param ty y scale factor, in signed 16.16 bit fixed-point form.
 */
static inline void EVE_CoCmd_translate(EVE_HalContext *phost, int32_t tx, int32_t ty)
{
	EVE_CoCmd_ddd(phost, CMD_TRANSLATE, tx, ty);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = true;
#endif
}

ESD_FUNCTION(EVE_CoCmd_scale, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(sx, Type = int32_t, Default = 0)
ESD_PARAMETER(sy, Type = int32_t, Default = 0)
/**
 * @brief Send CMD_SCALE
 *
 * @param phost Pointer to Hal context
 * @param sx x scale factor, in signed 16.16 bit fixed-point form
 * @param sy y scale factor, in signed 16.16 bit fixed-point form
 */
static inline void EVE_CoCmd_scale(EVE_HalContext *phost, int32_t sx, int32_t sy)
{
	EVE_CoCmd_ddd(phost, CMD_SCALE, sx, sy);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = true;
#endif
}

ESD_FUNCTION(EVE_CoCmd_rotate, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(a, Type = int32_t, Default = 0)
/**
 * @brief Send CMD_ROTATE
 *
 * @param phost Pointer to Hal context
 * @param a clockwise rotation angle, in units of 1/65536 of a circle
 */
static inline void EVE_CoCmd_rotate(EVE_HalContext *phost, int32_t a)
{
	EVE_CoCmd_dd(phost, CMD_ROTATE, a);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = true;
#endif
}

ESD_FUNCTION(EVE_CoCmd_setMatrix, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
/**
 * @brief Send CMD_SETMATRIX
 *
 * @param phost
 */
static inline void EVE_CoCmd_setMatrix(EVE_HalContext *phost)
{
#if EVE_DL_OPTIMIZE
	if (phost->CoBitmapTransform || EVE_DL_STATE.BitmapTransform)
	{
		/* Setting matrix can be skipped if both are identity, since it's a no-op */
#endif
		EVE_CoCmd_d(phost, CMD_SETMATRIX);
#if EVE_DL_OPTIMIZE
		EVE_DL_STATE.BitmapTransform = phost->CoBitmapTransform; /* Coprocessor matrix is now written to the display list */
	}
#endif
}

/**
 * @brief Send CMD_SETFONT
 *
 * @param phost Pointer to Hal context
 * @param font bitmap handle number, 0-31
 * @param ptr pointer to font description block
 */
static inline void EVE_CoCmd_setFont(EVE_HalContext *phost, uint32_t font, uint32_t ptr)
{
	EVE_CoCmd_ddd(phost, CMD_SETFONT, font, ptr);
}

ESD_FUNCTION(EVE_CoCmd_gradColor, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(c, Type = esd_rgb32_t, Default = 0) // COLOR
/**
 * @brief Send CMD_GRADCOLOR
 *
 * @param phost Pointer to Hal context
 * @param c New highlight gradient color, as a 24-bit RGB number
 */
static inline void EVE_CoCmd_gradColor(EVE_HalContext *phost, uint32_t c)
{
	EVE_CoCmd_dd(phost, CMD_GRADCOLOR, c);
}


ESD_FUNCTION(EVE_CoCmd_setBase, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(base, Type = int32_t, Default = 0)
/**
 * @brief Send CMD_SETBASE
 *
 * @param phost Pointer to Hal context
 * @param base Numeric base, from 2 to 36
 */
static inline void EVE_CoCmd_setBase(EVE_HalContext *phost, uint32_t base)
{
	EVE_MULTI_TARGET_CHECK(CMD_SETBASE, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_dd(phost, CMD_SETBASE, base);
}

/**
 * @brief Send CMD_SETFONT2
 *
 * @param phost Pointer to Hal context
 * @param font bitmap handle number, 0-31
 * @param ptr pointer to font description block
 * @param firstchar first character in the font. For an extended font block, this should be zero
 */
static inline void EVE_CoCmd_setFont2(EVE_HalContext *phost, uint32_t font, uint32_t ptr, uint32_t firstchar)
{
	EVE_MULTI_TARGET_CHECK(CMD_SETFONT2, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_dddd(phost, CMD_SETFONT2, font, ptr, firstchar);
#if EVE_DL_OPTIMIZE
	EVE_DL_STATE.Handle = (uint8_t)font;
#endif
}

/**
 * @brief Send CMD_SETSCRATCH
 *
 * @param phost Pointer to Hal context
 * @param handle bitmap handle number, 0-31
 */
static inline void EVE_CoCmd_setScratch(EVE_HalContext *phost, uint32_t handle)
{
	EVE_MULTI_TARGET_CHECK(CMD_SETSCRATCH, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_dd(phost, CMD_SETSCRATCH, handle);
	phost->CoScratchHandle = (uint8_t)handle;
}

/**
 * @brief Send CMD_ROMFONT
 *
 * @param phost Pointer to Hal context
 * @param font Font number
 * @param romslot Slot number
 */
static inline void EVE_CoCmd_romFont(EVE_HalContext *phost, uint32_t font, uint32_t romslot)
{
	EVE_MULTI_TARGET_CHECK(CMD_ROMFONT, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_ddd(phost, CMD_ROMFONT, font, romslot);
#if EVE_DL_OPTIMIZE
	EVE_DL_STATE.Handle = (uint8_t)font;
#endif
}

/**
 * @brief Send CMD_SETBITMAP
 *
 * @param phost Pointer to Hal context
 * @param source Source address for bitmap, in RAM or ï¬‚ash, as a BITMAP SOURCEargument
 * @param fmt Bitmap format
 * @param w Bitmap screen width in pixels
 * @param h Bitmap screen height in pixels
 */
static inline void EVE_CoCmd_setBitmap(EVE_HalContext *phost, uint32_t source, uint16_t fmt, uint16_t w, uint16_t h)
{
	EVE_MULTI_TARGET_CHECK(CMD_SETBITMAP, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_ddwww(phost, CMD_SETBITMAP, source, fmt, w, h);
}



#define EVE_CoCmd_rotateAround(phost, x, y, a, s) EVE_COCMD_UNSUPPORTED(CMD_ROTATEAROUND, false)
#define EVE_CoCmd_resetFonts(phost) EVE_COCMD_UNSUPPORTED(CMD_RESETFONTS, false)
#define EVE_CoCmd_fillWidth(phost, s) EVE_COCMD_UNSUPPORTED(CMD_FILLWIDTH, false)


/**********************************************************************
***********************************************************************
**********************************************************************/

ESD_FUNCTION(EVE_CoCmd_gradient, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x0, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y0, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(rgb0, Type = esd_rgb32_t, Default = 0) // COLOR
ESD_PARAMETER(x1, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y1, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(rgb1, Type = esd_rgb32_t, Default = 0) // COLOR
/**
 * @brief Send CMD_GRADIENT
 *
 * @param phost Pointer to Hal context
 * @param x0 x-coordinate of point 0, in pixels
 * @param y0 y-coordinate of point 0, in pixels
 * @param rgb0 Color of point 0, as a 24-bit RGB number
 * @param x1 x-coordinate of point 1, in pixels
 * @param y1 y-coordinate of point 1, in pixels
 * @param rgb1 Color of point 1
 */
static inline void EVE_CoCmd_gradient(EVE_HalContext *phost, int16_t x0, int16_t y0, uint32_t rgb0, int16_t x1, int16_t y1, uint32_t rgb1)
{
	EVE_CoCmd_dwwdwwd(phost, CMD_GRADIENT, x0, y0, rgb0, x1, y1, rgb1);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

/**
 * @brief Send CMD_TEXT
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of text base, in pixels
 * @param y y-coordinate of text base, in pixels
 * @param font Font to use for text, 0-31
 * @param options Text option
 * @param s Text string, UTF-8 encoding
 * @param ... Text format
 */
EVE_HAL_EXPORT void EVE_CoCmd_text(EVE_HalContext *phost, int16_t x, int16_t y, int16_t font, uint16_t options, const char *s, ...);

/**
 * @brief Send CMD_TEXT with length
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of text base, in pixels
 * @param y y-coordinate of text base, in pixels
 * @param font Font to use for text, 0-31
 * @param options Text option
 * @param s Text string, UTF-8 encoding
 * @param length length of text
 */
EVE_HAL_EXPORT void EVE_CoCmd_text_s(EVE_HalContext *phost, int16_t x, int16_t y, int16_t font, uint16_t options, const char *s, uint32_t length);

ESD_RENDER(EVE_CoCmd_text_ex, Type = void, Category = _GroupHidden, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(font, Type = int16_t, Default = 21, Min = 0, Max = 31) // BITMAP_HANDLE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(bottom, Type = bool, Default = 0)
ESD_PARAMETER(baseLine, Type = int16_t, Default = 0)
ESD_PARAMETER(capsHeight, Type = int16_t, Default = 0)
ESD_PARAMETER(xOffset, Type = int16_t, Default = 0)
ESD_PARAMETER(s, Type = const char *, Default = "Text")
/**
 * @brief Send CMD_TEXT
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of text base, in pixels
 * @param y y-coordinate of text base, in pixels
 * @param font Font to use for text, 0-31
 * @param options Text option
 * @param bottom
 * @param baseLine
 * @param capsHeight
 * @param s Text string, UTF-8 encoding
 */
EVE_HAL_EXPORT void EVE_CoCmd_text_ex(EVE_HalContext *phost, int16_t x, int16_t y, int16_t font, uint16_t options, bool bottom, int16_t baseLine, int16_t capsHeight, int16_t xOffset, const char *s);

/**
 * @brief Send CMD_BUTTON
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of button top-left, in pixels
 * @param y y-coordinate of button top-left, in pixels
 * @param w Button width
 * @param h Button height
 * @param font font to use for text, 0-31
 * @param options Font option
 * @param s Button label text, UTF-8 encoding
 * @param ... Format of button label text, like printf
 */
EVE_HAL_EXPORT void EVE_CoCmd_button(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t h, int16_t font, uint16_t options, const char *s, ...);

ESD_RENDER(EVE_CoCmd_keys, Type = void, Category = _GroupHidden, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(width, Type = int16_t, Default = 60) // SCREEN_SIZE
ESD_PARAMETER(height, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(font, Type = int16_t, Default = 21, Min = 0, Max = 31) // BITMAP_HANDLE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(s, Type = const char *, Default = "Button")
/**
 * @brief Send CMD_KEYS
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of keys top-left, in pixels
 * @param y y-coordinate of keys top-left, in pixels
 * @param w Keys width
 * @param h Keys height
 * @param font Font for keys label
 * @param options Drawing option
 * @param s key labels, one character per key
 */
EVE_HAL_EXPORT void EVE_CoCmd_keys(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t h, int16_t font, uint16_t options, const char *s);

ESD_RENDER(EVE_CoCmd_progress, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(width, Type = int16_t, Default = 60) // SCREEN_SIZE
ESD_PARAMETER(height, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(val, Type = uint16_t, Default = 0)
ESD_PARAMETER(range, Type = uint16_t, Default = 0)
/**
 * @brief Send CMD_PROGRESS
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of progress bar top-left, in pixels
 * @param y y-coordinate of progress bar top-left, in pixels
 * @param w width of progress bar, in pixels
 * @param h height of progress bar, in pixels
 * @param options Drawing option
 * @param val Displayed value of progresss bar, between 0 and range inclusive
 * @param range Maximum value
 */
static inline void EVE_CoCmd_progress(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t range)
{
	EVE_CoCmd_dwwwwwww(phost, CMD_PROGRESS, x, y, w, h, options, val, range);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

ESD_RENDER(EVE_CoCmd_slider, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(width, Type = int16_t, Default = 60) // SCREEN_SIZE
ESD_PARAMETER(height, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(val, Type = uint16_t, Default = 0)
ESD_PARAMETER(range, Type = uint16_t, Default = 0)
/**
 * @brief Send CMD_SLIDER
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of slider top-left, in pixels
 * @param y y-coordinate of slider top-left, in pixels
 * @param w width of slider, in pixels
 * @param h height of slider, in pixels
 * @param options By default the slider is drawn with a 3D effect. OPT_FLAT removes the 3D effect
 * @param val Displayed value of slider, between 0 and range inclusive
 * @param range Maximum value
 */
static inline void EVE_CoCmd_slider(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t range)
{
	EVE_CoCmd_dwwwwwww(phost, CMD_SLIDER, x, y, w, h, options, val, range);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

ESD_RENDER(EVE_CoCmd_scrollbar, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(width, Type = int16_t, Default = 60) // SCREEN_SIZE
ESD_PARAMETER(height, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(val, Type = uint16_t, Default = 0)
ESD_PARAMETER(size, Type = uint16_t, Default = 0)
ESD_PARAMETER(range, Type = uint16_t, Default = 0)
/**
 * @brief Send CMD_SCROLLBAR
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of scroll bar top-left, in pixels
 * @param y y-coordinate of scroll bar top-left, in pixels
 * @param w width of scroll bar, in pixels. If width is greater, the scroll bar is drawn horizontally
 * @param h height of scroll bar, in pixels. If height is greater, the scroll bar is drawn vertically
 * @param options By default the scroll bar is drawn with a 3D eï¬€ect. OPT FLAT removes the 3D eï¬€ect
 * @param val Displayed value of scroll bar, between 0 and range inclusive
 * @param size Scrol bar size
 * @param range Maximum value
 */
static inline void EVE_CoCmd_scrollbar(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t size, uint16_t range)
{
	EVE_CoCmd_dwwwwwwww(phost, CMD_SCROLLBAR, x, y, w, h, options, val, size, range);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

/**
 * @brief Send CMD_TOGGLE
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of top-left of toggle, in pixels
 * @param y y-coordinate of top-left of toggle, in pixels
 * @param w width of toggle, in pixels
 * @param font font to use for text, 0-31
 * @param options Drawing option
 * @param state state of the toggle: 0 is off, 65535 is on.
 * @param s string labels for toggle,UTF-8 encoding
 * @param ... string labels format
 */
EVE_HAL_EXPORT void EVE_CoCmd_toggle(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t font, uint16_t options, uint16_t state, const char *s, ...);

ESD_RENDER(EVE_CoCmd_gauge, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(r, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(major, Type = uint16_t, Default = 0)
ESD_PARAMETER(minor, Type = uint16_t, Default = 0)
ESD_PARAMETER(val, Type = uint16_t, Default = 0)
ESD_PARAMETER(range, Type = uint16_t, Default = 0)
/**
 * @brief Send CMD_GAUGE
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of gauge center, in pixels
 * @param y y-coordinate of gauge center, in pixels
 * @param r radius of the gauge, in pixels
 * @param options Drawing option
 * @param major Number of major subdivisions on the dial, 1-10
 * @param minor Number of minor subdivisions on the dial, 1-10
 * @param val gauge indicated value, between 0 and range, inclusive
 * @param range maximum value
 */
static inline void EVE_CoCmd_gauge(EVE_HalContext *phost, int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t major, uint16_t minor, uint16_t val, uint16_t range)
{
	EVE_CoCmd_dwwwwwwww(phost, CMD_GAUGE, x, y, r, options, major, minor, val, range);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

ESD_RENDER(EVE_CoCmd_clock, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(r, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(height, Type = uint16_t, Default = 0)
ESD_PARAMETER(m, Type = uint16_t, Default = 0)
ESD_PARAMETER(s, Type = uint16_t, Default = 0)
ESD_PARAMETER(ms, Type = uint16_t, Default = 0)
/**
 * @brief Send CMD_CLOCK
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of clock center, in pixels
 * @param y y-coordinate of clock center, in pixels
 * @param r Clock radius
 * @param options Drawing option
 * @param h hours
 * @param m minutes
 * @param s seconds
 * @param ms milliseconds
 */
static inline void EVE_CoCmd_clock(EVE_HalContext *phost, int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t h, uint16_t m, uint16_t s, uint16_t ms)
{
	EVE_CoCmd_dwwwwwwww(phost, CMD_CLOCK, x, y, r, options, h, m, s, ms);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

ESD_RENDER(EVE_CoCmd_dial, Type = void, Category = _GroupHidden, Inline, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(r, Type = int16_t, Default = 40) // SCREEN_SIZE
ESD_PARAMETER(options, Type = Ft_CoPro_Opt, Default = 0)
ESD_PARAMETER(val, Type = uint16_t, Default = 0)
/**
 * @brief Send CMD_DIAL
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of dial center, in pixels
 * @param y y-coordinate of dial center, in pixels
 * @param r radius of dial, in pixels.
 * @param options Drawing option
 * @param val Specify the position of dial points by setting value between 0 and 65535 inclusive. 0 means that the dial points straight down, 0x4000 left, 0x8000 up, and0xc000 right.
 */
static inline void EVE_CoCmd_dial(EVE_HalContext *phost, int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t val)
{
	EVE_CoCmd_dwwwww(phost, CMD_DIAL, x, y, r, options, val);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

ESD_RENDER(EVE_CoCmd_number, Type = void, Category = _GroupHidden, Include = "Esd_Core.h")
ESD_PARAMETER(phost, Type = EVE_HalContext *, Default = Esd_GetHost, Hidden, Internal, Static) // PHOST
ESD_PARAMETER(x, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(y, Type = int16_t, Default = 0) // SCREEN_SIZE
ESD_PARAMETER(font, Type = int16_t, Default = 21, Min = 16, Max = 34) // BITMAP_HANDLE
ESD_PARAMETER(options, Type = uint16_t, Default = 256)
ESD_PARAMETER(n, Type = int32_t, Default = 0)
/**
 * @brief Send CMD_NUMBER
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of text base, in pixels
 * @param y y-coordinate of text base, in pixels
 * @param font font to use for text, 0-31
 * @param options Drawing option
 * @param n The number to display, either unsigned or signed 32-bit
 */
EVE_HAL_EXPORT void EVE_CoCmd_number(EVE_HalContext *phost, int16_t x, int16_t y, int16_t font, uint16_t options, int32_t n);


#define EVE_CoCmd_gradientA(phost, x0, y0, argb0, x1, y1, argb1) EVE_COCMD_UNSUPPORTED(CMD_GRADIENTA, false)


/**********************************************************************
***********************************************************************
**********************************************************************/

/**
 * @brief Send CMD_CALIBRATE
 *
 * @param phost
 * @return uint32_t
 */
EVE_HAL_EXPORT uint32_t EVE_CoCmd_calibrate(EVE_HalContext *phost);

/**
 * @brief Send CMD_SPINNER
 *
 * @param phost Pointer to Hal context
 * @param x The X coordinate of top left of spinner
 * @param y The Y coordinate of top left of spinner
 * @param style The style of spinner. Valid range is from 0 to 3
 * @param scale The scaling coefficient of spinner. 0 means no scaling
 */
static inline void EVE_CoCmd_spinner(EVE_HalContext *phost, int16_t x, int16_t y, uint16_t style, uint16_t scale)
{
	EVE_CoCmd_dwwww(phost, CMD_SPINNER, x, y, style, scale);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

/**
 * @brief Send CMD_STOP
 *
 * @param phost
 */
static inline void EVE_CoCmd_stop(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_STOP);
}

/**
 * @brief Send CMD_TRACK
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of track area top-left, in pixels
 * @param y y-coordinate of track area top-left, in pixels
 * @param w width of track area, in pixels
 * @param h height of track area, in pixels
 * @param tag tag for this track, 1-255
 */
static inline void EVE_CoCmd_track(EVE_HalContext *phost, int16_t x, int16_t y, int16_t w, int16_t h, int16_t tag)
{
	EVE_CoCmd_dwwwww(phost, CMD_TRACK, x, y, w, h, tag);
}

/**
 * @brief Send CMD_SCREENSAVER
 *
 * @param phost
 */
static inline void EVE_CoCmd_screenSaver(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_SCREENSAVER);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

/**
 * @brief Send CMD_SKETCH
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of sketch area top-left, in pixels
 * @param y y-coordinate of sketch area top-left, in pixels
 * @param w Width of sketch area, in pixels
 * @param h Height of sketch area, in pixels
 * @param ptr Base address of sketch bitmap
 * @param format Format of sketch bitmap, either L1 or L8
 */
static inline void EVE_CoCmd_sketch(EVE_HalContext *phost, int16_t x, int16_t y, uint16_t w, uint16_t h, uint32_t ptr, uint16_t format)
{
	EVE_CoCmd_dwwwwdw(phost, CMD_SKETCH, x, y, w, h, ptr, format);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

/**
 * @brief Send CMD_LOGO
 *
 * @param phost Pointer to Hal context
 */
static inline void EVE_CoCmd_logo(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_LOGO);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif
}

/**
 * @brief Send CMD_CSKETCH. Only exists under FT801
 *
 * @param phost Pointer to Hal context
 * @param x x-coordinate of sketch area top-left, in pixels
 * @param y y-coordinate of sketch area top-left, in pixels
 * @param w Width of sketch area, in pixels
 * @param h Height of sketch area, in pixels
 * @param ptr Base address of sketch bitmap
 * @param format Format of sketch bitmap, either L1 or L8
 * @param freq Deprecated
 */
static inline void EVE_CoCmd_cSketch(EVE_HalContext *phost, int16_t x, int16_t y, uint16_t w, uint16_t h, uint32_t ptr, uint16_t format, uint16_t freq)
{
	{
		/* Simply fall back to regular sketch on non-FT801 platform */
		EVE_CoCmd_sketch(phost, x, y, w, h, ptr, format);
	}
}


/**
 * @brief Send CMD_PLAYVIDEO
 *
 * @param phost Pointer to Hal context
 * @param options Command option
 */
static inline void EVE_CoCmd_playVideo(EVE_HalContext *phost, uint32_t options)
{
	EVE_MULTI_TARGET_CHECK(CMD_PLAYVIDEO, EVE_CHIPID >= EVE_FT810);
	EVE_CoCmd_dd(phost, CMD_PLAYVIDEO, options);

#if (EVE_DL_OPTIMIZE)
	phost->DlPrimitive = 0;
#endif

	if (options & (OPT_FLASH | OPT_MEDIAFIFO))
	{
		/* WORKAROUND: CMD_PLAYVIDEO completes immediately,
		but the command following it does not.
		Write a CMD_NOP command to behave as documented */
			EVE_CoCmd_memCpy(phost, 0, 0, 1);
	}
}



#define EVE_CoCmd_animStart(phost, ch, aoptr, loop) EVE_COCMD_UNSUPPORTED(CMD_ANIMSTART, false)
#define EVE_CoCmd_animStop(phost, ch) EVE_COCMD_UNSUPPORTED(CMD_ANIMSTOP, false)
#define EVE_CoCmd_animXY(phost, ch, x, y) EVE_COCMD_UNSUPPORTED(CMD_ANIMXY, false)
#define EVE_CoCmd_animDraw(phost, ch) EVE_COCMD_UNSUPPORTED(CMD_ANIMDRAW, false)
#define EVE_CoCmd_animFrame(phost, x, y, aoptr, frame) EVE_COCMD_UNSUPPORTED(CMD_ANIMFRAME, false)



#define EVE_CoCmd_calibrateSub(phost, x, y, w, h) EVE_COCMD_UNSUPPORTED(CMD_CALIBRATESUB, 0)
#define EVE_CoCmd_testCard(phost) EVE_COCMD_UNSUPPORTED(CMD_TESTCARD, false)
#define EVE_CoCmd_animFrameRam(phost, x, y, aoptr, frame) EVE_COCMD_UNSUPPORTED(CMD_ANIMFRAMERAM, false)
#define EVE_CoCmd_animStartRam(phost, ch, aoptr, loop) EVE_COCMD_UNSUPPORTED(CMD_ANIMSTARTRAM, false)
#define EVE_CoCmd_runAnim(phost, waitmask, play) EVE_COCMD_UNSUPPORTED(CMD_RUNANIM, false)


/**********************************************************************
***********************************************************************
**********************************************************************/

#endif /* EVE_CO_CMD__H */

/* end of file */
