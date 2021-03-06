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
// Symbols
//-----------------------------------------------------------------------------
Gura_DeclareUserSymbol(face);
Gura_DeclareUserSymbol(pixel);
Gura_DeclareUserSymbol(xMin);
Gura_DeclareUserSymbol(yMin);
Gura_DeclareUserSymbol(xMax);
Gura_DeclareUserSymbol(yMax);
Gura_DeclareUserSymbol(xx);
Gura_DeclareUserSymbol(xy);
Gura_DeclareUserSymbol(yx);
Gura_DeclareUserSymbol(yy);
// Face attributes
Gura_DeclareUserSymbol(num_faces);
Gura_DeclareUserSymbol(face_index);
Gura_DeclareUserSymbol(face_flags);
Gura_DeclareUserSymbol(style_flags);
Gura_DeclareUserSymbol(num_glyphs);
Gura_DeclareUserSymbol(family_name);
Gura_DeclareUserSymbol(style_name);
Gura_DeclareUserSymbol(num_fixed_sizes);
Gura_DeclareUserSymbol(available_sizes);
Gura_DeclareUserSymbol(num_charmaps);
Gura_DeclareUserSymbol(charmaps);
Gura_DeclareUserSymbol(generic);
Gura_DeclareUserSymbol(bbox);
Gura_DeclareUserSymbol(units_per_EM);
Gura_DeclareUserSymbol(ascender);
Gura_DeclareUserSymbol(descender);
Gura_DeclareUserSymbol(color);
Gura_DeclareUserSymbol(mode);
Gura_DeclareUserSymbol(blend);
Gura_DeclareUserSymbol(alpha);
Gura_DeclareUserSymbol(strength);
Gura_DeclareUserSymbol(slant);
Gura_DeclareUserSymbol(rotate);
Gura_DeclareUserSymbol(width);
Gura_DeclareUserSymbol(height);
Gura_DeclareUserSymbol(max_advance_width);
Gura_DeclareUserSymbol(max_advance_height);
Gura_DeclareUserSymbol(underline_position);
Gura_DeclareUserSymbol(underline_thickness);
Gura_DeclareUserSymbol(glyph);
Gura_DeclareUserSymbol(size);
Gura_DeclareUserSymbol(charmap);
Gura_DeclareUserSymbol(advance);
Gura_DeclareUserSymbol(format);
Gura_DeclareUserSymbol(bitmap);
Gura_DeclareUserSymbol(bitmap_left);
Gura_DeclareUserSymbol(bitmap_top);
Gura_DeclareUserSymbol(outline);

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
class Handler {
private:
	Signal &_sig;
	Stream *_pStream;
	FT_StreamRec *_pStreamRec;
public:
	inline Handler(Signal &sig, Stream *pStream) :
			_sig(sig), _pStream(pStream), _pStreamRec(new FT_StreamRec) {}
	~Handler();
	bool OpenFace(Signal &sig, int index, FT_Face *aface);
private:
	FT_ULong Read(FT_ULong pos, FT_Byte *buffer, FT_ULong count);
	static FT_ULong ReadStub(FT_Stream streamFT,
				FT_ULong pos, FT_Byte *buffer, FT_ULong count);
};

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
String GetSysFontPathName(const char *name);
void SetError_Freetype(Signal &sig, FT_Error err);

Gura_EndModuleHeader(freetype)

#endif
