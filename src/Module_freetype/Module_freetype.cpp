//-----------------------------------------------------------------------------
// Gura freetype module
//-----------------------------------------------------------------------------
#include "Module_freetype.h"

#define Gura_AssignRawValue(name) \
Gura_AssignValue(name, Value(static_cast<double>(name)))

#define Gura_AssignFTValue(name) \
Gura_AssignValue(name, Value(static_cast<double>(FT_##name)))

Gura_BeginModule(freetype)

static FT_Library g_lib;

static String GetSysFontPathName();

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
	if (err) {
		sig.SetError(ERR_IOError, "font open error");
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
// Object_Vector implementation
//-----------------------------------------------------------------------------
Object *Object_Vector::Clone() const
{
	return NULL;
}

String Object_Vector::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Vector:x=%d,y=%d>", _vector.x, _vector.y);
	return String(buff);
}

bool Object_Vector::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_Vector::DoGetProp(Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vector.y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Vector::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Vector
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Vector)
{
}

//-----------------------------------------------------------------------------
// Object_BBox implementation
//-----------------------------------------------------------------------------
Object *Object_BBox::Clone() const
{
	return NULL;
}

String Object_BBox::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.BBox:xMin=%d,yMin=%d,xMax=%d,yMax=%d>",
						_bbox.xMin, _bbox.yMin, _bbox.xMax, _bbox.yMax);
	return String(buff);
}

bool Object_BBox::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(xMin));
	symbols.insert(Gura_UserSymbol(yMin));
	symbols.insert(Gura_UserSymbol(xMax));
	symbols.insert(Gura_UserSymbol(yMax));
	return true;
}

Value Object_BBox::DoGetProp(Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xMin))) {
		return Value(_bbox.xMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMin))) {
		return Value(_bbox.yMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xMax))) {
		return Value(_bbox.xMax);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMax))) {
		return Value(_bbox.yMax);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_BBox::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xMin))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.xMin = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.xMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMin))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.yMin = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.yMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xMax))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.xMax = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.xMax);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMax))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.yMax = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.yMax);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.BBox
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(BBox)
{
}

//-----------------------------------------------------------------------------
// Object_Matrix implementation
//-----------------------------------------------------------------------------
Object *Object_Matrix::Clone() const
{
	return NULL;
}

String Object_Matrix::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Matrix:xx=%d,xy=%d,yx=%d,yy=%d>",
					_matrix.xx, _matrix.xy, _matrix.yx, _matrix.yy);
	return String(buff);
}

bool Object_Matrix::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(xx));
	symbols.insert(Gura_UserSymbol(xy));
	symbols.insert(Gura_UserSymbol(yx));
	symbols.insert(Gura_UserSymbol(yy));
	return true;
}

Value Object_Matrix::DoGetProp(Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xx))) {
		return Value(_matrix.xx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xy))) {
		return Value(_matrix.xy);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yx))) {
		return Value(_matrix.yx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yy))) {
		return Value(_matrix.yy);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Matrix::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xx))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.xx = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.xx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xy))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.xy = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.xy);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yx))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.yx = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.yx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yy))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.yy = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.yy);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Matrix
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Matrix)
{
}

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

bool Object_Face::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
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

Value Object_Face::DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Environment &env = *this;
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

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing freetype module.
//-----------------------------------------------------------------------------
// image#drawtext(face:freetype.Face, x:number, y:number, str:string):map:reduce
Gura_DeclareMethod(image, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "face", VTYPE_Face);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Draws a text on the image.");
}

Gura_ImplementMethod(image, drawtext)
{
	Object_image *pObjImage = Object_image::GetThisObj(args);
	Object_Face *pObjFace = Object_Face::GetObject(args, 0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	if (pObjFace->DrawOnImage(sig, pObjImage, x, y, str)) return Value::Null;
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
	//Handler handler(sig, args.GetStream(0));
	//FT_Face face;
	//handler.OpenFace(sig, 0, &face);
	//printf("%s\n", face->family_name);
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

// freetype.New_Face(stream:stream, face_index:number => 0):map {block?}
Gura_DeclareFunction(New_Face)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "face_index", VTYPE_number,
						OCCUR_Once, FLAG_None, new Expr_Value(0));
	//SetClassToConstruct(Gura_UserClass(Face));
}

Gura_ImplementFunction(New_Face)
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

// freetype.sysfontpath(name?:string):map
Gura_DeclareFunction(sysfontpath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(sysfontpath)
{
	const char *name = args.IsString(0)? args.GetString(0) : "";
	return Value(env, OAL::JoinPathName(GetSysFontPathName().c_str(), name).c_str());
}

// Module entry
Gura_ModuleEntry()
{
	::FT_Init_FreeType(&g_lib);
	// symbol realization
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
	Gura_RealizeUserSymbol(height);
	Gura_RealizeUserSymbol(max_advance_width);
	Gura_RealizeUserSymbol(max_advance_height);
	Gura_RealizeUserSymbol(underline_position);
	Gura_RealizeUserSymbol(underline_thickness);
	Gura_RealizeUserSymbol(glyph);
	Gura_RealizeUserSymbol(size);
	Gura_RealizeUserSymbol(charmap);
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
	// FT_AUTOHINTER_SCRIPT_XXX
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_CJK);
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_INDIC);
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_LATIN);
	Gura_AssignFTValue(AUTOHINTER_SCRIPT_NONE);
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
	Gura_AssignFTValue(STROKER_LINEJOIN_MITER_VARIABLE);
	Gura_AssignFTValue(STROKER_LINEJOIN_MITER);
	Gura_AssignFTValue(STROKER_LINEJOIN_MITER_FIXED);
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
	Gura_RealizeUserClass(Vector, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(BBox, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Matrix, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Face, env.LookupClass(VTYPE_object));
	// method assignment to image type
	Gura_AssignMethodTo(VTYPE_image, image, drawtext);
	// function assignment
	Gura_AssignFunction(test);
	Gura_AssignFunction(New_Face);
	Gura_AssignFunction(sysfontpath);
}

Gura_ModuleTerminate()
{
	::FT_Done_FreeType(g_lib);
}

#if defined(HAVE_WINDOWS_H)
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


Gura_EndModule(freetype, freetype)

Gura_RegisterModule(freetype)
