//-----------------------------------------------------------------------------
// Gura module: freetype
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define Gura_AssignRawValue(name) \
Gura_AssignValueEx(#name, Value(static_cast<double>(name)))

#define Gura_AssignFTValue(name) \
Gura_AssignValueEx(#name, Value(static_cast<double>(FT_##name)))

Gura_BeginModuleBody(freetype)

FT_Library g_lib;

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
Handler::~Handler()
{
	Stream::Delete(_pStream);
	delete _pStreamRec;
}

bool Handler::OpenFace(Signal sig, int index, FT_Face *aface)
{
	::memset(_pStreamRec, 0x00, sizeof(FT_StreamRec));
	_pStreamRec->descriptor.pointer = this;
	_pStreamRec->size = 0x7fffffffL;
	_pStreamRec->pos = 0;
	_pStreamRec->base = NULL;
	_pStreamRec->read = ReadStub;
	_pStreamRec->close = NULL;
	FT_Open_Args ftargs;
	::memset(&ftargs, 0x00, sizeof(ftargs));
	ftargs.flags = FT_OPEN_STREAM;
	ftargs.stream = _pStreamRec;
	FT_Error err = ::FT_Open_Face(g_lib, &ftargs, index, aface);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return false;
	}
	return true;
}

FT_ULong Handler::Read(FT_ULong pos, FT_Byte *buffer, FT_ULong count)
{
	if (!_pStream->Seek(_sig, pos, Stream::SeekSet)) return 0;
	if (count == 0) return 0;
	//::printf("read %08x %d bytes\n", pos, count);
	return static_cast<FT_ULong>(_pStream->Read(_sig, buffer, count));
}

FT_ULong Handler::ReadStub(FT_Stream streamFT,
						FT_ULong pos, FT_Byte *buffer, FT_ULong count)
{
	Handler *pHandler = reinterpret_cast<Handler *>(streamFT->descriptor.pointer);
	return pHandler->Read(pos, buffer, count);
}

//-----------------------------------------------------------------------------
// Gura interfaces for image
// These methods are available after importing freetype module.
//-----------------------------------------------------------------------------
// image#drawtext(font:freetype.font, x:number, y:number, str:string):map:reduce {block?}
Gura_DeclareMethod(image, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "font", VTYPE_font);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Draws a text on the image.");
}

Gura_ImplementMethod(image, drawtext)
{
	Object_image *pObjImage = Object_image::GetThisObj(args);
	Object_font *pObjFont = Object_font::GetObject(args, 0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	const Function *pFuncDeco = NULL;
	if (args.IsBlockSpecified()) {
		pFuncDeco = args.GetBlockFunc(env, sig, GetSymbolForBlock());
		if (pFuncDeco == NULL) return Value::Null;
	}
	if (pObjFont->DrawOnImage(env, sig, pObjImage->GetImage(),
								x, y, str, pFuncDeco)) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: freetype
//-----------------------------------------------------------------------------
// freetype.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(test)
{
#if 0
	FT_Face face;
	FT_Error err = ::FT_New_Face(g_lib, "arial.ttf", 0, &face);
	
	FT_Stream streamFT = new FT_StreamRec;
	
	Handler handler(sig, args.GetStream(0));
	::memset(streamFT, 0x00, sizeof(*streamFT));
	streamFT->descriptor.pointer = &handler;
	streamFT->size = 0x7fffffffL;
	streamFT->pos = 0;
	streamFT->base = NULL;
	streamFT->read = Handler::ReadStub;
	streamFT->close = NULL;
	FT_Open_Args ftargs;
	::memset(&ftargs, 0x00, sizeof(ftargs));
	ftargs.flags = FT_OPEN_STREAM;
	ftargs.stream = streamFT;
	err = ::FT_Open_Face(g_lib, &ftargs, 0, &face);
	
	delete streamFT;
	::printf("err: %d\n", err);
#endif
#if 0
	String pathName = GetSysFontPathName();
	Directory *pDirectoryParent = Directory::OpenDirectory(
						env, sig, pathName.c_str(), Directory::NF_Signal);
	Directory *pDirectory = NULL;
	while ((pDirectory = pDirectoryParent->Next(env, sig)) != NULL) {
		if (pDirectory->IsMatchName("*.ttf", true) ||
								pDirectory->IsMatchName("*.ttc", true)) {
			FT_Face face;
			String pathName = pDirectory->MakePathName(false);
			FT_Error err = ::FT_New_Face(g_lib, pathName.c_str(), 0, &face);
			if (err) continue;	// just ignore errored one
			for (int i = 0; i < face->num_faces; i++) {
				::printf("%d %-20s %-20s %08x %08x\n", i,
					face->family_name, face->style_name,
					face->face_flags, face->style_flags);
			}
			::FT_Done_Face(face);
		}
	}
#endif
	return Value::Null;
}

#if 0
	FT_Error err;
	FT_Face face;
	err = ::FT_New_Face(g_lib, "", 0, &face);
	//err = ::FT_Set_Char_Size(face, 0, 16 * 64, 300, 300);
	err = ::FT_Set_Pixel_Sizes(face, 0, 16);
	FT_GlyphSlot glyphSlot = face->glyph;
	FT_ULong codeUTF32 = 0x00000000;
	//FT_UInt glyph_index = ::FT_Get_Char_Index(face, codeUTF32);
	//err = ::FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
	//err = ::FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
	err = ::FT_Load_Char(face, codeUTF32, FT_LOAD_RENDER);
	FT_Bitmap &bitmap = glyphSlot->bitmap;
	bitmap.rows;
	bitmap.width;
	bitmap.pitch;
	bitmap.buffer;
	glyphSlot->bitmap_left;
	glyphSlot->bitmap_top;
	glyphSlot->advance.x;
	glyphSlot->advance.y;
	//err = ::FT_New_Memory_Face(g_lib, buffer, size, 0, &face);
	//FT_Open_Args args;
	//err = ::FT_Open_Face(g_lib, &args, face_index, &face);
	::FT_Done_Face(face);
	return Value::Null;
#endif


// freetype.sysfontpath(name?:string):map
Gura_DeclareFunction(sysfontpath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(sysfontpath)
{
	const char *name = args.Is_string(0)? args.GetString(0) : "";
	return Value(OAL::JoinPathName(GetSysFontPathName().c_str(), name));
}

// Module entry
Gura_ModuleEntry()
{
	::FT_Init_FreeType(&g_lib);
	// symbol realization
	Gura_RealizeUserSymbol(face);
	Gura_RealizeUserSymbol(pixel);
	Gura_RealizeUserSymbol(xMin);
	Gura_RealizeUserSymbol(yMin);
	Gura_RealizeUserSymbol(xMax);
	Gura_RealizeUserSymbol(yMax);
	Gura_RealizeUserSymbol(xx);
	Gura_RealizeUserSymbol(xy);
	Gura_RealizeUserSymbol(yx);
	Gura_RealizeUserSymbol(yy);
	Gura_RealizeUserSymbol(num_faces);
	Gura_RealizeUserSymbol(face_index);
	Gura_RealizeUserSymbol(face_flags);
	Gura_RealizeUserSymbol(style_flags);
	Gura_RealizeUserSymbol(num_glyphs);
	Gura_RealizeUserSymbol(family_name);
	Gura_RealizeUserSymbol(style_name);
	Gura_RealizeUserSymbol(num_fixed_sizes);
	Gura_RealizeUserSymbol(available_sizes);
	Gura_RealizeUserSymbol(num_charmaps);
	Gura_RealizeUserSymbol(charmaps);
	Gura_RealizeUserSymbol(generic);
	Gura_RealizeUserSymbol(bbox);
	Gura_RealizeUserSymbol(units_per_EM);
	Gura_RealizeUserSymbol(ascender);
	Gura_RealizeUserSymbol(descender);
	Gura_RealizeUserSymbol(color);
	Gura_RealizeUserSymbol(mode);
	Gura_RealizeUserSymbol(blend);
	Gura_RealizeUserSymbol(alpha);
	Gura_RealizeUserSymbol(strength);
	Gura_RealizeUserSymbol(slant);
	Gura_RealizeUserSymbol(rotate);
	Gura_RealizeUserSymbol(width);
	Gura_RealizeUserSymbol(height);
	Gura_RealizeUserSymbol(max_advance_width);
	Gura_RealizeUserSymbol(max_advance_height);
	Gura_RealizeUserSymbol(underline_position);
	Gura_RealizeUserSymbol(underline_thickness);
	Gura_RealizeUserSymbol(glyph);
	Gura_RealizeUserSymbol(size);
	Gura_RealizeUserSymbol(charmap);
	Gura_RealizeUserSymbol(advance);
	Gura_RealizeUserSymbol(format);
	Gura_RealizeUserSymbol(bitmap);
	Gura_RealizeUserSymbol(bitmap_left);
	Gura_RealizeUserSymbol(bitmap_top);
	Gura_RealizeUserSymbol(outline);
	// value declarations
	// BDF_PropertyType (BDF_PROPERTY_TYPE_XXX)
	Gura_AssignRawValue(BDF_PROPERTY_TYPE_NONE);
	Gura_AssignRawValue(BDF_PROPERTY_TYPE_ATOM);
	Gura_AssignRawValue(BDF_PROPERTY_TYPE_INTEGER);
	Gura_AssignRawValue(BDF_PROPERTY_TYPE_CARDINAL);
	// FREETYPE_XXX
	Gura_AssignRawValue(FREETYPE_MAJOR);
	Gura_AssignRawValue(FREETYPE_MINOR);
	Gura_AssignRawValue(FREETYPE_PATCH);
	// FT_ANGLE_XXX
	Gura_AssignFTValue(ANGLE_2PI);
	Gura_AssignFTValue(ANGLE_PI);
	Gura_AssignFTValue(ANGLE_PI2);
	Gura_AssignFTValue(ANGLE_PI4);
#ifdef FT_AUTOHINTER_H
	// FT_AUTOHINTER_SCRIPT_XXX
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_CJK);
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_INDIC);
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_LATIN);
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_NONE);
#endif
	// FT_Encoding (FT_ENCODING_XXX)
	Gura_AssignFTValue(ENCODING_ADOBE_CUSTOM);
	Gura_AssignFTValue(ENCODING_ADOBE_EXPERT);
	Gura_AssignFTValue(ENCODING_ADOBE_LATIN_1);
	Gura_AssignFTValue(ENCODING_ADOBE_STANDARD);
	Gura_AssignFTValue(ENCODING_APPLE_ROMAN);
	Gura_AssignFTValue(ENCODING_BIG5);
	Gura_AssignFTValue(ENCODING_GB2312);
	Gura_AssignFTValue(ENCODING_JOHAB);
	Gura_AssignFTValue(ENCODING_MS_BIG5);
	Gura_AssignFTValue(ENCODING_MS_GB2312);
	Gura_AssignFTValue(ENCODING_MS_JOHAB);
	Gura_AssignFTValue(ENCODING_MS_SJIS);
	Gura_AssignFTValue(ENCODING_MS_SYMBOL);
	Gura_AssignFTValue(ENCODING_MS_WANSUNG);
	Gura_AssignFTValue(ENCODING_NONE);
	Gura_AssignFTValue(ENCODING_OLD_LATIN_2);
	Gura_AssignFTValue(ENCODING_SJIS);
	Gura_AssignFTValue(ENCODING_UNICODE);
	Gura_AssignFTValue(ENCODING_WANSUNG);
	// FT_FACE_FLAG_XXX
	Gura_AssignFTValue(FACE_FLAG_SCALABLE);
	Gura_AssignFTValue(FACE_FLAG_FIXED_WIDTH);
	Gura_AssignFTValue(FACE_FLAG_SFNT);
	Gura_AssignFTValue(FACE_FLAG_HORIZONTAL);
	Gura_AssignFTValue(FACE_FLAG_VERTICAL);
	Gura_AssignFTValue(FACE_FLAG_KERNING);
	Gura_AssignFTValue(FACE_FLAG_FAST_GLYPHS);
	Gura_AssignFTValue(FACE_FLAG_MULTIPLE_MASTERS);
	Gura_AssignFTValue(FACE_FLAG_GLYPH_NAMES);
	Gura_AssignFTValue(FACE_FLAG_EXTERNAL_STREAM);
	Gura_AssignFTValue(FACE_FLAG_HINTER);
	Gura_AssignFTValue(FACE_FLAG_CID_KEYED);
	Gura_AssignFTValue(FACE_FLAG_TRICKY);
	// FT_FSTYPE_XXX
	Gura_AssignFTValue(FSTYPE_INSTALLABLE_EMBEDDING);
	Gura_AssignFTValue(FSTYPE_RESTRICTED_LICENSE_EMBEDDING);
	Gura_AssignFTValue(FSTYPE_PREVIEW_AND_PRINT_EMBEDDING);
	Gura_AssignFTValue(FSTYPE_EDITABLE_EMBEDDING);
	Gura_AssignFTValue(FSTYPE_NO_SUBSETTING);
	Gura_AssignFTValue(FSTYPE_BITMAP_EMBEDDING_ONLY);
	// FT_Glyph_BBox_Mode (FT_GLYPH_BBOX_XXX)
	Gura_AssignFTValue(GLYPH_BBOX_UNSCALED);
	Gura_AssignFTValue(GLYPH_BBOX_SUBPIXELS);
	Gura_AssignFTValue(GLYPH_BBOX_GRIDFIT);
	Gura_AssignFTValue(GLYPH_BBOX_TRUNCATE);
	Gura_AssignFTValue(GLYPH_BBOX_PIXELS);
	// FT_Kerning_Mode (FT_KERNING_XXX)
	Gura_AssignFTValue(KERNING_DEFAULT);
	Gura_AssignFTValue(KERNING_UNFITTED);
	Gura_AssignFTValue(KERNING_UNSCALED);
	// FT_LcdFilter (FT_LCD_FILTER_XXX)
	Gura_AssignFTValue(LCD_FILTER_NONE);
	Gura_AssignFTValue(LCD_FILTER_DEFAULT);
	Gura_AssignFTValue(LCD_FILTER_LIGHT);
	Gura_AssignFTValue(LCD_FILTER_LEGACY);
	// FT_LOAD_XXX
	Gura_AssignFTValue(LOAD_DEFAULT);
	Gura_AssignFTValue(LOAD_NO_SCALE);
	Gura_AssignFTValue(LOAD_NO_HINTING);
	Gura_AssignFTValue(LOAD_RENDER);
	Gura_AssignFTValue(LOAD_NO_BITMAP);
	Gura_AssignFTValue(LOAD_VERTICAL_LAYOUT);
	Gura_AssignFTValue(LOAD_FORCE_AUTOHINT);
	Gura_AssignFTValue(LOAD_CROP_BITMAP);
	Gura_AssignFTValue(LOAD_PEDANTIC);
	Gura_AssignFTValue(LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH);
	Gura_AssignFTValue(LOAD_NO_RECURSE);
	Gura_AssignFTValue(LOAD_IGNORE_TRANSFORM);
	Gura_AssignFTValue(LOAD_MONOCHROME);
	Gura_AssignFTValue(LOAD_LINEAR_DESIGN);
	Gura_AssignFTValue(LOAD_NO_AUTOHINT);
	// FT_GLYPH_FORMAT_XXX
	Gura_AssignFTValue(GLYPH_FORMAT_NONE);
	Gura_AssignFTValue(GLYPH_FORMAT_COMPOSITE);
	Gura_AssignFTValue(GLYPH_FORMAT_BITMAP);
	Gura_AssignFTValue(GLYPH_FORMAT_OUTLINE);
	Gura_AssignFTValue(GLYPH_FORMAT_PLOTTER);
	// FT_OPEN_XXX
	Gura_AssignFTValue(OPEN_DRIVER);
	Gura_AssignFTValue(OPEN_MEMORY);
	Gura_AssignFTValue(OPEN_PARAMS);
	Gura_AssignFTValue(OPEN_PATHNAME);
	Gura_AssignFTValue(OPEN_STREAM);
	// FT_Orientation (FT_ORIENTATION_XXX)
	Gura_AssignFTValue(ORIENTATION_TRUETYPE);
	Gura_AssignFTValue(ORIENTATION_POSTSCRIPT);
	Gura_AssignFTValue(ORIENTATION_FILL_RIGHT);
	Gura_AssignFTValue(ORIENTATION_FILL_LEFT);
	Gura_AssignFTValue(ORIENTATION_NONE);
	// FT_OUTLINE_XXX
	Gura_AssignFTValue(OUTLINE_NONE);
	Gura_AssignFTValue(OUTLINE_OWNER);
	Gura_AssignFTValue(OUTLINE_EVEN_ODD_FILL);
	Gura_AssignFTValue(OUTLINE_REVERSE_FILL);
	Gura_AssignFTValue(OUTLINE_IGNORE_DROPOUTS);
	Gura_AssignFTValue(OUTLINE_SMART_DROPOUTS);
	Gura_AssignFTValue(OUTLINE_INCLUDE_STUBS);
	Gura_AssignFTValue(OUTLINE_HIGH_PRECISION);
	Gura_AssignFTValue(OUTLINE_SINGLE_PASS);
	// FT_PARAM_TAG_XXX
	Gura_AssignFTValue(PARAM_TAG_IGNORE_PREFERRED_FAMILY);
	Gura_AssignFTValue(PARAM_TAG_IGNORE_PREFERRED_SUBFAMILY);
	Gura_AssignFTValue(PARAM_TAG_INCREMENTAL);
	Gura_AssignFTValue(PARAM_TAG_UNPATENTED_HINTING);
	// FT_Pixel_Mode (FT_PIXEL_MODE_XXX)
	Gura_AssignFTValue(PIXEL_MODE_NONE);
	Gura_AssignFTValue(PIXEL_MODE_MONO);
	Gura_AssignFTValue(PIXEL_MODE_GRAY);
	Gura_AssignFTValue(PIXEL_MODE_GRAY2);
	Gura_AssignFTValue(PIXEL_MODE_GRAY4);
	Gura_AssignFTValue(PIXEL_MODE_LCD);
	Gura_AssignFTValue(PIXEL_MODE_LCD_V);
	// FT_RASTER_FLAG_XXX
	Gura_AssignFTValue(RASTER_FLAG_DEFAULT);
	Gura_AssignFTValue(RASTER_FLAG_AA);
	Gura_AssignFTValue(RASTER_FLAG_DIRECT);
	Gura_AssignFTValue(RASTER_FLAG_CLIP);
	// FT_Render_Mode (FT_RENDER_MODE_XXX)
	Gura_AssignFTValue(RENDER_MODE_NORMAL);
	Gura_AssignFTValue(RENDER_MODE_LIGHT);
	Gura_AssignFTValue(RENDER_MODE_MONO);
	Gura_AssignFTValue(RENDER_MODE_LCD);
	Gura_AssignFTValue(RENDER_MODE_LCD_V);
	// FT_Size_Request_Type (FT_SIZE_REQUEST_TYPE_XXX)
	Gura_AssignFTValue(SIZE_REQUEST_TYPE_NOMINAL);
	Gura_AssignFTValue(SIZE_REQUEST_TYPE_REAL_DIM);
	Gura_AssignFTValue(SIZE_REQUEST_TYPE_BBOX);
	Gura_AssignFTValue(SIZE_REQUEST_TYPE_CELL);
	Gura_AssignFTValue(SIZE_REQUEST_TYPE_SCALES);
	// FT_StrokerBorder (FT_STROKER_BORDER_XXX)
	Gura_AssignFTValue(STROKER_BORDER_LEFT);
	Gura_AssignFTValue(STROKER_BORDER_RIGHT);
	// FT_Stroker_LineCap (FT_STROKER_LINECAP_XXX)
	Gura_AssignFTValue(STROKER_LINECAP_BUTT);
	Gura_AssignFTValue(STROKER_LINECAP_ROUND);
	Gura_AssignFTValue(STROKER_LINECAP_SQUARE);
	// FT_Stroker_LineCap (FT_STROKER_LINEJOIN_XXX)
	Gura_AssignFTValue(STROKER_LINEJOIN_ROUND);
	Gura_AssignFTValue(STROKER_LINEJOIN_BEVEL);
#if defined(FT_STROKER_LINEJOIN_MITER_VARIABLE)
	Gura_AssignFTValue(STROKER_LINEJOIN_MITER_VARIABLE);
#endif
	Gura_AssignFTValue(STROKER_LINEJOIN_MITER);
#if defined(FT_STROKER_LINEJOIN_MITER_FIXED)
	Gura_AssignFTValue(STROKER_LINEJOIN_MITER_FIXED);
#endif
	// FT_STYLE_FLAG_XXX
	Gura_AssignFTValue(STYLE_FLAG_ITALIC);
	Gura_AssignFTValue(STYLE_FLAG_BOLD);
	// FT_SUBGLYPH_FLAG_XXX
	Gura_AssignFTValue(SUBGLYPH_FLAG_ARGS_ARE_WORDS);
	Gura_AssignFTValue(SUBGLYPH_FLAG_ARGS_ARE_XY_VALUES);
	Gura_AssignFTValue(SUBGLYPH_FLAG_ROUND_XY_TO_GRID);
	Gura_AssignFTValue(SUBGLYPH_FLAG_SCALE);
	Gura_AssignFTValue(SUBGLYPH_FLAG_XY_SCALE);
	Gura_AssignFTValue(SUBGLYPH_FLAG_2X2);
	Gura_AssignFTValue(SUBGLYPH_FLAG_USE_MY_METRICS);
	// FT_TrueTypeEngineType (FT_TRUETYPE_ENGINE_TYPE_XXX)
	Gura_AssignFTValue(TRUETYPE_ENGINE_TYPE_NONE);
	Gura_AssignFTValue(TRUETYPE_ENGINE_TYPE_UNPATENTED);
	Gura_AssignFTValue(TRUETYPE_ENGINE_TYPE_PATENTED);
	// FT_VALIDATE_XXX
	Gura_AssignFTValue(VALIDATE_MS);
	Gura_AssignFTValue(VALIDATE_APPLE);
	Gura_AssignFTValue(VALIDATE_CKERN);
	// FT_VALIDATE_OTXXX
	Gura_AssignFTValue(VALIDATE_OT);
	Gura_AssignFTValue(VALIDATE_BASE);
	Gura_AssignFTValue(VALIDATE_GDEF);
	Gura_AssignFTValue(VALIDATE_GPOS);
	Gura_AssignFTValue(VALIDATE_GSUB);
	Gura_AssignFTValue(VALIDATE_JSTF);
	Gura_AssignFTValue(VALIDATE_MATH);
	// FT_VALIDATE_GXXX
	Gura_AssignFTValue(VALIDATE_GX);
	Gura_AssignFTValue(VALIDATE_GX_LENGTH);
	Gura_AssignFTValue(VALIDATE_feat);
	Gura_AssignFTValue(VALIDATE_mort);
	Gura_AssignFTValue(VALIDATE_morx);
	Gura_AssignFTValue(VALIDATE_bsln);
	Gura_AssignFTValue(VALIDATE_just);
	Gura_AssignFTValue(VALIDATE_kern);
	Gura_AssignFTValue(VALIDATE_opbd);
	Gura_AssignFTValue(VALIDATE_trak);
	Gura_AssignFTValue(VALIDATE_prop);
	Gura_AssignFTValue(VALIDATE_lcar);
	// FT_WinFNT_ID_XXX
	Gura_AssignFTValue(WinFNT_ID_CP1252);
	Gura_AssignFTValue(WinFNT_ID_DEFAULT);
	Gura_AssignFTValue(WinFNT_ID_SYMBOL);
	Gura_AssignFTValue(WinFNT_ID_MAC);
	Gura_AssignFTValue(WinFNT_ID_CP932);
	Gura_AssignFTValue(WinFNT_ID_CP949);
	Gura_AssignFTValue(WinFNT_ID_CP1361);
	Gura_AssignFTValue(WinFNT_ID_CP936);
	Gura_AssignFTValue(WinFNT_ID_CP950);
	Gura_AssignFTValue(WinFNT_ID_CP1253);
	Gura_AssignFTValue(WinFNT_ID_CP1254);
	Gura_AssignFTValue(WinFNT_ID_CP1258);
	Gura_AssignFTValue(WinFNT_ID_CP1255);
	Gura_AssignFTValue(WinFNT_ID_CP1256);
	Gura_AssignFTValue(WinFNT_ID_CP1257);
	Gura_AssignFTValue(WinFNT_ID_CP1251);
	Gura_AssignFTValue(WinFNT_ID_CP874);
	Gura_AssignFTValue(WinFNT_ID_CP1250);
	Gura_AssignFTValue(WinFNT_ID_OEM);
	// TT_ADOBE_ID_XXX
	Gura_AssignRawValue(TT_ADOBE_ID_STANDARD);
	Gura_AssignRawValue(TT_ADOBE_ID_EXPERT);
	Gura_AssignRawValue(TT_ADOBE_ID_CUSTOM);
	Gura_AssignRawValue(TT_ADOBE_ID_LATIN_1);
	// TT_APPLE_ID_XXX
	Gura_AssignRawValue(TT_APPLE_ID_DEFAULT);
	Gura_AssignRawValue(TT_APPLE_ID_ISO_10646);
	Gura_AssignRawValue(TT_APPLE_ID_UNICODE_1_1);
	Gura_AssignRawValue(TT_APPLE_ID_UNICODE_2_0);
	Gura_AssignRawValue(TT_APPLE_ID_UNICODE_32);
	Gura_AssignRawValue(TT_APPLE_ID_VARIANT_SELECTOR);
	// TT_ISO_ID_XXX
	Gura_AssignRawValue(TT_ISO_ID_10646);
	Gura_AssignRawValue(TT_ISO_ID_7BIT_ASCII);
	Gura_AssignRawValue(TT_ISO_ID_8859_1);
	// TT_MAC_ID_XXX
	Gura_AssignRawValue(TT_MAC_ID_ARABIC);
	Gura_AssignRawValue(TT_MAC_ID_ARMENIAN);
	Gura_AssignRawValue(TT_MAC_ID_BENGALI);
	Gura_AssignRawValue(TT_MAC_ID_BURMESE);
	Gura_AssignRawValue(TT_MAC_ID_DEVANAGARI);
	Gura_AssignRawValue(TT_MAC_ID_GEEZ);
	Gura_AssignRawValue(TT_MAC_ID_GEORGIAN);
	Gura_AssignRawValue(TT_MAC_ID_GREEK);
	Gura_AssignRawValue(TT_MAC_ID_GUJARATI);
	Gura_AssignRawValue(TT_MAC_ID_GURMUKHI);
	Gura_AssignRawValue(TT_MAC_ID_HEBREW);
	Gura_AssignRawValue(TT_MAC_ID_JAPANESE);
	Gura_AssignRawValue(TT_MAC_ID_KANNADA);
	Gura_AssignRawValue(TT_MAC_ID_KHMER);
	Gura_AssignRawValue(TT_MAC_ID_KOREAN);
	Gura_AssignRawValue(TT_MAC_ID_LAOTIAN);
	Gura_AssignRawValue(TT_MAC_ID_MALAYALAM);
	Gura_AssignRawValue(TT_MAC_ID_MALDIVIAN);
	Gura_AssignRawValue(TT_MAC_ID_MONGOLIAN);
	Gura_AssignRawValue(TT_MAC_ID_ORIYA);
	Gura_AssignRawValue(TT_MAC_ID_ROMAN);
	Gura_AssignRawValue(TT_MAC_ID_RSYMBOL);
	Gura_AssignRawValue(TT_MAC_ID_RUSSIAN);
	Gura_AssignRawValue(TT_MAC_ID_SIMPLIFIED_CHINESE);
	Gura_AssignRawValue(TT_MAC_ID_SINDHI);
	Gura_AssignRawValue(TT_MAC_ID_SINHALESE);
	Gura_AssignRawValue(TT_MAC_ID_SLAVIC);
	Gura_AssignRawValue(TT_MAC_ID_TAMIL);
	Gura_AssignRawValue(TT_MAC_ID_TELUGU);
	Gura_AssignRawValue(TT_MAC_ID_THAI);
	Gura_AssignRawValue(TT_MAC_ID_TIBETAN);
	Gura_AssignRawValue(TT_MAC_ID_TRADITIONAL_CHINESE);
	Gura_AssignRawValue(TT_MAC_ID_UNINTERP);
	Gura_AssignRawValue(TT_MAC_ID_VIETNAMESE);
	// TT_MS_ID_XXX
	Gura_AssignRawValue(TT_MS_ID_BIG_5);
	Gura_AssignRawValue(TT_MS_ID_GB2312);
	Gura_AssignRawValue(TT_MS_ID_JOHAB);
	Gura_AssignRawValue(TT_MS_ID_SJIS);
	Gura_AssignRawValue(TT_MS_ID_SYMBOL_CS);
	Gura_AssignRawValue(TT_MS_ID_UCS_4);
	Gura_AssignRawValue(TT_MS_ID_UNICODE_CS);
	Gura_AssignRawValue(TT_MS_ID_WANSUNG);
	// TT_PLATFORM_XXX
	Gura_AssignRawValue(TT_PLATFORM_APPLE_UNICODE);
	Gura_AssignRawValue(TT_PLATFORM_MACINTOSH);
	Gura_AssignRawValue(TT_PLATFORM_ISO);
	Gura_AssignRawValue(TT_PLATFORM_MICROSOFT);
	Gura_AssignRawValue(TT_PLATFORM_CUSTOM);
	Gura_AssignRawValue(TT_PLATFORM_ADOBE);
	// class realization
	Gura_RealizeUserClassWithoutPrepare(BDF_Property, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(BBox, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Face, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Vector, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Matrix, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Bitmap, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(CharMap, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Glyph, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(GlyphSlot, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Outline, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Raster, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Span, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(Stroker, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_CMapCache, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_ImageCache, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_ImageType, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_Manager, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_Node, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_SBit, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_SBitCache, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(FTC_Scaler, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(font, env.LookupClass(VTYPE_object));
	Gura_UserClass(BDF_Property)->Prepare(env);
	Gura_UserClass(BBox)->Prepare(env);
	Gura_UserClass(Face)->Prepare(env);
	Gura_UserClass(Vector)->Prepare(env);
	Gura_UserClass(Matrix)->Prepare(env);
	Gura_UserClass(Bitmap)->Prepare(env);
	Gura_UserClass(CharMap)->Prepare(env);
	Gura_UserClass(Glyph)->Prepare(env);
	Gura_UserClass(GlyphSlot)->Prepare(env);
	Gura_UserClass(Outline)->Prepare(env);
	Gura_UserClass(Raster)->Prepare(env);
	Gura_UserClass(Span)->Prepare(env);
	Gura_UserClass(Stroker)->Prepare(env);
	Gura_UserClass(FTC_CMapCache)->Prepare(env);
	Gura_UserClass(FTC_ImageCache)->Prepare(env);
	Gura_UserClass(FTC_ImageType)->Prepare(env);
	Gura_UserClass(FTC_Manager)->Prepare(env);
	Gura_UserClass(FTC_Node)->Prepare(env);
	Gura_UserClass(FTC_SBit)->Prepare(env);
	Gura_UserClass(FTC_SBitCache)->Prepare(env);
	Gura_UserClass(FTC_Scaler)->Prepare(env);
	Gura_UserClass(font)->Prepare(env);
	// method assignment to image type
	Gura_AssignMethodTo(VTYPE_image, image, drawtext);
	// function assignment
	Gura_AssignFunction(test);
	Gura_AssignFunction(sysfontpath);
	return true;
}

Gura_ModuleTerminate()
{
	::FT_Done_FreeType(g_lib);
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
#if defined(GURA_ON_MSWIN)
String GetSysFontPathName()
{
	char pathName[MAX_PATH];
	if (SUCCEEDED(::SHGetFolderPath(NULL, CSIDL_FONTS, NULL, 0, pathName))) {
		return String(pathName);
	}
	return String("");
}
#else
String GetSysFontPathName()
{
	return String("");
}
#endif

void SetError_Freetype(Signal sig, FT_Error err)
{
	sig.SetError(ERR_RuntimeError, "freetype error");
}

Gura_EndModuleBody(freetype, freetype)

Gura_RegisterModule(freetype)
