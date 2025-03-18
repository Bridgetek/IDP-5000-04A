/*
ESD Framework
Copyright (C) 2018  Bridgetek Pte Lte
Author: Jan Boon <jan.boon@kaetemi.be>
*/

#include "Esd_FontInfo.h"

#ifndef NDEBUG
#define ESD_FONTINFO_DEBUG
#endif

#ifdef ESD_FONTINFO_DEBUG
#define esd_resourceinfo_printf(fmt, ...) eve_printf(fmt, ##__VA_ARGS__)
#else
#define esd_resourceinfo_printf(fmt, ...) eve_noop()
#endif

extern ESD_CORE_EXPORT EVE_HalContext *Esd_Host;
extern ESD_CORE_EXPORT Esd_GpuAlloc *Esd_GAlloc;

ESD_CORE_EXPORT uint32_t Esd_LoadFont(Esd_FontInfo *fontInfo)
{
	uint32_t glyphAddr;

	if (fontInfo->Type != ESD_FONT_LEGACY && fontInfo->Type != ESD_FONT_EXTENDED)
	{
		return GA_INVALID;
	}

	// Load glyphs
	glyphAddr = Esd_LoadResource(&fontInfo->GlyphResource, NULL);
	if (glyphAddr != GA_INVALID)
	{
		// Load map
		uint32_t fontAddr;
		bool rewriteAddr;

		fontAddr = Esd_GpuAlloc_Get(Esd_GAlloc, fontInfo->FontResource.GpuHandle);
		if (fontAddr == GA_INVALID)
		{
			fontAddr = Esd_LoadResource(&fontInfo->FontResource, NULL);
			rewriteAddr = true;
		}
		else
		{
			rewriteAddr = (glyphAddr != fontInfo->GlyphAddress);
		}

		if (fontAddr == GA_INVALID)
		{
			// Failed to load font block, unload glyphs
			esd_resourceinfo_printf("Failed to load font block, free glyphs\n");
			Esd_FreeResource(&fontInfo->GlyphResource);
			return GA_INVALID;
		}

		if (rewriteAddr)
		{
			// Rewrite glyph address in the font block
			uint32_t format;
			(void)format;
			switch (fontInfo->Type)
			{
			case ESD_FONT_LEGACY: {
				format = EVE_Hal_rd32(Esd_Host, fontAddr + 128);
				fontInfo->FontHeight = EVE_Hal_rd32(Esd_Host, fontAddr + 140);
				esd_resourceinfo_printf("Set legacy glyph address to %i\n", (int)glyphAddr);
				EVE_Hal_wr32(Esd_Host, fontAddr + 144, glyphAddr);
				fontInfo->BitmapHandle = ESD_BITMAPHANDLE_INVALID;
				break;
			}
			case ESD_FONT_EXTENDED: {
				format = EVE_Hal_rd32(Esd_Host, fontAddr + 8);
				fontInfo->FontHeight = EVE_Hal_rd32(Esd_Host, fontAddr + 28);
				esd_resourceinfo_printf("Set extended glyph address to %i\n", (int)glyphAddr);
				EVE_Hal_wr32(Esd_Host, fontAddr + 32, glyphAddr);
				fontInfo->BitmapHandle = ESD_BITMAPHANDLE_INVALID;
				break;
			}
			default: {
				format = 0;
				break;
			}
			}
			if (!fontInfo->BaseLine)
				fontInfo->BaseLine = fontInfo->FontHeight;
			if (!fontInfo->CapsHeight)
				fontInfo->CapsHeight = fontInfo->FontHeight;
			fontInfo->GlyphAddress = glyphAddr;

		}

		return fontAddr;
	}

	return GA_INVALID;
}

ESD_CORE_EXPORT void Esd_FontPersist(Esd_FontInfo *fontInfo)
{
	Esd_LoadFont(fontInfo);
}

/* end of file */
