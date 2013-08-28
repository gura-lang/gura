#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_font implementation
//-----------------------------------------------------------------------------
Object_font::Object_font(Object_Face *pObjFace, Object_color *pObjColor) :
		Object(Gura_UserClass(font)), _pObjFace(pObjFace), _pObjColor(pObjColor)
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
	symbols.insert(Gura_UserSymbol(color));
	symbols.insert(Gura_UserSymbol(mode));
	symbols.insert(Gura_UserSymbol(strength));
	symbols.insert(Gura_UserSymbol(slant));
	symbols.insert(Gura_UserSymbol(rotate));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_font::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(face))) {
		return Value(Object_Face::Reference(_pObjFace.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(color))) {
		return Value(Object_color::Reference(_pObjColor.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mode))) {
		const Symbol *pSymbol =
			(_mode == MODE_Blend)? Gura_UserSymbol(blend) :
			(_mode == MODE_Alpha)? Gura_UserSymbol(alpha) :
			Gura_UserSymbol(blend);
		return Value(pSymbol);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(strength))) {
		return Value(_strength);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(slant))) {
		return Value(_slant);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(rotate))) {
		return Value(_rotate.deg);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_width);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_height);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_font::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(color))) {
		Value valueCasted;
		if (!value.CastType(env, sig, VTYPE_color, valueCasted)) {
			sig.SetError(ERR_ValueError, "value must be color");
			return Value::Null;
		}
		_pObjColor->SetColor(Object_color::GetObject(valueCasted)->GetColor());
		return Value(Object_color::Reference(_pObjColor.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mode))) {
		if (!value.MustBeSymbol(sig)) return Value::Null;
		const Symbol *pSymbolVal = value.GetSymbol();
		if (pSymbolVal->IsIdentical(Gura_UserSymbol(blend))) {
			_mode = MODE_Blend;
		} else if (pSymbolVal->IsIdentical(Gura_UserSymbol(alpha))) {
			_mode = MODE_Alpha;
		} else {
			sig.SetError(ERR_ValueError, "symbol must be `blend or `alpha");
			return Value::Null;
		}
		return Value(pSymbolVal);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(strength))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		SetStrength(value.GetDouble());
		return Value(_strength);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(slant))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		SetSlant(value.GetDouble());
		return Value(_slant);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(rotate))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		SetRotate(value.GetDouble());
		return Value(_rotate.deg);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		SetWidth(value.GetDouble());
		return Value(_width);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		SetHeight(value.GetDouble());
		return Value(_height);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_font::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<freetype.font:";
	str += _pObjFace->ToString(sig, false);
	str += ">";
	return str;
}

void Object_font::ClearDeco()
{
	_pObjColor->SetColor(Color::Black);
	_mode = MODE_Blend;
	_width = 0, _height = 0; // default value is used when _height == 0.
	_strength = 0.;
	_slant = 0.;
	_rotate.deg = 0.;
	_rotate.cosNum = 1., _rotate.sinNum = 0.;
}

bool Object_font::CalcSize(Environment &env, Signal sig, const String &str,
					size_t &width, size_t &height, const Function *pFuncDeco)
{
	int xShifted = 0, yShifted = 0;
	String::const_iterator p = str.begin();
	int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
	size_t idx = 0;
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		if (LoadAndDecorateChar(env, sig, codeUTF32, idx, pFuncDeco) != 0) continue;
		FT_GlyphSlot glyphSlot = GetFace()->glyph;
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
		idx++;
	} while (p != str.end());
	width = xMax - xMin, height = yMax - yMin;
	return true;
}

bool Object_font::DrawOnImage(Environment &env, Signal sig, Image *pImage,
				int x, int y, const String &str, const Function *pFuncDeco)
{
	const Color &color = _pObjColor->GetColor();
	unsigned long redFg = color.GetRed();
	unsigned long greenFg = color.GetGreen();
	unsigned long blueFg = color.GetBlue();
	String::const_iterator p = str.begin();
	int xShifted = x << 6, yShifted = y << 6;
	size_t idx = 0;
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		if (LoadAndDecorateChar(env, sig, codeUTF32, idx, pFuncDeco) != 0) continue;
		FT_GlyphSlot glyphSlot = GetFace()->glyph;
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
		idx++;
	} while (p != str.end());
	return true;
}

FT_Error Object_font::LoadAndDecorateChar(Environment &env, Signal sig,
			unsigned long codeUTF32, size_t idx, const Function *pFuncDeco)
{
	bool transformFlag = (pFuncDeco != NULL);
	FT_Matrix matrix;	// 16.16 fixed float
	matrix.xx = 1 << 16;
	matrix.xy = 0 << 16;
	matrix.yx = 0 << 16;
	matrix.yy = 1 << 16;
	// slanting the font
	if (_slant != 0.) {
		transformFlag = true;
		matrix.xy = static_cast<FT_Fixed>(_slant * (1 << 16));
	}
	// rotating the font
	if (_rotate.deg != 0.) {
		transformFlag = true;
		FT_Matrix matRot;
		int cos16 = static_cast<int>(_rotate.cosNum * (1 << 16));
		int sin16 = static_cast<int>(_rotate.sinNum * (1 << 16));
		matRot.xx = cos16;
		matRot.xy = -sin16;
		matRot.yx = sin16;
		matRot.yy = cos16;
		::FT_Matrix_Multiply(&matRot, &matrix);
	}
	if (_height != 0) {
		FT_Error err = ::FT_Set_Pixel_Sizes(GetFace(),
					static_cast<FT_UInt>(_width), static_cast<FT_UInt>(_height));
		if (err != 0) return err;
	}
	// FT_Load_Char calls FT_Get_Char_Index and FT_Load_Glypy internally.
	if (pFuncDeco == NULL) {
		FT_Error err = ::FT_Load_Char(GetFace(), codeUTF32,
					FT_LOAD_DEFAULT | (transformFlag? FT_LOAD_NO_BITMAP : 0));
		if (err != 0) return err;
	} else {
		ValueList valListArg;
		valListArg.reserve(2);
		valListArg.push_back(Value(codeUTF32));
		valListArg.push_back(Value(idx));
		Args args(valListArg);
		pFuncDeco->Eval(env, sig, args);
	}
	FT_GlyphSlot glyphSlot = GetFace()->glyph;
	if (_strength == 0.) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_NONE) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_COMPOSITE) {
		// nothing to do
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_BITMAP) {
		FT_Pos xStrength = static_cast<FT_Pos>(_strength * (1 << 6)); // 26.6 fixed float
		FT_Pos yStrength = 0;
		FT_Error err = ::FT_Bitmap_Embolden(g_lib, &glyphSlot->bitmap, xStrength, yStrength);
		if (err != 0) return err;
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_OUTLINE) {
		FT_Pos strength = static_cast<FT_Pos>(_strength * (1 << 6)); // 26.6 fixed float
		FT_Error err = ::FT_Outline_Embolden(&glyphSlot->outline, strength);
		if (err != 0) return err;
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
		FT_Error err = ::FT_Render_Glyph(glyphSlot, FT_RENDER_MODE_NORMAL);
		if (err != 0) return err;
		if (_rotate.deg != 0.) {
			double cosNum = _rotate.cosNum;
			double sinNum = -_rotate.sinNum;
			FT_Pos x = glyphSlot->advance.x;
			FT_Pos y = glyphSlot->advance.y;
			glyphSlot->advance.x = static_cast<FT_Pos>(cosNum * x - sinNum * y);
			glyphSlot->advance.y = static_cast<FT_Pos>(sinNum * x + cosNum * y);
		}
	} else if (glyphSlot->format == FT_GLYPH_FORMAT_PLOTTER) {
		// nothing to do
	}
	return 0;
}

void Object_font::DrawMonoOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset)
{
	const Color &color = _pObjColor->GetColor();
	unsigned char red = color.GetRed();
	unsigned char green = color.GetGreen();
	unsigned char blue = color.GetBlue();
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
	const Color &color = _pObjColor->GetColor();
	unsigned long redFg = color.GetRed();
	unsigned long greenFg = color.GetGreen();
	unsigned long blueFg = color.GetBlue();
	std::auto_ptr<Image::Scanner>
				pScanner(pImage->CreateScanner(x, y, width, height));
	const unsigned char *pLine = buffer + xOffset + yOffset * pitch;
	const unsigned char *pPixel = pLine;
	bool alphaFlag = (pImage->GetFormat() == Image::FORMAT_RGBA);
	for (;;) {
		if (_mode == MODE_Alpha) {
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
		} else { // _mode == MODE_Blend;
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
// Gura interfaces for freetype.font
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
		new Object_font(Object_Face::Reference(pObjFace), new Object_color(env)));
	return ReturnValue(env, sig, args, Value(pObjFont.release()));
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

// freetype.font#drawtext(image:image, x:number, y:number, str:string):map:reduce {block?}
Gura_DeclareMethod(font, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), SYN_markdown, "Draws a text on the image.");
}

Gura_ImplementMethod(font, drawtext)
{
	Object_font *pThis = Object_font::GetThisObj(args);
	Image *pImage = Object_image::GetObject(args, 0)->GetImage();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	const Function *pFuncDeco = NULL;
	if (args.IsBlockSpecified()) {
		pFuncDeco = args.GetBlockFunc(env, sig, GetSymbolForBlock());
		if (pFuncDeco == NULL) return Value::Null;
	}
	if (pThis->DrawOnImage(env, sig, pImage, x, y, str, pFuncDeco)) return Value::Null;
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
	const Function *pFuncDeco = NULL;
	Object_font *pThis = Object_font::GetThisObj(args);
	String str = args.GetStringSTL(0);
	size_t width, height;
	if (!pThis->CalcSize(env, sig, str, width, height, pFuncDeco)) return Value::Null;
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
	const Function *pFuncDeco = NULL;
	Object_font *pThis = Object_font::GetThisObj(args);
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	String str = args.GetStringSTL(2);
	size_t width, height;
	if (!pThis->CalcSize(env, sig, str, width, height, pFuncDeco)) return Value::Null;
	return Value::CreateAsList(env,
			Value(x), Value(y - pThis->GetFace()->ascender / 4),
			Value(width), Value(height));
}

// implementation of class font
Gura_ImplementUserClass(font)
{
	Gura_AssignFunction(font);
	Gura_AssignMethod(font, cleardeco);
	Gura_AssignMethod(font, drawtext);
	Gura_AssignMethod(font, calcsize);
	Gura_AssignMethod(font, calcbbox);
}

}}
