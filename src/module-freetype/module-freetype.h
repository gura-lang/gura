//-----------------------------------------------------------------------------
// Gura module: freetype
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_FREETYPE_H__
#define __GURA_MODULE_FREETYPE_H__
#include <gura.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_BITMAP_H
#include FT_OUTLINE_H
#include FT_GLYPH_H
#include FT_TRIGONOMETRY_H
#include FT_BDF_H
#ifdef FT_AUTOHINTER_H
#include FT_AUTOHINTER_H
#endif
#include FT_LCD_FILTER_H
#include FT_WINFONTS_H
#include FT_GX_VALIDATE_H
#include FT_OPENTYPE_VALIDATE_H
#include FT_SFNT_NAMES_H
#include FT_INCREMENTAL_H
#include FT_STROKER_H
#include FT_MODULE_H
#include FT_UNPATENTED_HINTING_H
#include FT_TRUETYPE_IDS_H
#include FT_CACHE_H
#include FT_ADVANCES_H

#define FREETYPE_CHECK_VERSION(major, minor, patch) \
(FREETYPE_MAJOR * 10000 + FREETYPE_MINOR * 100 + FREETYPE_PATCH >= \
 (major) * 10000 + (minor) * 100 + (patch))

#if defined(GURA_ON_MSWIN)
#include <shlobj.h>
#endif

Gura_BeginModuleHeader(freetype)

extern FT_Library g_lib;

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
class Handler {
private:
	Signal _sig;
	Stream *_pStream;
	FT_StreamRec *_pStreamRec;
public:
	inline Handler(Signal sig, Stream *pStream) :
			_sig(sig), _pStream(pStream), _pStreamRec(new FT_StreamRec) {}
	~Handler();
	bool OpenFace(Signal sig, int index, FT_Face *aface);
private:
	FT_ULong Read(FT_ULong pos, FT_Byte *buffer, FT_ULong count);
	static FT_ULong ReadStub(FT_Stream streamFT,
				FT_ULong pos, FT_Byte *buffer, FT_ULong count);
};

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
String GetSysFontPathName();
void SetError_Freetype(Signal sig, FT_Error err);

Gura_EndModuleHeader(freetype)

#endif
