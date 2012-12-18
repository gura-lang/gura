//-----------------------------------------------------------------------------
// Gura freetype module
//-----------------------------------------------------------------------------
#include "Module_freetype.h"

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
// Object_face implementation
//-----------------------------------------------------------------------------
Object_face::~Object_face()
{
	delete _pHandler;
	::FT_Done_Face(_face);
}

Object *Object_face::Clone() const
{
	return NULL; //new Object_face(*this);
}

bool Object_face::DoPropDir(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoPropDir(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(num_faces));
	symbols.insert(Gura_UserSymbol(face_index));
	symbols.insert(Gura_UserSymbol(face_flag_scalable));
	symbols.insert(Gura_UserSymbol(face_flag_fixed_width));
	symbols.insert(Gura_UserSymbol(face_flag_sfnt));
	symbols.insert(Gura_UserSymbol(face_flag_horizontal));
	symbols.insert(Gura_UserSymbol(face_flag_vertical));
	symbols.insert(Gura_UserSymbol(face_flag_kerning));
	symbols.insert(Gura_UserSymbol(face_flag_fast_glyphs));
	symbols.insert(Gura_UserSymbol(face_flag_multiple_masters));
	symbols.insert(Gura_UserSymbol(face_flag_glyph_names));
	symbols.insert(Gura_UserSymbol(face_flag_external_stream));
	symbols.insert(Gura_UserSymbol(face_flag_hinter));
	symbols.insert(Gura_UserSymbol(face_flag_cid_keyed));
	symbols.insert(Gura_UserSymbol(face_flag_tricky));
	symbols.insert(Gura_UserSymbol(style_flag_italic));
	symbols.insert(Gura_UserSymbol(style_flag_bold));
	symbols.insert(Gura_UserSymbol(family_name));
	symbols.insert(Gura_UserSymbol(style_name));
	symbols.insert(Gura_UserSymbol(bbox));
	symbols.insert(Gura_UserSymbol(ascender));
	symbols.insert(Gura_UserSymbol(descender));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_face::DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	double y_ppem = _face->size->metrics.y_ppem;// pixels/EM
	double units_per_EM = _face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (pSymbol->IsIdentical(Gura_UserSymbol(num_faces))) {
		return Value(_face->num_faces);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_index))) {
		return Value(_face->face_index);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_scalable))) {
		return Value((_face->face_flags & FT_FACE_FLAG_SCALABLE)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_fixed_width))) {
		return Value((_face->face_flags & FT_FACE_FLAG_FIXED_WIDTH)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_sfnt))) {
		return Value((_face->face_flags & FT_FACE_FLAG_SFNT)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_horizontal))) {
		return Value((_face->face_flags & FT_FACE_FLAG_HORIZONTAL)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_vertical))) {
		return Value((_face->face_flags & FT_FACE_FLAG_VERTICAL)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_kerning))) {
		return Value((_face->face_flags & FT_FACE_FLAG_KERNING)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_fast_glyphs))) {
		return Value((_face->face_flags & FT_FACE_FLAG_FAST_GLYPHS)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_multiple_masters))) {
		return Value((_face->face_flags & FT_FACE_FLAG_MULTIPLE_MASTERS)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_glyph_names))) {
		return Value((_face->face_flags & FT_FACE_FLAG_GLYPH_NAMES)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_external_stream))) {
		return Value((_face->face_flags & FT_FACE_FLAG_EXTERNAL_STREAM)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_hinter))) {
		return Value((_face->face_flags & FT_FACE_FLAG_HINTER)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_cid_keyed))) {
		return Value::Null;
		//return Value((_face->face_flags & FT_FACE_FLAG_CID_KEYED)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flag_tricky))) {
		return Value::Null;
		//return Value((_face->face_flags & FT_FACE_FLAG_TRICKY)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_flag_italic))) {
		return Value((_face->style_flags & FT_STYLE_FLAG_ITALIC)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_flag_bold))) {
		return Value((_face->style_flags & FT_STYLE_FLAG_BOLD)? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(family_name))) {
		return Value(env, _face->family_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_name))) {
		if (_face->style_name == NULL) return Value::Null;
		return Value(env, _face->style_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bbox))) {
		return Value::CreateAsList(env,
				Value(_face->bbox.xMin), Value(_face->bbox.yMin),
				Value(_face->bbox.xMax), Value(_face->bbox.yMax));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ascender))) {	// fontUnits
		return Value(_face->ascender * y_ppem / units_per_EM);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(descender))) {	// fontUnits
		return Value(_face->descender * y_ppem / units_per_EM);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {		// fontUnits
		return Value(_face->height * y_ppem / units_per_EM);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_face::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<freetype.face";
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

bool Object_face::Initialize(Signal sig, const char *pathName, int index)
{
	FT_Error err = ::FT_New_Face(g_lib, pathName, index, &_face);
	if (err) {
		sig.SetError(ERR_IOError, "error occurs in FT_New_Face()");
		return false;
	}
	return true;
}

bool Object_face::Initialize(Signal sig, Stream *pStream, int index)
{
	_pHandler = new Handler(sig, Stream::Reference(pStream));
	return _pHandler->OpenFace(sig, index, &_face);
}

bool Object_face::SetPixelSizes(Signal sig, size_t width, size_t height)
{
	FT_Error err = ::FT_Set_Pixel_Sizes(_face,
				static_cast<FT_UInt>(width), static_cast<FT_UInt>(height));
	if (err) {
		sig.SetError(ERR_IOError, "error occurs in FT_Set_Pixel_Sizes()");
		return false;
	}
	return true;
}

bool Object_face::CalcSize(Signal sig, const String &str, size_t &width, size_t &height)
{
	int x = 0, y = 0;
	String::const_iterator p = str.begin();
	int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
	do {
		unsigned long codeUTF32;
		p = Gura::NextUTF32(str, p, codeUTF32);
		if (codeUTF32 == 0x00000000) break;
		FT_GlyphSlot slot = LoadChar(codeUTF32);
		if (slot == NULL) continue;
		FT_Bitmap &bitmap = slot->bitmap;
		int xLeft = x + slot->bitmap_left;
		int yTop = y - slot->bitmap_top;
		int xRight = xLeft + bitmap.width;
		int yBottom = yTop + bitmap.rows;
		if (xMin > xLeft) xMin = xLeft;
		if (xMax < xRight) xMax = xRight;
		if (yMin > yTop) yMin = yTop;
		if (yMax < yBottom) yMax = yBottom;
		x += slot->advance.x >> 6;	// 26.6 fixed float
		y += slot->advance.y >> 6;	// 26.6 fixed float
	} while (p != str.end());
	width = xMax - xMin, height = yMax - yMin;
	return true;
}

bool Object_face::DrawOnImage(Signal sig,
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
		FT_GlyphSlot slot = LoadChar(codeUTF32);
		if (slot == NULL) continue;
		if (slot->format == FT_GLYPH_FORMAT_BITMAP) {
			FT_Bitmap &bitmap = slot->bitmap;
			int xOrg = x + slot->bitmap_left;
			int yOrg = y - slot->bitmap_top;
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
		x += slot->advance.x >> 6;	// 26.6 fixed float
		y += slot->advance.y >> 6;	// 26.6 fixed float
	} while (p != str.end());
	return true;
}

FT_GlyphSlot Object_face::LoadChar(unsigned long codeUTF32)
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
	FT_GlyphSlot slot = _face->glyph;
	if (_deco.strength == 0.) {
		// nothing to do
	} else if (slot->format == FT_GLYPH_FORMAT_NONE) {
		// nothing to do
	} else if (slot->format == FT_GLYPH_FORMAT_COMPOSITE) {
		// nothing to do
	} else if (slot->format == FT_GLYPH_FORMAT_BITMAP) {
		FT_Pos xStrength = static_cast<FT_Pos>(_deco.strength * (1 << 6)); // 26.6 fixed float
		FT_Pos yStrength = 0;
		err = ::FT_Bitmap_Embolden(g_lib, &slot->bitmap, xStrength, yStrength);
		if (err) return NULL;
	} else if (slot->format == FT_GLYPH_FORMAT_OUTLINE) {
		FT_Pos strength = static_cast<FT_Pos>(_deco.strength * (1 << 6)); // 26.6 fixed float
		err = ::FT_Outline_Embolden(&slot->outline, strength);
		if (err) return NULL;
	} else if (slot->format == FT_GLYPH_FORMAT_PLOTTER) {
		// nothing to do
	}
	if (slot->format == FT_GLYPH_FORMAT_NONE) {
		// nothing to do
	} else if (slot->format == FT_GLYPH_FORMAT_COMPOSITE) {
		// nothing to do
	} else if (slot->format == FT_GLYPH_FORMAT_BITMAP) {
		// nothing to do
	} else if (slot->format == FT_GLYPH_FORMAT_OUTLINE) {
		if (transformFlag) {
			::FT_Outline_Transform(&slot->outline, &matrix);
		}
		// convert outline to bitmap
		err = ::FT_Render_Glyph(slot, FT_RENDER_MODE_NORMAL);
		if (err) return NULL;
		if (_deco.rotate.sinNum != 0.) {
			double cosNum = _deco.rotate.cosNum;
			double sinNum = -_deco.rotate.sinNum;
			FT_Pos x = slot->advance.x, y = slot->advance.y;
			slot->advance.x = static_cast<FT_Pos>(cosNum * x - sinNum * y);
			slot->advance.y = static_cast<FT_Pos>(sinNum * x + cosNum * y);
		}
	} else if (slot->format == FT_GLYPH_FORMAT_PLOTTER) {
		// nothing to do
	}
	return slot;
}

void Object_face::DrawMonoOnImage(Object_image *pObjImage, int x, int y,
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

void Object_face::DrawGrayOnImage(Object_image *pObjImage, int x, int y,
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
// Gura interfaces for Object_face
//-----------------------------------------------------------------------------
// freetype.face#setcolor(color:color)
Gura_DeclareMethod(face, setcolor)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(face, setcolor)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	pSelf->SetColor(args.GetColorObj(0)->GetColor());
	return args.GetSelf();
}

// freetype.face#setalpha(alpha:number)
Gura_DeclareMethod(face, setalpha)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementMethod(face, setalpha)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	pSelf->SetAlpha(args.GetUChar(0));
	return args.GetSelf();
}

// freetype.face#setstrength(strength:number)
Gura_DeclareMethod(face, setstrength)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(face, setstrength)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	pSelf->SetStrength(args.GetDouble(0));
	return args.GetSelf();
}

// freetype.face#setslant(slant:number)
Gura_DeclareMethod(face, setslant)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "slant", VTYPE_number);
}

Gura_ImplementMethod(face, setslant)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	pSelf->SetSlant(args.GetDouble(0));
	return args.GetSelf();
}

// freetype.face#setrotate(degree:number)
Gura_DeclareMethod(face, setrotate)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "degree", VTYPE_number);
}

Gura_ImplementMethod(face, setrotate)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	pSelf->SetRotate(args.GetDouble(0));
	return args.GetSelf();
}

// freetype.face#setsize(width:number, height:number)
Gura_DeclareMethod(face, setsize)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(face, setsize)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	if (!pSelf->SetPixelSizes(sig, args.GetSizeT(0), args.GetSizeT(1))) return Value::Null;
	return args.GetSelf();
}

// freetype.face#setheight(height:number)
Gura_DeclareMethod(face, setheight)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(face, setheight)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	if (!pSelf->SetPixelSizes(sig, 0, args.GetSizeT(0))) return Value::Null;
	return args.GetSelf();
}

// freetype.face#cleardeco()
Gura_DeclareMethod(face, cleardeco)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(face, cleardeco)
{
	Object_face *pSelf = Object_face::GetSelfObj(args);
	pSelf->ClearDeco();
	return args.GetSelf();
}

// freetype.face#drawtext(image:image, x:number, y:number, str:string):map:reduce
Gura_DeclareMethod(face, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	SetHelp("Draws a text on the image.");
}

Gura_ImplementMethod(face, drawtext)
{
	Object_face *pObjFace = Object_face::GetSelfObj(args);
	Object_image *pObjImage = Object_image::GetObject(args, 0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	if (pObjFace->DrawOnImage(sig, pObjImage, x, y, str)) return Value::Null;
	return args.GetSelf();
}

// freetype.face#calcsize(str:string):map
Gura_DeclareMethod(face, calcsize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementMethod(face, calcsize)
{
	Object_face *pObjFace = Object_face::GetSelfObj(args);
	String str = args.GetStringSTL(0);
	size_t width, height;
	if (!pObjFace->CalcSize(sig, str, width, height)) return Value::Null;
	return Value::CreateAsList(env, 
			Value(static_cast<unsigned int>(width)),
			Value(static_cast<unsigned int>(height)));
}

// freetype.face#calcbbox(x:number, y:number, str:string):map
Gura_DeclareMethod(face, calcbbox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
}

// ******************* still buggy
Gura_ImplementMethod(face, calcbbox)
{
	Object_face *pObjFace = Object_face::GetSelfObj(args);
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
Gura_ImplementUserClass(face)
{
	Gura_AssignMethod(face, setcolor);
	Gura_AssignMethod(face, setalpha);
	Gura_AssignMethod(face, setstrength);
	Gura_AssignMethod(face, setslant);
	Gura_AssignMethod(face, setrotate);
	Gura_AssignMethod(face, setsize);
	Gura_AssignMethod(face, setheight);
	Gura_AssignMethod(face, cleardeco);
	Gura_AssignMethod(face, drawtext);
	Gura_AssignMethod(face, calcsize);
	Gura_AssignMethod(face, calcbbox);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing freetype module.
//-----------------------------------------------------------------------------
// image#drawtext(face:freetype.face, x:number, y:number, str:string):map:reduce
Gura_DeclareMethod(image, drawtext)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "face", VTYPE_face);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "str", VTYPE_string);
	SetHelp("Draws a text on the image.");
}

Gura_ImplementMethod(image, drawtext)
{
	Object_image *pObjImage = Object_image::GetSelfObj(args);
	Object_face *pObjFace = Object_face::GetObject(args, 0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	String str = args.GetStringSTL(3);
	if (pObjFace->DrawOnImage(sig, pObjImage, x, y, str)) return Value::Null;
	return args.GetSelf();
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
	FT_GlyphSlot slot = face->glyph;
	FT_ULong codeUTF32 = 0x00000000;
	//FT_UInt glyph_index = ::FT_Get_Char_Index(face, codeUTF32);
	//err = ::FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
	//err = ::FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
	err = ::FT_Load_Char(face, codeUTF32, FT_LOAD_RENDER);
	FT_Bitmap &bitmap = slot->bitmap;
	bitmap.rows;
	bitmap.width;
	bitmap.pitch;
	bitmap.buffer;
	slot->bitmap_left;
	slot->bitmap_top;
	slot->advance.x;
	slot->advance.y;
	//err = ::FT_New_Memory_Face(g_lib, buffer, size, 0, &face);
	//FT_Open_Args args;
	//err = ::FT_Open_Face(g_lib, &args, face_index, &face);
	::FT_Done_Face(face);
	return Value::Null;
#endif

// freetype.face(stream:stream, index:number => 0):map
Gura_DeclareFunction(face)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "index", VTYPE_number,
						OCCUR_Once, FLAG_None, new Expr_Value(0));
	SetClassToConstruct(Gura_UserClass(face));
}

Gura_ImplementFunction(face)
{
	AutoPtr<Stream> pStream(Stream::Reference(&args.GetStream(0)));
	int index = args.GetInt(1);
	if (!pStream->IsBwdSeekable()) {
		pStream.reset(Stream::Prefetch(sig, pStream.release(), true));
		if (sig.IsSignalled()) return Value::Null;
	}
	AutoPtr<Object_face> pObjFace(new Object_face());
	pObjFace->Initialize(sig, pStream.release(), index);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObjFace.release());
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
	Gura_RealizeUserSymbol(num_faces);
	Gura_RealizeUserSymbol(face_index);
	Gura_RealizeUserSymbol(face_flag_scalable);
	Gura_RealizeUserSymbol(face_flag_fixed_width);
	Gura_RealizeUserSymbol(face_flag_sfnt);
	Gura_RealizeUserSymbol(face_flag_horizontal);
	Gura_RealizeUserSymbol(face_flag_vertical);
	Gura_RealizeUserSymbol(face_flag_kerning);
	Gura_RealizeUserSymbol(face_flag_fast_glyphs);
	Gura_RealizeUserSymbol(face_flag_multiple_masters);
	Gura_RealizeUserSymbol(face_flag_glyph_names);
	Gura_RealizeUserSymbol(face_flag_external_stream);
	Gura_RealizeUserSymbol(face_flag_hinter);
	Gura_RealizeUserSymbol(face_flag_cid_keyed);
	Gura_RealizeUserSymbol(face_flag_tricky);
	Gura_RealizeUserSymbol(style_flag_italic);
	Gura_RealizeUserSymbol(style_flag_bold);
	Gura_RealizeUserSymbol(family_name);
	Gura_RealizeUserSymbol(style_name);
	Gura_RealizeUserSymbol(bbox);
	Gura_RealizeUserSymbol(ascender);
	Gura_RealizeUserSymbol(descender);
	Gura_RealizeUserSymbol(height);
	// class realization
	Gura_RealizeUserClass(face, env.LookupClass(VTYPE_object));
	// method assignment to image type
	Gura_AssignMethodTo(VTYPE_image, image, drawtext);
	// function assignment
	Gura_AssignFunction(test);
	Gura_AssignFunction(face);
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
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_FONTS, NULL, 0, pathName))) {
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
