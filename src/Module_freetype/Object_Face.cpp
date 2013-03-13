#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Face implementation
//-----------------------------------------------------------------------------
Object_Face::~Object_Face()
{
	delete _pHandler;
	::FT_Done_Face(_face);
}

Object *Object_Face::Clone() const
{
	return NULL; //new Object_Face(*this);
}

bool Object_Face::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(num_faces));
	symbols.insert(Gura_UserSymbol(face_index));
	symbols.insert(Gura_UserSymbol(family_name));
	symbols.insert(Gura_UserSymbol(style_name));
	symbols.insert(Gura_UserSymbol(bbox));
	symbols.insert(Gura_UserSymbol(ascender));
	symbols.insert(Gura_UserSymbol(descender));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_Face::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	double y_ppem = _face->size->metrics.y_ppem;// pixels/EM
	double units_per_EM = _face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (pSymbol->IsIdentical(Gura_UserSymbol(num_faces))) {
		return Value(_face->num_faces);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_index))) {
		return Value(_face->face_index);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flags))) {
		return Value(_face->face_flags);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_flags))) {
		return Value(_face->style_flags);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_glyphs))) {
		return Value(_face->num_glyphs);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(family_name))) {
		if (_face->family_name == NULL) return Value::Null;
		return Value(env, _face->family_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_name))) {
		if (_face->style_name == NULL) return Value::Null;
		return Value(env, _face->style_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_fixed_sizes))) {
		return Value(_face->num_fixed_sizes);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(available_sizes))) {
		//_face->num_fixed_sizes
		//_face->available_sizes
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_charmaps))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(charmaps))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(generic))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bbox))) {
		return Value::CreateAsList(env,
				Value(_face->bbox.xMin), Value(_face->bbox.yMin),
				Value(_face->bbox.xMax), Value(_face->bbox.yMax)); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(units_per_EM))) {
		return Value(_face->units_per_EM);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ascender))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->ascender * y_ppem / units_per_EM);
		}
		return Value(_face->ascender); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(descender))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->descender * y_ppem / units_per_EM);
		}
		return Value(_face->descender); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->height * y_ppem / units_per_EM);
		}
		return Value(_face->height); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_advance_width))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->max_advance_width * y_ppem / units_per_EM);
		}
		return Value(_face->max_advance_width); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_advance_height))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->max_advance_height * y_ppem / units_per_EM);
		}
		return Value(_face->max_advance_height); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(underline_position))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->underline_position * y_ppem / units_per_EM);
		}
		return Value(_face->underline_position); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(underline_thickness))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->underline_thickness * y_ppem / units_per_EM);
		}
		return Value(_face->underline_thickness); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(glyph))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(charmap))) {
		return Value::Null;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_Face::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<freetype.Face";
	str += ":";
	str += _face->family_name;
	if (_face->style_name != NULL) {
		str += ":";
		str += _face->style_name;
	}
	str += ":#";
	str += NumberToString(_face->face_index);
	str += ":";
	str += NumberToString(_face->num_faces);
	str += "faces";
	str += ">";
	return str;
}

bool Object_Face::Initialize(Signal sig, Stream *pStream, int index)
{
	_pHandler = new Handler(sig, Stream::Reference(pStream));
	return _pHandler->OpenFace(sig, index, &_face);
}

bool Object_Face::SetPixelSizes(Signal sig, size_t width, size_t height)
{
	FT_Error err = ::FT_Set_Pixel_Sizes(_face,
				static_cast<FT_UInt>(width), static_cast<FT_UInt>(height));
	if (err) {
		sig.SetError(ERR_IOError, "error occurs in FT_Set_Pixel_Sizes()");
		return false;
	}
	return true;
}

bool Object_Face::CalcSize(Signal sig, const String &str, size_t &width, size_t &height)
{
	int x = 0, y = 0;
	String::const_iterator p = str.begin();
	int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		FT_GlyphSlot glyphSlot = LoadChar(codeUTF32);
		if (glyphSlot == NULL) continue;
		FT_Bitmap &bitmap = glyphSlot->bitmap;
		int xLeft = x + glyphSlot->bitmap_left;
		int yTop = y - glyphSlot->bitmap_top;
		int xRight = xLeft + bitmap.width;
		int yBottom = yTop + bitmap.rows;
		if (xMin > xLeft) xMin = xLeft;
		if (xMax < xRight) xMax = xRight;
		if (yMin > yTop) yMin = yTop;
		if (yMax < yBottom) yMax = yBottom;
		x += glyphSlot->advance.x >> 6;	// 26.6 fixed float
		y += glyphSlot->advance.y >> 6;	// 26.6 fixed float
	} while (p != str.end());
	width = xMax - xMin, height = yMax - yMin;
	return true;
}

bool Object_Face::DrawOnImage(Signal sig,
				Object_image *pObjImage, int x, int y, const String &str)
{
	unsigned long redFg = _color.GetRed();
	unsigned long greenFg = _color.GetGreen();
	unsigned long blueFg = _color.GetBlue();
	String::const_iterator p = str.begin();
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		FT_GlyphSlot glyphSlot = LoadChar(codeUTF32);
		if (glyphSlot == NULL) continue;
		if (glyphSlot->format == FT_GLYPH_FORMAT_BITMAP) {
			FT_Bitmap &bitmap = glyphSlot->bitmap;
			int xOrg = x + glyphSlot->bitmap_left;
			int yOrg = y - glyphSlot->bitmap_top;
			int xAdj = xOrg, yAdj = yOrg;
			int width = bitmap.width;
			int height = bitmap.rows;
			if (bitmap.buffer == NULL) {
				// nothing to do
			} else if (!pObjImage->AdjustCoord(xAdj, yAdj, width, height)) {
				// nothing to do
			} else if (bitmap.pixel_mode == FT_PIXEL_MODE_MONO) {
				DrawMonoOnImage(pObjImage, xAdj, yAdj, bitmap.buffer,
							width, height, bitmap.pitch, xAdj - xOrg, yAdj - yOrg);
			} else if (bitmap.pixel_mode == FT_PIXEL_MODE_GRAY) {
				DrawGrayOnImage(pObjImage, xAdj, yAdj, bitmap.buffer,
							width, height, bitmap.pitch, xAdj - xOrg, yAdj - yOrg);
			}
		}
		x += glyphSlot->advance.x >> 6;	// 26.6 fixed float
		y += glyphSlot->advance.y >> 6;	// 26.6 fixed float
	} while (p != str.end());
	return true;
}

FT_GlyphSlot Object_Face::LoadChar(unsigned long codeUTF32)
{
	bool transformFlag = false;
	FT_Matrix matrix;	// 16.16 fixed float
	matrix.xx = 1 << 16;
	matrix.xy = 0;
	matrix.yx = 0;
	matrix.yy = 1 << 16;
	// slanting the font
	if (_deco.slant != 0.) {
		transformFlag = true;
		matrix.xy = static_cast<FT_Fixed>(_deco.slant * (1 << 16));
	}
	// rotating the font
	if (_deco.rotate.sinNum != 0.) {
		transformFlag = true;
		FT_Matrix matRot;
		int cos16 = static_cast<int>(_deco.rotate.cosNum * (1 << 16));
		int sin16 = static_cast<int>(_deco.rotate.sinNum * (1 << 16));
		matRot.xx = cos16;
		matRot.xy = -sin16;
		matRot.yx = sin16;
		matRot.yy = cos16;
		::FT_Matrix_Multiply(&matRot, &matrix);
	}
	// FT_Load_Char calls FT_Get_Char_Index and FT_Load_Glypy internally.
	FT_Error err = ::FT_Load_Char(_face, codeUTF32,
					FT_LOAD_DEFAULT | (transformFlag? FT_LOAD_NO_BITMAP : 0));
	if (err) return NULL;
	FT_GlyphSlot glyphSlot = _face->glyph;
	if (_deco.strength == 0.) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_NONE) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_COMPOSITE) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_BITMAP) {
		FT_Pos xStrength = static_cast<FT_Pos>(_deco.strength * (1 << 6)); // 26.6 fixed float
		FT_Pos yStrength = 0;
		err = ::FT_Bitmap_Embolden(g_lib, &glyphSlot->bitmap, xStrength, yStrength);
		if (err) return NULL;
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_OUTLINE) {
		FT_Pos strength = static_cast<FT_Pos>(_deco.strength * (1 << 6)); // 26.6 fixed float
		err = ::FT_Outline_Embolden(&glyphSlot->outline, strength);
		if (err) return NULL;
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_PLOTTER) {
		// nothing to do
	}
	if (glyphSlot->format == FT_GLYPH_FORMAT_NONE) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_COMPOSITE) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_BITMAP) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_OUTLINE) {
		if (transformFlag) {
			::FT_Outline_Transform(&glyphSlot->outline, &matrix);
		}
		// convert outline to bitmap
		err = ::FT_Render_Glyph(glyphSlot, FT_RENDER_MODE_NORMAL);
		if (err) return NULL;
		if (_deco.rotate.sinNum != 0.) {
			double cosNum = _deco.rotate.cosNum;
			double sinNum = -_deco.rotate.sinNum;
			FT_Pos x = glyphSlot->advance.x, y = glyphSlot->advance.y;
			glyphSlot->advance.x = static_cast<FT_Pos>(cosNum * x - sinNum * y);
			glyphSlot->advance.y = static_cast<FT_Pos>(sinNum * x + cosNum * y);
		}
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_PLOTTER) {
		// nothing to do
	}
	return glyphSlot;
}

void Object_Face::DrawMonoOnImage(Object_image *pObjImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset)
{
	unsigned char red = _color.GetRed();
	unsigned char green = _color.GetGreen();
	unsigned char blue = _color.GetBlue();
	std::auto_ptr<Object_image::Scanner>
				pScanner(pObjImage->CreateScanner(x, y, width, height));
	int bitOffset = xOffset % 8;
	unsigned char mask = 1 << (7 - bitOffset);
	const unsigned char *pLine = buffer + (xOffset / 8) + yOffset * pitch;
	const unsigned char *pPixel = pLine;
	bool alphaFlag = (pObjImage->GetFormat() == Image::FORMAT_RGBA);
	for (;;) {
		if (!(*pPixel & mask)) {
			// nothing to do
		} else if (alphaFlag) {
			pScanner->StorePixel(red, green, blue, _alpha);
		} else {
			pScanner->StorePixel(red, green, blue);
		}
		if (pScanner->NextPixel()) {
			mask >>= 1;
			if (mask == 0x00) {
				mask = 1 << 7;
				pPixel++;
			}
		} else if (pScanner->NextLine()) {
			pLine += pitch;
			pPixel = pLine;
			mask = 1 << (7 - bitOffset);
		} else {
			break;
		}
	}
}

void Object_Face::DrawGrayOnImage(Object_image *pObjImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset)
{
	unsigned long redFg = _color.GetRed();
	unsigned long greenFg = _color.GetGreen();
	unsigned long blueFg = _color.GetBlue();
	std::auto_ptr<Object_image::Scanner>
				pScanner(pObjImage->CreateScanner(x, y, width, height));
	const unsigned char *pLine = buffer + xOffset + yOffset * pitch;
	const unsigned char *pPixel = pLine;
	bool alphaFlag = (pObjImage->GetFormat() == Image::FORMAT_RGBA);
	for (;;) {
		unsigned long ratioFg = *pPixel;
		unsigned long ratioBg = 255 - ratioFg;
		unsigned long redBg = pScanner->GetRed();
		unsigned long greenBg = pScanner->GetGreen();
		unsigned long blueBg = pScanner->GetBlue();
		unsigned long red = redFg * ratioFg + redBg * ratioBg;
		unsigned long green = greenFg * ratioFg + greenBg * ratioBg;
		unsigned long blue = blueFg * ratioFg + blueBg * ratioBg;
		red /= 255, green /= 255, blue /= 255;
		if (alphaFlag) {
			pScanner->StorePixel(
					static_cast<unsigned char>(red),
					static_cast<unsigned char>(green),
					static_cast<unsigned char>(blue),
					_alpha);
		} else {
			pScanner->StorePixel(
					static_cast<unsigned char>(red),
					static_cast<unsigned char>(green),
					static_cast<unsigned char>(blue));
		}
		if (pScanner->NextPixel()) {
			pPixel++;
		} else if (pScanner->NextLine()) {
			pLine += pitch;
			pPixel = pLine;
		} else {
			break;
		}
	}
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Face
//-----------------------------------------------------------------------------
// freetype.Face.New(stream:stream, face_index:number => 0):map {block?}
Gura_DeclareClassMethod(Face, New)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "face_index", VTYPE_number,
						OCCUR_Once, FLAG_None, new Expr_Value(0));
	//SetClassToConstruct(Gura_UserClass(Face));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(Face, New)
{
	AutoPtr<Stream> pStream(Stream::Reference(&args.GetStream(0)));
	int index = args.GetInt(1);
	if (!pStream->IsBwdSeekable()) {
		pStream.reset(Stream::Prefetch(sig, pStream.release(), true));
		if (sig.IsSignalled()) return Value::Null;
	}
	AutoPtr<Object_Face> pObjFace(new Object_Face());
	pObjFace->Initialize(sig, pStream.release(), index);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjFace.release()));
}

// freetype.Face#setcolor(color:color)
Gura_DeclareMethod(Face, setcolor)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(Face, setcolor)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	pThis->SetColor(args.GetColorObj(0)->GetColor());
	return args.GetThis();
}

// freetype.Face#setalpha(alpha:number)
Gura_DeclareMethod(Face, setalpha)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementMethod(Face, setalpha)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	pThis->SetAlpha(args.GetUChar(0));
	return args.GetThis();
}

// freetype.Face#setstrength(strength:number)
Gura_DeclareMethod(Face, setstrength)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(Face, setstrength)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	pThis->SetStrength(args.GetDouble(0));
	return args.GetThis();
}

// freetype.Face#setslant(slant:number)
Gura_DeclareMethod(Face, setslant)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "slant", VTYPE_number);
}

Gura_ImplementMethod(Face, setslant)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	pThis->SetSlant(args.GetDouble(0));
	return args.GetThis();
}

// freetype.Face#setrotate(degree:number)
Gura_DeclareMethod(Face, setrotate)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "degree", VTYPE_number);
}

Gura_ImplementMethod(Face, setrotate)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	pThis->SetRotate(args.GetDouble(0));
	return args.GetThis();
}

// freetype.Face#setsize(width:number, height:number)
Gura_DeclareMethod(Face, setsize)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(Face, setsize)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	if (!pThis->SetPixelSizes(sig, args.GetSizeT(0), args.GetSizeT(1))) return Value::Null;
	return args.GetThis();
}

// freetype.Face#setheight(height:number)
Gura_DeclareMethod(Face, setheight)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(Face, setheight)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	if (!pThis->SetPixelSizes(sig, 0, args.GetSizeT(0))) return Value::Null;
	return args.GetThis();
}

// freetype.Face#cleardeco()
Gura_DeclareMethod(Face, cleardeco)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(Face, cleardeco)
{
	Object_Face *pThis = Object_Face::GetThisObj(args);
	pThis->ClearDeco();
	return args.GetThis();
}

// freetype.Face#drawtext(image:image, x:number, y:number, str:string):map:reduce
Gura_DeclareMethod(Face, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Draws a text on the image.");
}

Gura_ImplementMethod(Face, drawtext)
{
	Object_Face *pObjFace = Object_Face::GetThisObj(args);
	Object_image *pObjImage = Object_image::GetObject(args, 0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	if (pObjFace->DrawOnImage(sig, pObjImage, x, y, str)) return Value::Null;
	return args.GetThis();
}

// freetype.Face#calcsize(str:string):map
Gura_DeclareMethod(Face, calcsize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementMethod(Face, calcsize)
{
	Object_Face *pObjFace = Object_Face::GetThisObj(args);
	String str = args.GetStringSTL(0);
	size_t width, height;
	if (!pObjFace->CalcSize(sig, str, width, height)) return Value::Null;
	return Value::CreateAsList(env, 
			Value(static_cast<unsigned int>(width)),
			Value(static_cast<unsigned int>(height)));
}

// freetype.Face#calcbbox(x:number, y:number, str:string):map
Gura_DeclareMethod(Face, calcbbox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
}

// ******************* still buggy
Gura_ImplementMethod(Face, calcbbox)
{
	Object_Face *pObjFace = Object_Face::GetThisObj(args);
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	String str = args.GetStringSTL(2);
	size_t width, height;
	if (!pObjFace->CalcSize(sig, str, width, height)) return Value::Null;
	return Value::CreateAsList(env,
			Value(x), Value(y - pObjFace->GetFace()->ascender / 4),
			Value(width), Value(height));
}

// implementation of class Face
Gura_ImplementUserClass(Face)
{
	Gura_AssignMethod(Face, New);
	Gura_AssignMethod(Face, setcolor);
	Gura_AssignMethod(Face, setalpha);
	Gura_AssignMethod(Face, setstrength);
	Gura_AssignMethod(Face, setslant);
	Gura_AssignMethod(Face, setrotate);
	Gura_AssignMethod(Face, setsize);
	Gura_AssignMethod(Face, setheight);
	Gura_AssignMethod(Face, cleardeco);
	Gura_AssignMethod(Face, drawtext);
	Gura_AssignMethod(Face, calcsize);
	Gura_AssignMethod(Face, calcbbox);
}

}}
