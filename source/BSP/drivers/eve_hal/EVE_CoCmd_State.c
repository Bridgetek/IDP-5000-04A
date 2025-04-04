/**
 * @file EVE_CoCmd_State.c
 * @brief EVE's co-processor command
 *
 * @author Bridgetek
 *
 * @date 2018
 *
 * MIT License
 *
 * Copyright (c) [2019] [Bridgetek Pte Ltd (BRTChip)]
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

#include "EVE_Platform.h"

void EVE_CoCmd_bgColor(EVE_HalContext *phost, uint32_t c)
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

void EVE_CoCmd_fgColor(EVE_HalContext *phost, uint32_t c)
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

void EVE_CoCmd_loadIdentity(EVE_HalContext *phost)
{
	EVE_CoCmd_d(phost, CMD_LOADIDENTITY);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = false; /* Identity */
#endif
}

void EVE_CoCmd_translate(EVE_HalContext *phost, int32_t tx, int32_t ty)
{
	EVE_CoCmd_ddd(phost, CMD_TRANSLATE, tx, ty);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = true;
#endif
}

void EVE_CoCmd_scale(EVE_HalContext *phost, int32_t sx, int32_t sy)
{
	EVE_CoCmd_ddd(phost, CMD_SCALE, sx, sy);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = true;
#endif
}

void EVE_CoCmd_rotate(EVE_HalContext *phost, int32_t a)
{
	EVE_CoCmd_dd(phost, CMD_ROTATE, a);

#if EVE_DL_OPTIMIZE
	phost->CoBitmapTransform = true;
#endif
}

void EVE_CoCmd_setMatrix(EVE_HalContext *phost)
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

void EVE_CoCmd_setFont(EVE_HalContext *phost, uint32_t font, uint32_t ptr)
{
	EVE_CoCmd_ddd(phost, CMD_SETFONT, font, ptr);
}

void EVE_CoCmd_gradColor(EVE_HalContext *phost, uint32_t c)
{
	EVE_CoCmd_dd(phost, CMD_GRADCOLOR, c);
}

void EVE_CoCmd_setBase(EVE_HalContext *phost, uint32_t base)
{
	EVE_CoCmd_dd(phost, CMD_SETBASE, base);
}

void EVE_CoCmd_setFont2(EVE_HalContext *phost, uint32_t font, uint32_t ptr, uint32_t firstchar)
{
	EVE_CoCmd_dddd(phost, CMD_SETFONT2, font, ptr, firstchar);
#if EVE_DL_OPTIMIZE
	EVE_DL_STATE.Handle = (uint8_t)font;
#endif
}

void EVE_CoCmd_setScratch(EVE_HalContext *phost, uint32_t handle)
{
	EVE_CoCmd_dd(phost, CMD_SETSCRATCH, handle);
	phost->CoScratchHandle = (uint8_t)handle;
}

void EVE_CoCmd_romFont(EVE_HalContext *phost, uint32_t font, uint32_t romslot)
{
	EVE_CoCmd_ddd(phost, CMD_ROMFONT, font, romslot);
#if EVE_DL_OPTIMIZE
	EVE_DL_STATE.Handle = (uint8_t)font;
#endif
}

void EVE_CoCmd_setBitmap(EVE_HalContext *phost, uint32_t source, uint16_t fmt, uint16_t w, uint16_t h)
{
	EVE_CoCmd_ddwww(phost, CMD_SETBITMAP, source, fmt, w, h);
}


bool EVE_CoCmd_bitmapTransform(EVE_HalContext *phost, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t tx0, int32_t ty0, int32_t tx1, int32_t ty1, int32_t tx2, int32_t ty2, uint16_t *result)
{
	uint16_t resAddr;

#if EVE_CMD_HOOKS
	if (phost->CoCmdHook && phost->CoCmdHook(phost, CMD_BITMAP_TRANSFORM, 0))
		return false;
#endif

	EVE_Cmd_startFunc(phost);
	EVE_Cmd_wr32(phost, CMD_BITMAP_TRANSFORM);
	EVE_Cmd_wr32(phost, x0);
	EVE_Cmd_wr32(phost, y0);
	EVE_Cmd_wr32(phost, x1);
	EVE_Cmd_wr32(phost, y1);
	EVE_Cmd_wr32(phost, x2);
	EVE_Cmd_wr32(phost, y2);
	EVE_Cmd_wr32(phost, tx0);
	EVE_Cmd_wr32(phost, ty0);
	EVE_Cmd_wr32(phost, tx1);
	EVE_Cmd_wr32(phost, ty1);
	EVE_Cmd_wr32(phost, tx2);
	EVE_Cmd_wr32(phost, ty2);
	resAddr = EVE_Cmd_moveWp(phost, 4);
	EVE_Cmd_endFunc(phost);

#if EVE_DL_OPTIMIZE
	EVE_DL_STATE.BitmapTransform = true;
#endif

	/* Read result */
	if (result)
	{
		if (!EVE_Cmd_waitFlush(phost))
			return false;
		*result = EVE_Hal_rd16(phost, RAM_CMD + resAddr);
	}
	return true;
}

/* end of file */
