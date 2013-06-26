#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_font implementation
//-----------------------------------------------------------------------------
Object_font::Object_font(Object_Face *pObjFace) :
			Object(Gura_UserClass(font)), _pObjFace(pObjFace), _blendingFlag(true)
{
	ClearDeco();
}

Object *Object_font::Clone() const
{
	return NULL; //new Object_font(*this);
}

bool Object_font::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(face));
	return _pObjFace->DoDirProp(env, sig, symbols);
}

Value Object_font::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(face))) {
		return Value(Object_Face::Reference(_pObjFace.get()));
	}
	evaluatedFlag = false;
	return _pObjFace->DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_font::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<freetype.font:";
	str += _pObjFace->ToString(sig, false);
	str += ">";
	return str;
}

bool Object_font::SetPixelSizes(Signal sig, size_t width, size_t height)
{
	FT_Error err = ::FT_Set_Pixel_Sizes(GetFace(),
				static_cast<FT_UInt>(width), static_cast<FT_UInt>(height));
	if (err) {
		sig.SetError(ERR_IOError, "error occurs in FT_Set_Pixel_Sizes()");
		return false;
	}
	return true;
}

bool Object_font::CalcSize(Signal sig, const String &str, size_t &width, size_t &height)
{
	int xShifted = 0, yShifted = 0;
	String::const_iterator p = str.begin();
	int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		FT_GlyphSlot glyphSlot = LoadChar(codeUTF32);
		if (glyphSlot == NULL) continue;
		FT_Bitmap &bitmap = glyphSlot->bitmap;
		int xLeft = (xShifted >> 6) + glyphSlot->bitmap_left;
		int yTop = (yShifted >> 6)  - glyphSlot->bitmap_top;
		int xRight = xLeft + bitmap.width;
		int yBottom = yTop + bitmap.rows;
		if (xMin > xLeft) xMin = xLeft;
		if (xMax < xRight) xMax = xRight;
		if (yMin > yTop) yMin = yTop;
		if (yMax < yBottom) yMax = yBottom;
		xShifted += glyphSlot->advance.x;	// 26.6 fixed float
		yShifted += glyphSlot->advance.y;	// 26.6 fixed float
	} while (p != str.end());
	width = xMax - xMin, height = yMax - yMin;
	return true;
}

bool Object_font::DrawOnImage(Signal sig,
						Image *pImage, int x, int y, const String &str)
{
	unsigned long redFg = _color.GetRed();
	unsigned long greenFg = _color.GetGreen();
	unsigned long blueFg = _color.GetBlue();
	String::const_iterator p = str.begin();
	int xShifted = x << 6, yShifted = y << 6;
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		FT_GlyphSlot glyphSlot = LoadChar(codeUTF32);
		if (glyphSlot == NULL) continue;
		if (glyphSlot->format == FT_GLYPH_FORMAT_BITMAP) {
			FT_Bitmap &bitmap = glyphSlot->bitmap;
			int xOrg = (xShifted >> 6) + glyphSlot->bitmap_left;
			int yOrg = (yShifted >> 6) - glyphSlot->bitmap_top;
			int xAdj = xOrg, yAdj = yOrg;
			int width = bitmap.width;
			int height = bitmap.rows;
			if (bitmap.buffer == NULL) {
				// nothing to do
			} else if (!pImage->AdjustCoord(xAdj, yAdj, width, height)) {
				// nothing to do
			} else if (bitmap.pixel_mode == FT_PIXEL_MODE_MONO) {
				DrawMonoOnImage(pImage, xAdj, yAdj, bitmap.buffer,
							width, height, bitmap.pitch, xAdj - xOrg, yAdj - yOrg);
			} else if (bitmap.pixel_mode == FT_PIXEL_MODE_GRAY) {
				DrawGrayOnImage(pImage, xAdj, yAdj, bitmap.buffer,
							width, height, bitmap.pitch, xAdj - xOrg, yAdj - yOrg);
			}
		}
		xShifted += glyphSlot->advance.x;	// 26.6 fixed float
		yShifted += glyphSlot->advance.y;	// 26.6 fixed float
	} while (p != str.end());
	return true;
}

FT_GlyphSlot Object_font::LoadChar(unsigned long codeUTF32)
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
	FT_Error err = ::FT_Load_Char(GetFace(), codeUTF32,
					FT_LOAD_DEFAULT | (transformFlag? FT_LOAD_NO_BITMAP : 0));
	if (err) return NULL;
	FT_GlyphSlot glyphSlot = GetFace()->glyph;
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

void Object_font::DrawMonoOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset)
{
	unsigned char red = _color.GetRed();
	unsigned char green = _color.GetGreen();
	unsigned char blue = _color.GetBlue();
	std::auto_ptr<Image::Scanner>
				pScanner(pImage->CreateScanner(x, y, width, height));
	int bitOffset = xOffset % 8;
	unsigned char mask = 1 << (7 - bitOffset);
	const unsigned char *pLine = buffer + (xOffset / 8) + yOffset * pitch;
	const unsigned char *pPixel = pLine;
	bool alphaFlag = (pImage->GetFormat() == Image::FORMAT_RGBA);
	for (;;) {
		if (!(*pPixel & mask)) {
			// nothing to do
		} else if (alphaFlag) {
			pScanner->StorePixel(red, green, blue, 255);
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

void Object_font::DrawGrayOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset)
{
	unsigned long redFg = _color.GetRed();
	unsigned long greenFg = _color.GetGreen();
	unsigned long blueFg = _color.GetBlue();
	std::auto_ptr<Image::Scanner>
				pScanner(pImage->CreateScanner(x, y, width, height));
	const unsigned char *pLine = buffer + xOffset + yOffset * pitch;
	const unsigned char *pPixel = pLine;
	bool alphaFlag = (pImage->GetFormat() == Image::FORMAT_RGBA);
	for (;;) {
		if (_blendingFlag) {
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
						static_cast<unsigned char>(blue), 255);
			} else {
				pScanner->StorePixel(
						static_cast<unsigned char>(red),
						static_cast<unsigned char>(green),
						static_cast<unsigned char>(blue));
			}
		} else {
			if (alphaFlag) {
				if (pScanner->GetAlpha() < *pPixel) {
					pScanner->StorePixel(
						static_cast<unsigned char>(redFg),
						static_cast<unsigned char>(greenFg),
						static_cast<unsigned char>(blueFg),
						*pPixel);
				}
			} else {
				pScanner->StorePixel(
						static_cast<unsigned char>(redFg),
						static_cast<unsigned char>(greenFg),
						static_cast<unsigned char>(blueFg));
			}
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
// Gura interfaces for Object_font
//-----------------------------------------------------------------------------
// freetype.font(face:freetype.Face):map {block?}
Gura_DeclareFunction(font)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "face", VTYPE_Face);
	SetClassToConstruct(Gura_UserClass(font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(font)
{
	Object_Face *pObjFace = Object_Face::GetObject(args, 0);
	AutoPtr<Object_font> pObjFont(
					new Object_font(Object_Face::Reference(pObjFace)));
	return ReturnValue(env, sig, args, Value(pObjFont.release()));
}

// freetype.font#setcolor(color:color, blending?:boolean)
Gura_DeclareMethod(font, setcolor)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
	DeclareArg(env, "blending", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(font, setcolor)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	pThis->SetColor(Object_color::GetObject(args, 0)->GetColor(),
									args.IsBoolean(1)? args.GetBoolean(1) : true);
	return args.GetThis();
}

// freetype.font#setstrength(strength:number)
Gura_DeclareMethod(font, setstrength)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(font, setstrength)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	pThis->SetStrength(args.GetDouble(0));
	return args.GetThis();
}

// freetype.font#setslant(slant:number)
Gura_DeclareMethod(font, setslant)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "slant", VTYPE_number);
}

Gura_ImplementMethod(font, setslant)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	pThis->SetSlant(args.GetDouble(0));
	return args.GetThis();
}

// freetype.font#setrotate(degree:number)
Gura_DeclareMethod(font, setrotate)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "degree", VTYPE_number);
}

Gura_ImplementMethod(font, setrotate)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	pThis->SetRotate(args.GetDouble(0));
	return args.GetThis();
}

// freetype.font#setsize(width:number, height:number)
Gura_DeclareMethod(font, setsize)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(font, setsize)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	if (!pThis->SetPixelSizes(sig, args.GetSizeT(0), args.GetSizeT(1))) return Value::Null;
	return args.GetThis();
}

// freetype.font#setheight(height:number)
Gura_DeclareMethod(font, setheight)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(font, setheight)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	if (!pThis->SetPixelSizes(sig, 0, args.GetSizeT(0))) return Value::Null;
	return args.GetThis();
}

// freetype.font#cleardeco()
Gura_DeclareMethod(font, cleardeco)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(font, cleardeco)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	pThis->ClearDeco();
	return args.GetThis();
}

// freetype.font#drawtext(image:image, x:number, y:number, str:string):map:reduce
Gura_DeclareMethod(font, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Draws a text on the image.");
}

Gura_ImplementMethod(font, drawtext)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	Image *pImage = Object_image::GetObject(args, 0)->GetImage();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	if (pThis->DrawOnImage(sig, pImage, x, y, str)) return Value::Null;
	return args.GetThis();
}

// freetype.font#calcsize(str:string):map
Gura_DeclareMethod(font, calcsize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementMethod(font, calcsize)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	String str = args.GetStringSTL(0);
	size_t width, height;
	if (!pThis->CalcSize(sig, str, width, height)) return Value::Null;
	return Value::CreateAsList(env, 
			Value(static_cast<unsigned int>(width)),
			Value(static_cast<unsigned int>(height)));
}

// freetype.font#calcbbox(x:number, y:number, str:string):map
Gura_DeclareMethod(font, calcbbox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
}

// ******************* still buggy
Gura_ImplementMethod(font, calcbbox)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	String str = args.GetStringSTL(2);
	size_t width, height;
	if (!pThis->CalcSize(sig, str, width, height)) return Value::Null;
	return Value::CreateAsList(env,
			Value(x), Value(y - pThis->GetFace()->ascender / 4),
			Value(width), Value(height));
}

// implementation of class font
Gura_ImplementUserClass(font)
{
	Gura_AssignFunction(font);
	Gura_AssignMethod(font, setcolor);
	Gura_AssignMethod(font, setstrength);
	Gura_AssignMethod(font, setslant);
	Gura_AssignMethod(font, setrotate);
	Gura_AssignMethod(font, setsize);
	Gura_AssignMethod(font, setheight);
	Gura_AssignMethod(font, cleardeco);
	Gura_AssignMethod(font, drawtext);
	Gura_AssignMethod(font, calcsize);
	Gura_AssignMethod(font, calcbbox);
}

}}
