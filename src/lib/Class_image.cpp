//=============================================================================
// Gura class: image
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_image
//-----------------------------------------------------------------------------
Object_image::Object_image(Environment &env, Image *pImage) :
					Object(env.LookupClass(VTYPE_image)), _pImage(pImage)
{
}

Object_image::Object_image(Class *pClass, Image *pImage) :
					Object(pClass), _pImage(pImage)
{
}

Object_image::Object_image(const Object_image &obj) :
					Object(obj), _pImage(new Image(*obj.GetImage()))
{
}

Object *Object_image::Clone() const
{
	return new Object_image(*this);
}

bool Object_image::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(height));
	symbols.insert(Gura_Symbol(palette));
	symbols.insert(Gura_Symbol(width));
	return true;
}

Value Object_image::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(GetImage()->FormatToSymbol(GetImage()->GetFormat()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		return Value(static_cast<UInt>(GetImage()->GetHeight()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(palette))) {
		const Palette *pPalette = GetImage()->GetPalette();
		if (pPalette == NULL) return Value::Null;
		return Value(new Object_palette(env, Palette::Reference(pPalette)));
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		return Value(static_cast<UInt>(GetImage()->GetWidth()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_image::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(palette))) {
		if (value.Is_palette()) {
			GetImage()->SetPalette(Palette::Reference(Object_palette::GetObject(value)->GetPalette()));
			return value;
		} else if (value.IsInvalid()) {
			GetImage()->SetPalette(NULL);
			return Value::Null;
		} else {
			sig.SetError(ERR_ValueError, "palette object must be specified");
			return Value::Null;
		}
	}
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_image::ToString(bool exprFlag)
{
	String rtn;
	rtn = "<image:";
	rtn += GetImage()->FormatToSymbol(GetImage()->GetFormat())->GetName();
	rtn += ":";
	if (GetImage()->IsValid()) {
		char buff[64];
		::sprintf(buff, "%dx%d",
				static_cast<int>(GetImage()->GetWidth()), static_cast<int>(GetImage()->GetHeight()));
		rtn += buff;
	} else {
		rtn += "invalid";
	}
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// image(args+):map {block?}
Gura_DeclareFunction(image)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_image));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns an image instance with specified characteristics.\n"
		"There are three forms to call the function as below:\n"
		"\n"
		"- `image(format:symbol)` ..\n"
		"  Creates an image instance of the specified format without buffer allocated.\n"
		"- `image(format:symbol, width:number, height:number, color?:color)` ..\n"
		"  Allocates an image buffer with the specified size and fills it with the color.\n"
		"- `image(stream:stream, format?:symbol, imagetype?:string)` ..\n"
		"  Reads image data from the stream and allocates necessary buffer\n"
		"  in which the read data is stored.\n"
		"\n"
		"The argument `format` specifies what elements are stored in the memory\n"
		"and takes one of the following symbols:\n"
		"\n"
		"- `` `rgb`` .. red, green and blue\n"
		"- `` `rgba`` .. red, green, blue and alpha\n"
		"\n"
		"In the third form, the format of the image data is determined\n"
		"by the byte sequence of the stream data and its file name.\n"
		"\n"
		"You can also explicitly specify the image data format by the argument `imagetype`.\n");
}

Gura_ImplementFunction(image)
{
	if (sig.IsSignalled()) return Value::Null;
	ValueList valList = args.GetList(0);
	AutoPtr<Image> pImage;
	if (valList[0].Is_symbol()) {
		AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(format), VTYPE_symbol));
		pDecl->ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Image::Format format =
					Image::SymbolToFormat(sig, valList[0].GetSymbol());
		if (sig.IsSignalled()) return Value::Null;
		pImage.reset(new Image(format));
		if (valList.size() >= 2) {
			AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(width), VTYPE_number));
			pDecl->ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			size_t width = valList[1].GetSizeT();
			size_t height = width;
			if (valList.size() >= 3) {
				AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(height), VTYPE_number));
				pDecl->ValidateAndCast(env, sig, valList[2]);
				if (sig.IsSignalled()) return Value::Null;
				height = valList[2].GetSizeT();
			}
			if (!pImage->AllocBuffer(sig, width, height, 0x00)) return Value::Null;
			if (valList.size() >= 4) {
				AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(color), VTYPE_color));
				pDecl->ValidateAndCast(env, sig, valList[3]);
				if (sig.IsSignalled()) return Value::Null;
				pImage->Fill(Object_color::GetObject(valList[3])->GetColor());
			}
		}
	} else {
		AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(stream), VTYPE_stream, OCCUR_Once, FLAG_Read, NULL));
		pDecl->ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Stream &stream = valList[0].GetStream();
		Image::Format format = Image::FORMAT_RGBA;
		if (valList.size() >= 2) {
			AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(format), VTYPE_symbol));
			pDecl->ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			format = Image::SymbolToFormat(sig, valList[1].GetSymbol());
			if (sig.IsSignalled()) return Value::Null;
		}
		pImage.reset(new Image(format));
		const char *imageType = NULL;
		if (valList.size() >= 3) {
			AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(imagetype), VTYPE_string));
			pDecl->ValidateAndCast(env, sig, valList[2]);
			if (sig.IsSignalled()) return Value::Null;
			imageType = valList[2].GetString();
		}
		if (!pImage->Read(env, sig, stream, imageType)) return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// image#allocbuff(width:number, height:number, color?:color):reduce
Gura_DeclareMethod(image, allocbuff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Allocates a specified size of buffer in the `image` instance\n"
		"that is supposed to has no buffer allocated.\n"
		"\n"
		"The allocated buffer will be filled with `color`.\n"
		"If omitted, it will be filled with zero value.\n"
		"\n"
		"An error occurs in following cases:\n"
		"\n"
		"- It fails to allocate necessary buffer.\n"
		"- The `image` instance already has allocated buffer.\n");
}

Gura_ImplementMethod(image, allocbuff)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckEmpty(sig)) return Value::Null;
	pThis->GetImage()->AllocBuffer(sig, args.GetSizeT(0), args.GetSizeT(1), 0x00);
	if (args.Is_color(2)) pThis->GetImage()->Fill(Object_color::GetObject(args, 2)->GetColor());
	return args.GetThis();
}

// image#blur(radius:number, sigma:number) {block?}
Gura_DeclareMethod(image, blur)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "radius", VTYPE_number);
	DeclareArg(env, "sigma", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a new image that blurs the original image with the given parameters.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, blur)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	int radius = args.GetInt(0);
	Number sigma = args.Is_number(1)? args.GetNumber(1) : 1.5;
	AutoPtr<Image> pImage(pThis->GetImage()->Blur(sig, radius, sigma));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#clear():reduce
Gura_DeclareMethod(image, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Fills the buffer in the `image` instance with zero value.\n"
		"\n"
		"This has the same effect with calling `image#fill()` with `color.zero`.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, clear)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	pThis->GetImage()->Fill(Color::zero);
	return args.GetThis();
}

// image#crop(x:number, y:number, width?:number, height?:number):map {block?}
Gura_DeclareMethod(image, crop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a new image instance of the extracted area of the source image.\n"
		"\n"
		"The extracted area is specified by the following arguments:\n"
		"\n"
		"- `x` .. The left position.\n"
		"- `y` .. The top position.\n"
		"- `width` .. The width. If it's omitted or specified with `nil`,\n"
		"             the whole area on the right of `x` will be extracted.\n"
		"- `height` .. The height. If it's omitted or specified with `nil`,\n"
		"             the whole area on the bottom of `y` will be extracted.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, crop)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0);
	size_t y = args.GetSizeT(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	size_t width = args.Is_number(2)? args.GetSizeT(2) : pThis->GetImage()->GetWidth() - x;
	size_t height = args.Is_number(3)? args.GetSizeT(3) : pThis->GetImage()->GetHeight() - y;
	if (!pThis->GetImage()->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	AutoPtr<Image> pImage(pThis->GetImage()->Crop(sig, x, y, width, height));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#delpalette():reduce
Gura_DeclareMethod(image, delpalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Deletes a `palette` instance the image owns if it does.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, delpalette)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	pThis->GetImage()->SetPalette(NULL);
	return args.GetThis();
}

// image#extract(x:number, y:number, width:number, height:number, element:symbol, dst):reduce
Gura_DeclareMethod(image, extract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "element", VTYPE_symbol);
	DeclareArg(env, "dst", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Extracts the element values within the specified area of the image,\n"
		"and store them into a list or matrix.\n"
		"The argument `x` and `y` specifies the left-top position,\n"
		"and `width`, and `height` does the size of the area.\n"
		"\n"
		"The argument `element` takes the following symbol\n"
		"that specifies which element should be extracted:\n"
		"\n"
		"- `` `r`` .. red\n"
		"- `` `g`` .. green\n"
		"- `` `b`` .. blue\n"
		"- `` `a`` .. alpha\n"
		"\n"
		"The argument `dst` specifies the variable into which the extracted data is stored,\n"
		"which must be a list or matrix that has enough space to store the data.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, extract)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0), y = args.GetSizeT(1);
	size_t width = args.GetSizeT(2), height = args.GetSizeT(3);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	if (!pThis->GetImage()->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	const Symbol *pSymbol = args.GetSymbol(4);
	if (args.Is_matrix(5)) {
		pThis->GetImage()->Extract(sig, x, y, width, height,
					pSymbol, Object_matrix::GetObject(args, 5)->GetMatrix());
	} else if (args.Is_list(5)) {
		pThis->GetImage()->Extract(sig, x, y, width, height,
					pSymbol, Object_list::GetObject(args, 5)->GetList());
	} else {
		sig.SetError(ERR_ValueError, "invalid object for image's destination");
		return Value::Null;
	}
	return args.GetThis();
}

// image#fill(color:color):reduce
Gura_DeclareMethod(image, fill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Fills the whole image with the specified color.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, fill)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	pThis->GetImage()->Fill(Object_color::GetObject(args, 0)->GetColor());
	return args.GetThis();
}

// image#fillrect(x:number, y:number, width:number, height:number, color:color):map:reduce
Gura_DeclareMethod(image, fillrect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Fills the specified area with the specified color."
		"\n"
		"The argument `x` and `y` specifies the left-top position,\n"
		"and `width`, and `height` does the size of the area.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, fillrect)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	int width = args.GetInt(2), height = args.GetInt(3);
	if (!pThis->GetImage()->AdjustCoord(x, y, width, height)) return Value::Null;
	pThis->GetImage()->FillRect(x, y, width, height, Object_color::GetObject(args, 4)->GetColor());
	return args.GetThis();
}

// image#flip(orient:symbol):map {block?}
Gura_DeclareMethod(image, flip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orient", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a new `image` instance that flips the source image horizontally or vertically.\n"
		"You can specify the following symbol to the `orient` argument.\n"
		"\n"
		"- `` `horz`` .. flips horizontally.\n"
		"- `` `vert`` .. flips vertically.\n"
		"- `` `both`` .. flips both horizontally and vertically. This has the same effect with\n"
		"            rotating the image 180 degrees.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, flip)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	const Symbol *pSymbol = args.GetSymbol(0);
	bool horzFlag = false, vertFlag = false;
	if (pSymbol->IsIdentical(Gura_Symbol(horz))) {
		horzFlag = true;
	} else if (pSymbol->IsIdentical(Gura_Symbol(vert))) {
		vertFlag = true;
	} else if (pSymbol->IsIdentical(Gura_Symbol(both))) {
		horzFlag = vertFlag = true;
	} else {
		sig.SetError(ERR_ValueError, "orient must be one of `horz or `vert");
		return Value::Null;
	}
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	AutoPtr<Image> pImage(pThis->GetImage()->Flip(sig, horzFlag, vertFlag));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#getpixel(x:number, y:number):map {block?}
Gura_DeclareMethod(image, getpixel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a color of a pixel data at the specified position.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("c", "color"));
}

Gura_ImplementMethod(image, getpixel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	UChar *p = pThis->GetImage()->GetPointer(x, y);
	Color color;
	pThis->GetImage()->GetPixel(p, color);
	return ReturnValue(env, sig, args, Value(new Object_color(env, color)));
}

// image#grayscale() {block?}
Gura_DeclareMethod(image, grayscale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a new image instance that converts the source image into gray scale.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, grayscale)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	AutoPtr<Image> pImage(pThis->GetImage()->GrayScale(sig));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#mapcolorlevel(map@r[]:number, map@g?[]:number, map@b?[]:number) {block?}
Gura_DeclareMethod(image, mapcolorlevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "map@r", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "map@g", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareArg(env, "map@b", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a new image that converts color levels according to the given table.\n"
		"\n"
		"Each of the arguments `map@r`, `map@g` and `map@b` is a list\n"
		"containing 256 numbers between 0 and 255\n"
		"and corresponds to elements red, green and blue respectively.\n"
		"An element value in the source image becomes an index of the list\n"
		"and the indexed value will be stored as a converted element value.\n"
		"\n"
		"If you want to apply a mapping table to all the elements,\n"
		"call the method with a single argument like `image#mapcolorlevel(map)`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

UChar *ValueListToMapTable(Signal sig, const ValueList &valList)
{
	if (valList.size() != 256) {
		sig.SetError(ERR_ValueError, "the list of map table must contain %d elements");
		return NULL;
	}
	UChar *mapBuff = new UChar[256];
	UChar *p = mapBuff;
	foreach_const (ValueList, pValue, valList) {
		*p++ = pValue->GetUChar();
	}
	return mapBuff;
}

Gura_ImplementMethod(image, mapcolorlevel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	UChar *mapBuffR = ValueListToMapTable(sig, args.GetList(0));
	if (mapBuffR == NULL) return Value::Null;
	UChar *mapBuffG = NULL;
	UChar *mapBuffB = NULL;
	const UChar *mapR = mapBuffR;
	const UChar *mapG = mapBuffR;
	const UChar *mapB = mapBuffR;
	if (args.IsValid(1)) {
		mapBuffG = ValueListToMapTable(sig, args.GetList(1));
		if (mapBuffG == NULL) {
			delete[] mapBuffR;
			return Value::Null;
		}
		mapG = mapBuffG;
		mapB = mapBuffG;
	}
	if (args.IsValid(2)) {
		mapBuffB = ValueListToMapTable(sig, args.GetList(2));
		if (mapBuffB == NULL) {
			delete[] mapBuffR;
			delete[] mapBuffG;
			return Value::Null;
		}
		mapB = mapBuffB;
	}
	AutoPtr<Image> pImage(pThis->GetImage()->MapColorLevel(sig, mapR, mapG, mapB));
	delete[] mapBuffR;
	delete[] mapBuffG;
	delete[] mapBuffB;
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#paste(x:number, y:number, src:image, width?:number, height?:number,
//     xoffset:number => 0, yoffset:number => 0, a:number => 255):map:reduce
Gura_DeclareMethod(image, paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "src", VTYPE_image);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(255));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Pastes the source image `src` onto the target image instance at the specified position.\n"
		"\n"
		"The argument `width`, `height`, `xoffset` and `yoffset` specify\n"
		"the source image's area to be pasted.\n"
		"If they're omitted, the whole image will be pasted.\n"
		"\n"
		"The argument `a` specifies the alpha value that is put on the target image.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, paste)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	Object_image *pObjImg = Object_image::GetObject(args, 2);
	if (!pObjImg->GetImage()->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0);
	size_t y = args.GetSizeT(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	size_t xOffset = args.GetSizeT(5);
	size_t yOffset = args.GetSizeT(6);
	if (!pObjImg->GetImage()->CheckCoord(sig, xOffset, yOffset)) return Value::Null;
	size_t width = args.Is_number(3)?
				args.GetSizeT(3) : pObjImg->GetImage()->GetWidth() - xOffset;
	size_t height = args.Is_number(4)?
				args.GetSizeT(4) : pObjImg->GetImage()->GetHeight() - yOffset;
	if (!pObjImg->GetImage()->CheckCoord(sig, xOffset + width - 1, yOffset + height - 1)) {
		return Value::Null;
	}
	if (x + width > pThis->GetImage()->GetWidth()) width = pThis->GetImage()->GetWidth() - x;
	if (y + height > pThis->GetImage()->GetHeight()) height = pThis->GetImage()->GetHeight() - y;
	UChar a = args.GetUChar(7);
	pThis->GetImage()->Paste(x, y, pObjImg->GetImage(),
							width, height, xOffset, yOffset, a);
	if (sig.IsSignalled()) return Value::Null;
	return args.GetThis();
}

// image#putpixel(x:number, y:number, color:color):map:reduce
Gura_DeclareMethod(image, putpixel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Puts a color on the specified position.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, putpixel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	UChar *p = pThis->GetImage()->GetPointer(x, y);
	pThis->GetImage()->PutPixel(p, Object_color::GetObject(args, 2)->GetColor());
	return args.GetThis();
}

// image#read(stream:stream:r, imagetype?:string):map:reduce
Gura_DeclareMethod(image, read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "imagetype", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads image data from a stream.\n"
		"\n"
		"The format of the image data is determined\n"
		"by the byte sequence of the stream data and its file name.\n"
		"\n"
		"You can also explicitly specify the image data format by the argument `imagetype`.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, read)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->Read(env, sig, args.GetStream(0),
			args.Is_string(1)? args.GetString(1) : NULL)) return Value::Null;
	return args.GetThis();
}

// image#reducecolor(palette?:palette) {block?}
Gura_DeclareMethod(image, reducecolor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "palette", VTYPE_palette, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an image that reduces colors in the original image\n"
		"with a set of colors in the given palette.\n"
		"The specified palette would be associated with the created image.\n"
		"\n"
		"If no argument is specified, the associated palette would be used.\n"
		"In this case, an error occurs if there's no palette associated.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, reducecolor)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	const Palette *pPalette = pThis->GetImage()->GetPalette();
	if (args.Is_palette(0)) {
		pPalette = Object_palette::GetObject(args, 0)->GetPalette();
	} else if (pPalette == NULL) {
		sig.SetError(ERR_ValueError, "palette must be specified");
		return Value::Null;
	}
	AutoPtr<Image> pImage(pThis->GetImage()->ReduceColor(sig, pPalette));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#replacecolor(colorOrg:color, color:color, tolerance?:number):reduce
Gura_DeclareMethod(image, replacecolor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "colorOrg", VTYPE_color);
	DeclareArg(env, "color", VTYPE_color);
	DeclareArg(env, "tolerance", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Replaces pixels that have a color matching `colorOrg` with the `color`.\n"
		"\n"
		"The argument `tolerance` specifies an acceptable distance for the matching.\n"
		"If omitted, only an exact match is acceptable.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, replacecolor)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	double tolerance = args.Is_number(2)? args.GetDouble(2) : 0.;
	pThis->GetImage()->ReplaceColor(Object_color::GetObject(args, 0)->GetColor(),
					Object_color::GetObject(args, 1)->GetColor(), tolerance);
	return args.GetThis();
}

// image#resize(width?:number, height?:number):map:[box,ratio] {block?}
Gura_DeclareMethod(image, resize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(box));
	DeclareAttr(Gura_Symbol(ratio));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an image that resizes the original image to the sprcified `width` and `height`.\n"
		"\n"
		"- When both `width` and `height` are specified, the image would be resized to the size.\n"
		"- When `width` is specified and `height` is omitted or `nil`,\n"
		"  the resized height would be calculated from the width\n"
		"  so that they keep the same ratio as the original.\n"
		"- When `width` is `nil` and `height` is specified,\n"
		"  the resized width would be calculated from the height\n"
		"  so that they keep the same ratio as the original.\n"
		"\n"
		"The following attributes are acceptable:\n"
		"\n"
		"- `box` .. When only `width` is specified, the same value is set to `height`.\n"
		"- `ratio` .. Treats values of `width` and `height` as magnifying ration instead of pixel size.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, resize)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	bool boxFlag = args.IsSet(Gura_Symbol(box));
	bool ratioFlag = args.IsSet(Gura_Symbol(ratio));
	size_t width, height;
	if (!args.Is_number(0) && !args.Is_number(1)) {
		sig.SetError(ERR_ValueError, "width or height must be specified");
		return Value::Null;
	}
	if (args.Is_number(0) && !args.Is_number(1)) {
		if (ratioFlag) {
			width = static_cast<size_t>(pThis->GetImage()->GetWidth() * args.GetDouble(0));
		} else {
			width = args.GetSizeT(0);
		}
		if (boxFlag) {
			height = width;
		} else {
			height = pThis->GetImage()->GetHeight() * width / pThis->GetImage()->GetWidth();
		}
	} else if (!args.Is_number(0) && args.Is_number(1)) {
		if (ratioFlag) {
			height = static_cast<size_t>(pThis->GetImage()->GetHeight() * args.GetDouble(1));
		} else {
			height = args.GetSizeT(1);
		}
		if (boxFlag) {
			width = height;
		} else {
			width = pThis->GetImage()->GetWidth() * height / pThis->GetImage()->GetHeight();
		}
	} else {
		if (ratioFlag) {
			width = static_cast<size_t>(pThis->GetImage()->GetWidth() * args.GetDouble(0));
			height = static_cast<size_t>(pThis->GetImage()->GetHeight() * args.GetDouble(1));
		} else {
			width = args.GetSizeT(0);
			height = args.GetSizeT(1);
		}
	}
	AutoPtr<Image> pImage(pThis->GetImage()->Resize(sig, width, height));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#rotate(angle:number, background?:color):map {block?}
Gura_DeclareMethod(image, rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rotate", VTYPE_number);
	DeclareArg(env, "background", VTYPE_color, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an image that rotates the original image by the specified angle.\n"
		"\n"
		"The argument `angle` specifies the rotation angle in degree unit,\n"
		"and positive numbers for counterclockwise direction and\n"
		"negative for clockwise direction.\n"
		"\n"
		"The created instance has a size that exactly fits the rotated image.\n"
		"The argument `background` specifies the color of pixels to fill\n"
		"the empty area that appears after rotation.\n"
		"If omitted, the color that has all elements set to zero is used for filling.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("img", "image"));
}

Gura_ImplementMethod(image, rotate)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	Color color;
	if (args.Is_color(1)) {
		color = Object_color::GetObject(args, 1)->GetColor();
	}
	AutoPtr<Image> pImage(pThis->GetImage()->Rotate(sig, args.GetNumber(0), color));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// image#scan(x?:number, y?:number, width?:number, height?:number, scandir?:symbol) {block?}
Gura_DeclareMethod(image, scan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "scandir", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator that scans pixels in the image.\n"
		"\n"
		"The arguments `x`, `y`, `width` and `height` specify the image area to scan.\n"
		"The argument `scandir` specifies the scan direction and\n"
		"takes one of the following symbol:\n"
		"\n"
		"<table>\n"
		"<tr><th>Symbol</th><th>Start Pos</th><th>Direction</th></tr>\n"
		"<tr><td><code>`left_top_horz</code></td><td>left-top</td><td>horizontal</td></tr>\n"
		"<tr><td><code>`left_top_vert</code></td><td>left-top</td><td>vertical</td></tr>\n"
		"<tr><td><code>`left_bottom_horz</code></td><td>left-bottom</td><td>horizontal</td></tr>\n"
		"<tr><td><code>`left_bottom_vert</code></td><td>left-bottom</td><td>vertical</td></tr>\n"
		"<tr><td><code>`right_top_horz</code></td><td>right-top</td><td>horizontal</td></tr>\n"
		"<tr><td><code>`right_top_vert</code></td><td>right-top</td><td>vertical</td></tr>\n"
		"<tr><td><code>`right_bottom_horz</code></td><td>right-bottom</td><td>horizontal</td></tr>\n"
		"<tr><td><code>`right_bottom_vert</code></td><td>right-bottom</td><td>vertical</td></tr>\n"
		"</table>\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(image, scan)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	size_t x = args.Is_number(0)? args.GetSizeT(0) : 0;
	size_t y = args.Is_number(1)? args.GetSizeT(1) : 0;
	size_t width = args.Is_number(2)? args.GetSizeT(2) : pThis->GetImage()->GetWidth();
	size_t height = args.Is_number(3)? args.GetSizeT(3) : pThis->GetImage()->GetHeight();
	Image::ScanDir scanDir = Image::SCAN_LeftTopHorz;
	if (args.Is_symbol(4)) {
		scanDir = Image::SymbolToScanDir(args.GetSymbol(4));
		if (scanDir == Image::SCAN_None) {
			sig.SetError(ERR_ValueError, "invalid symbol for scandir");
			return Value::Null;
		}
	}
	Iterator *pIterator = new Image::IteratorScan(
			Image::Reference(pThis->GetImage()), x, y, width, height, scanDir);
	return ReturnIterator(env, sig, args, pIterator);
}

// image#setalpha(a:number, color?:color, tolerance?:number):reduce
Gura_DeclareMethod(image, setalpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tolerance", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(image, setalpha)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	if (pThis->GetImage()->GetFormat() != Image::FORMAT_RGBA) {
		sig.SetError(ERR_ValueError, "only RGBA format contains alpha element");
		return 0;
	}
	if (args.IsValid(1)) {
		double tolerance = args.Is_number(2)? args.GetDouble(2) : 0;
		pThis->GetImage()->FillAlpha(args.GetUChar(0),
					Object_color::GetObject(args, 1)->GetColor(), tolerance);
	} else {
		pThis->GetImage()->FillAlpha(args.GetUChar(0));
	}
	return args.GetThis();
}

// image#size()
Gura_DeclareMethod(image, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the image size as a list `[width, height]`.");
}

Gura_ImplementMethod(image, size)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.push_back(static_cast<int>(pThis->GetImage()->GetWidth()));
	valList.push_back(static_cast<int>(pThis->GetImage()->GetHeight()));
	return result;
}

// image#store(x:number, y:number, width:number, height:number, element:symbol, src):reduce
Gura_DeclareMethod(image, store)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "element", VTYPE_symbol);
	DeclareArg(env, "src", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(image, store)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0), y = args.GetSizeT(1);
	size_t width = args.GetSizeT(2), height = args.GetSizeT(3);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	if (!pThis->GetImage()->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	const Symbol *pSymbol = args.GetSymbol(4);
	if (args.Is_matrix(5)) {
		pThis->GetImage()->Store(sig, x, y, width, height, pSymbol,
							Object_matrix::GetObject(args, 5)->GetMatrix());
	} else if (args.Is_list(5) || args.Is_iterator(5)) {
		AutoPtr<Iterator> pIterator(args.GetValue(5).CreateIterator(sig));
		pThis->GetImage()->Store(env, sig, x, y, width, height, pSymbol, pIterator.get());
	} else {
		sig.SetError(ERR_ValueError, "invalid object for image's source");
		return Value::Null;
	}
	return args.GetThis();
}

// image#thumbnail(width?:number, height?:number):map:[box] {block?}
Gura_DeclareMethod(image, thumbnail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(box));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(image, thumbnail)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	bool boxFlag = args.IsSet(Gura_Symbol(box));
	Object_image *pObj = NULL;
	if (!args.Is_number(0) && !args.Is_number(1)) {
		sig.SetError(ERR_ValueError, "width or height must be specified");
		return Value::Null;
	}
	size_t width = 0, height = 0;
	if (args.Is_number(0) && !args.Is_number(1)) {
		width = args.GetSizeT(0);
		if (boxFlag) {
			height = width;
		} else {
			if (pThis->GetImage()->GetWidth() < width) {
				pObj = dynamic_cast<Object_image *>(pThis->Clone());
			} else {
				height = pThis->GetImage()->GetHeight() * width / pThis->GetImage()->GetWidth();
				AutoPtr<Image> pImage(pThis->GetImage()->Resize(sig, width, height));
				if (sig.IsSignalled()) return Value::Null;
				pObj = new Object_image(env, pImage.release());
			}
			return ReturnValue(env, sig, args, Value(pObj));
		}
	} else if (!args.Is_number(0) && args.Is_number(1)) {
		height = args.GetSizeT(1);
		if (boxFlag) {
			width = height;
		} else {
			if (pThis->GetImage()->GetHeight() < height) {
				pObj = dynamic_cast<Object_image *>(pThis->Clone());
			} else {
				width = pThis->GetImage()->GetWidth() * height / pThis->GetImage()->GetHeight();
				AutoPtr<Image> pImage(pThis->GetImage()->Resize(sig, width, height));
				if (sig.IsSignalled()) return Value::Null;
				pObj = new Object_image(env, pImage.release());
			}
			return ReturnValue(env, sig, args, Value(pObj));
		}
	} else {
		width = args.GetSizeT(0);
		height = args.GetSizeT(1);
	}
	if (pThis->GetImage()->GetWidth() < width && pThis->GetImage()->GetHeight() < height) {
		pObj = dynamic_cast<Object_image *>(pThis->Clone());
	} else {
		size_t widthExp = pThis->GetImage()->GetWidth() * height / pThis->GetImage()->GetHeight();
		if (widthExp <= width) {
			width = widthExp;
		} else {
			height = pThis->GetImage()->GetHeight() * width / pThis->GetImage()->GetWidth();
		}
		AutoPtr<Image> pImage(pThis->GetImage()->Resize(sig, width, height));
		if (sig.IsSignalled()) return Value::Null;
		pObj = new Object_image(env, pImage.release());
	}
	return ReturnValue(env, sig, args, Value(pObj));
}

// image#write(stream:stream:w, imagetype?:string):map:reduce
Gura_DeclareMethod(image, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "imagetype", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes image data to a stream.\n"
		"\n"
		"The format of the image data is determined by the stream's file name.\n"
		"\n"
		"You can also explicitly specify the image data format by the argument `imagetype`.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, write)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->Write(env, sig, args.GetStream(0),
			args.Is_string(1)? args.GetString(1) : NULL)) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_image::Class_image(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_image)
{
}

void Class_image::Prepare(Environment &env)
{
	Gura_AssignFunction(image);
	Gura_AssignMethod(image, allocbuff);
	Gura_AssignMethod(image, blur);
	Gura_AssignMethod(image, clear);
	Gura_AssignMethod(image, crop);
	Gura_AssignMethod(image, delpalette);
	Gura_AssignMethod(image, extract);
	Gura_AssignMethod(image, fill);
	Gura_AssignMethod(image, fillrect);
	Gura_AssignMethod(image, flip);
	Gura_AssignMethod(image, getpixel);
	Gura_AssignMethod(image, grayscale);
	Gura_AssignMethod(image, mapcolorlevel);
	Gura_AssignMethod(image, paste);
	Gura_AssignMethod(image, putpixel);
	Gura_AssignMethod(image, size);
	Gura_AssignMethod(image, store);
	Gura_AssignMethod(image, read);
	Gura_AssignMethod(image, reducecolor);
	Gura_AssignMethod(image, replacecolor);
	Gura_AssignMethod(image, resize);
	Gura_AssignMethod(image, rotate);
	Gura_AssignMethod(image, scan);
	Gura_AssignMethod(image, setalpha);
	Gura_AssignMethod(image, thumbnail);
	Gura_AssignMethod(image, write);
}

bool Class_image::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, value, pDecl);
	if (value.Is_stream()) {
		AutoPtr<Image> pImage(new Image(Image::FORMAT_RGBA));
		pImage->Read(env, sig, value.GetStream(), NULL);
		value = Value::Null; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(new Object_image(env, pImage.release()));
		return true;
	}
	return false;
}

}
