/**
 * @file EVE_LoadFile.h
 * @brief Eve_Hal framework APIs for loading file
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

#ifndef EVE_LOADFILE__H
#define EVE_LOADFILE__H

/*********************
 *      INCLUDES
 *********************/
#include "EVE_Platform.h"

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

/*
On embedded platforms, filename character set depends on the filesystem library.
*/

/** Load SD card */
bool EVE_Util_loadSdCard(EVE_HalContext *phost);
bool EVE_Util_sdCardReady(EVE_HalContext *phost);

bool EVE_Util_loadRawFile(EVE_HalContext *phost, uint32_t address, const char *filename);
 bool EVE_Util_loadInflateFile(EVE_HalContext *phost, uint32_t address, const char *filename);

/** Load a file using CMD_LOADIMAGE.
The image format is provided as output to the optional format argument */
bool EVE_Util_loadImageFile(EVE_HalContext *phost, uint32_t address, const char *filename, uint32_t *format);

/** Load a file into the coprocessor FIFO */
bool EVE_Util_loadCmdFile(EVE_HalContext *phost, const char *filename, uint32_t *transfered);

/** Read a file into a buffer, returns the number of bytes read */
size_t EVE_Util_readFile(EVE_HalContext *phost, uint8_t *buffer, size_t size, const char *filename);

/** Load a file into the media FIFO.
If transfered is set, the file may be streamed partially,
and will be kept open until EVE_Util_closeFile is called,
and stop once the coprocessor has processed it.
Filename may be omitted in subsequent calls */
bool EVE_Util_loadMediaFile(EVE_HalContext *phost, const char *filename, uint32_t *transfered);

void EVE_Util_closeFile(EVE_HalContext *phost);

#endif
/* end of file */
