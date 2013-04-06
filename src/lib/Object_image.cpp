// Object_image

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
	symbols.insert(Gura_Symbol(width));
	symbols.insert(Gura_Symbol(height));
	symbols.insert(Gura_Symbol(palette));
	return true;
}

Value Object_image::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(GetImage()->FormatToSymbol(GetImage()->GetFormat()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		return Value(static_cast<unsigned int>(GetImage()->GetWidth()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		return Value(static_cast<unsigned int>(GetImage()->GetHeight()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(palette))) {
		const Palette *pPalette = GetImage()->GetPalette();
		if (pPalette == NULL) return Value::Null;
		return Value(new Object_palette(env, Palette::Reference(pPalette)));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_image::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(palette))) {
		if (value.IsPalette()) {
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

String Object_image::ToString(Signal sig, bool exprFlag)
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
// Global functions
//-----------------------------------------------------------------------------
// image(args+):map {block?}
Gura_DeclareFunction(image)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_image));
	AddHelp(Gura_Symbol(en), 
	"Returns an image object with specified characteristics. There are three patterns\n"
	"to call the function as follows.\n"
	"- image(stream:stream, format?:symbol, imgtype?:string)\n"
	"- image(format:symbol)\n"
	"- image(format:symbol, width:number, height:number, color?:color)\n"
	"In the first pattern, it creates an empty image with a specified format.\n"
	"The second reads image data from the stream and expand it in the buffer.\n"
	"The last allocates an image buffer of specified size and fills it with the color.\n"
	"Parameter format specifies the internal format. Available formats are `rgb and `rgba.");
}

Gura_ImplementFunction(image)
{
	if (sig.IsSignalled()) return Value::Null;
	ValueList valList = args.GetList(0);
	Object_image *pObj = NULL;
	if (valList[0].IsSymbol()) {
		Declaration(Gura_Symbol(format), VTYPE_symbol).
									ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Image::Format format =
					Image::SymbolToFormat(sig, valList[0].GetSymbol());
		if (sig.IsSignalled()) return Value::Null;
		pObj = new Object_image(env, new Image(format));
		if (valList.size() >= 2) {
			Declaration(Gura_Symbol(width), VTYPE_number).
										ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			size_t width = valList[1].GetSizeT();
			size_t height = width;
			if (valList.size() >= 3) {
				Declaration(Gura_Symbol(height), VTYPE_number).
											ValidateAndCast(env, sig, valList[2]);
				if (sig.IsSignalled()) return Value::Null;
				height = valList[2].GetSizeT();
			}
			if (!pObj->GetImage()->AllocBuffer(sig, width, height, 0x00)) {
				delete pObj;
				return Value::Null;
			}
			if (valList.size() >= 4) {
				Declaration(Gura_Symbol(color), VTYPE_color).
										ValidateAndCast(env, sig, valList[3]);
				if (sig.IsSignalled()) return Value::Null;
				pObj->GetImage()->Fill(Object_color::GetObject(valList[3])->GetColor());
			}
		}
	} else {
		Declaration(Gura_Symbol(stream), VTYPE_stream, OCCUR_Once, FLAG_Read, NULL).
									ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Stream &stream = valList[0].GetStream();
		Image::Format format = Image::FORMAT_RGBA;
		if (valList.size() >= 2) {
			Declaration(Gura_Symbol(format), VTYPE_symbol).
									ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			format = Image::SymbolToFormat(sig, valList[1].GetSymbol());
			if (sig.IsSignalled()) return Value::Null;
		}
		pObj = new Object_image(env, new Image(format));
		const char *imgType = NULL;
		if (valList.size() >= 3) {
			Declaration(Gura_Symbol(imgtype), VTYPE_string).
									ValidateAndCast(env, sig, valList[2]);
			if (sig.IsSignalled()) return Value::Null;
			imgType = valList[2].GetString();
		}
		if (!pObj->GetImage()->Read(env, sig, stream, imgType)) return Value::Null;
	}
	Value result(pObj);
	return ReturnValue(env, sig, args, result);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
//-----------------------------------------------------------------------------
// image#size()
Gura_DeclareMethod(image, size)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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

// image#allocbuff(width:number, height:number, color?:color):void
Gura_DeclareMethod(image, allocbuff)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, allocbuff)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckEmpty(sig)) return Value::Null;
	pThis->GetImage()->AllocBuffer(sig, args.GetSizeT(0), args.GetSizeT(1), 0x00);
	if (args.IsColor(2)) pThis->GetImage()->Fill(Object_color::GetObject(args, 2)->GetColor());
	return Value::Null;
}

// image#putpixel(x:number, y:number, color:color):map:void
Gura_DeclareMethod(image, putpixel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, putpixel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	unsigned char *p = pThis->GetImage()->GetPointer(x, y);
	pThis->GetImage()->PutPixel(p, Object_color::GetObject(args, 2)->GetColor());
	return Value::Null;
}

// image#getpixel(x:number, y:number):map
Gura_DeclareMethod(image, getpixel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(image, getpixel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	unsigned char *p = pThis->GetImage()->GetPointer(x, y);
	Color color;
	pThis->GetImage()->GetPixel(p, color);
	return Value(new Object_color(env, color));
}

// image#store(x:number, y:number, width:number, height:number, element:symbol, src):void
Gura_DeclareMethod(image, store)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "element", VTYPE_symbol);
	DeclareArg(env, "src", VTYPE_any);
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
	if (args.IsMatrix(5)) {
		pThis->GetImage()->Store(sig, x, y, width, height, pSymbol, Object_matrix::GetObject(args, 5));
	} else if (args.IsList(5) || args.IsIterator(5)) {
		AutoPtr<Iterator> pIterator(args.GetValue(5).CreateIterator(sig));
		pThis->GetImage()->Store(env, sig, x, y, width, height, pSymbol, pIterator.get());
	} else {
		sig.SetError(ERR_ValueError, "invalid object for image's source");
		return Value::Null;
	}
	return Value::Null;
}

// image#extract(x:number, y:number, width:number, height:number, element:symbol, dst):void
Gura_DeclareMethod(image, extract)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "element", VTYPE_symbol);
	DeclareArg(env, "dst", VTYPE_any);
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
	if (args.IsMatrix(5)) {
		pThis->GetImage()->Extract(sig, x, y, width, height, pSymbol, Object_matrix::GetObject(args, 5));
	} else if (args.IsList(5)) {
		pThis->GetImage()->Extract(sig, x, y, width, height, pSymbol, Object_list::GetObject(args, 5));
	} else {
		sig.SetError(ERR_ValueError, "invalid object for image's destination");
		return Value::Null;
	}
	return Value::Null;
}

// image#replacecolor(colorOrg:color, color:color):void
Gura_DeclareMethod(image, replacecolor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "colorOrg", VTYPE_color);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, replacecolor)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	pThis->GetImage()->ReplaceColor(Object_color::GetObject(args, 0)->GetColor(),
							Object_color::GetObject(args, 1)->GetColor());
	return Value::Null;
}

// image#clear():void
Gura_DeclareMethod(image, clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(image, clear)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	pThis->GetImage()->Fill(Color::Zero);
	return Value::Null;
}

// image#fill(color:color):void
Gura_DeclareMethod(image, fill)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, fill)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	pThis->GetImage()->Fill(Object_color::GetObject(args, 0)->GetColor());
	return Value::Null;
}

// image#fillrect(x:number, y:number, width:number, height:number, color:color):map:void
Gura_DeclareMethod(image, fillrect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, fillrect)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	int width = args.GetInt(2), height = args.GetInt(3);
	if (!pThis->GetImage()->AdjustCoord(x, y, width, height)) return Value::Null;
	pThis->GetImage()->FillRect(x, y, width, height, Object_color::GetObject(args, 4)->GetColor());
	return Value::Null;
}

// image#setalpha(alpha:number, color?:color):reduce
Gura_DeclareMethod(image, setalpha)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
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
		pThis->GetImage()->FillAlpha(args.GetUChar(0), Object_color::GetObject(args, 1)->GetColor());
	} else {
		pThis->GetImage()->FillAlpha(args.GetUChar(0));
	}
	return args.GetThis();
}

// image#reducecolor(palette?:palette)
Gura_DeclareMethod(image, reducecolor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "palette", VTYPE_palette, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, reducecolor)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	const Palette *pPalette = pThis->GetImage()->GetPalette();
	if (args.IsPalette(0)) {
		pPalette = Object_palette::GetObject(args, 0)->GetPalette();
	} else if (pPalette == NULL) {
		sig.SetError(ERR_ValueError, "palette must be specified");
		return Value::Null;
	}
	AutoPtr<Image> pImage(pThis->GetImage()->ReduceColor(sig, pPalette));
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_image(env, pImage.release()));
}

// image#grayscale()
Gura_DeclareMethod(image, grayscale)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image, grayscale)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	AutoPtr<Image> pImage(pThis->GetImage()->GrayScale(sig));
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_image(env, pImage.release()));
}

// image#delpalette():reduce
Gura_DeclareMethod(image, delpalette)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(image, delpalette)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	pThis->GetImage()->SetPalette(NULL);
	return args.GetThis();
}

// image#flip(orient:symbol):map
Gura_DeclareMethod(image, flip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orient", VTYPE_symbol);
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
	return Value(new Object_image(env, pImage.release()));
}

// image#rotate(angle:number, background?:color):map
Gura_DeclareMethod(image, rotate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rotate", VTYPE_number);
	DeclareArg(env, "background", VTYPE_color, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, rotate)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	Color color;
	if (args.IsColor(1)) {
		color = Object_color::GetObject(1)->GetColor();
	}
	AutoPtr<Image> pImage(pThis->GetImage()->Rotate(sig, args.GetNumber(0), color));
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_image(env, pImage.release()));
}

// image#crop(x:number, y:number, width?:number, height?:number):map
Gura_DeclareMethod(image, crop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, crop)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0);
	size_t y = args.GetSizeT(1);
	if (!pThis->GetImage()->CheckCoord(sig, x, y)) return Value::Null;
	size_t width = args.IsNumber(2)? args.GetSizeT(2) : pThis->GetImage()->GetWidth() - x;
	size_t height = args.IsNumber(3)? args.GetSizeT(3) : pThis->GetImage()->GetHeight() - y;
	if (!pThis->GetImage()->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	AutoPtr<Image> pImage(pThis->GetImage()->Crop(sig, x, y, width, height));
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_image(env, pImage.release()));
}

// image#resize(width?:number, height?:number):map:[box]
Gura_DeclareMethod(image, resize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(box));
}

Gura_ImplementMethod(image, resize)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	bool boxFlag = args.IsSet(Gura_Symbol(box));
	size_t width, height;
	if (!args.IsNumber(0) && !args.IsNumber(1)) {
		sig.SetError(ERR_ValueError, "width or height must be specified");
		return Value::Null;
	}
	if (args.IsNumber(0) && !args.IsNumber(1)) {
		width = args.GetSizeT(0);
		if (boxFlag) {
			height = width;
		} else {
			height = pThis->GetImage()->GetHeight() * width / pThis->GetImage()->GetWidth();
		}
	} else if (!args.IsNumber(0) && args.IsNumber(1)) {
		height = args.GetSizeT(1);
		if (boxFlag) {
			width = height;
		} else {
			width = pThis->GetImage()->GetWidth() * height / pThis->GetImage()->GetHeight();
		}
	} else {
		width = args.GetSizeT(0), height = args.GetSizeT(1);
	}
	AutoPtr<Image> pImage(pThis->GetImage()->Resize(sig, width, height));
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_image(env, pImage.release()));
}

// image#thumbnail(width?:number, height?:number):map:[box]
Gura_DeclareMethod(image, thumbnail)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(box));
}

Gura_ImplementMethod(image, thumbnail)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	bool boxFlag = args.IsSet(Gura_Symbol(box));
	Object_image *pObj = NULL;
	if (!args.IsNumber(0) && !args.IsNumber(1)) {
		sig.SetError(ERR_ValueError, "width or height must be specified");
		return Value::Null;
	}
	size_t width = 0, height = 0;
	if (args.IsNumber(0) && !args.IsNumber(1)) {
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
			return Value(pObj);
		}
	} else if (!args.IsNumber(0) && args.IsNumber(1)) {
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
			return Value(pObj);
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
	return Value(pObj);
}

// image#paste(x:number, y:number, src:image, width?:number, height?:number,
//     xoffset:number => 0, yoffset:number => 0, alpha:number => 255):map:reduce
Gura_DeclareMethod(image, paste)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "src", VTYPE_image);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(255));
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
	size_t width = args.IsNumber(3)?
				args.GetSizeT(3) : pObjImg->GetImage()->GetWidth() - xOffset;
	size_t height = args.IsNumber(4)?
				args.GetSizeT(4) : pObjImg->GetImage()->GetHeight() - yOffset;
	if (!pObjImg->GetImage()->CheckCoord(sig, xOffset + width - 1, yOffset + height - 1)) {
		return Value::Null;
	}
	if (x + width > pThis->GetImage()->GetWidth()) width = pThis->GetImage()->GetWidth() - x;
	if (y + height > pThis->GetImage()->GetHeight()) height = pThis->GetImage()->GetHeight() - y;
	unsigned char alpha = args.GetUChar(7);
	pThis->GetImage()->Paste(x, y, pObjImg->GetImage(),
							width, height, xOffset, yOffset, alpha);
	if (sig.IsSignalled()) return Value::Null;
	return args.GetThis();
}

// image#read(stream:stream:r, imgtype?:string):map:reduce
Gura_DeclareMethod(image, read)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "imgtype", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Reads image data from a stream.");
}

Gura_ImplementMethod(image, read)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->Read(env, sig, args.GetStream(0),
			args.IsString(1)? args.GetString(1) : NULL)) return Value::Null;
	return args.GetThis();
}

// image#write(stream:stream:w, imgtype?:string):map:reduce
Gura_DeclareMethod(image, write)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "imgtype", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Writes image data to a stream.");
}

Gura_ImplementMethod(image, write)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->Write(env, sig, args.GetStream(0),
			args.IsString(1)? args.GetString(1) : NULL)) return Value::Null;
	return args.GetThis();
}

// image#each(x:number, y:number, width:number, height:number, scandir:symbol) {block?}
Gura_DeclareMethod(image, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "scandir", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Returns an iterator that scans pixels in the image.");
}

Gura_ImplementMethod(image, each)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	size_t x = args.IsNumber(0)? args.GetSizeT(0) : 0;
	size_t y = args.IsNumber(1)? args.GetSizeT(1) : 0;
	size_t width = args.IsNumber(2)? args.GetSizeT(2) : pThis->GetImage()->GetWidth();
	size_t height = args.IsNumber(3)? args.GetSizeT(3) : pThis->GetImage()->GetHeight();
	Image::ScanDir scanDir = Image::SCAN_LeftTopHorz;
	if (args.IsSymbol(4)) {
		const Symbol *pSymbol = args.GetSymbol(4);
		
	}
	Iterator *pIterator = new Image::IteratorEach(
			Image::Reference(pThis->GetImage()), x, y, width, height, scanDir);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_image::Class_image(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_image)
{
	Gura_AssignMethod(image, size);
	Gura_AssignMethod(image, allocbuff);
	Gura_AssignMethod(image, putpixel);
	Gura_AssignMethod(image, getpixel);
	Gura_AssignMethod(image, store);
	Gura_AssignMethod(image, extract);
	Gura_AssignMethod(image, replacecolor);
	Gura_AssignMethod(image, clear);
	Gura_AssignMethod(image, fill);
	Gura_AssignMethod(image, fillrect);
	Gura_AssignMethod(image, setalpha);
	Gura_AssignMethod(image, reducecolor);
	Gura_AssignMethod(image, grayscale);
	Gura_AssignMethod(image, delpalette);
	Gura_AssignMethod(image, flip);
	Gura_AssignMethod(image, rotate);
	Gura_AssignMethod(image, crop);
	Gura_AssignMethod(image, resize);
	Gura_AssignMethod(image, thumbnail);
	Gura_AssignMethod(image, paste);
	Gura_AssignMethod(image, read);
	Gura_AssignMethod(image, write);
	Gura_AssignMethod(image, each);
}

bool Class_image::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		AutoPtr<Stream> pStream(Directory::OpenStream(env, sig,
								value.GetString(), Stream::ATTR_Readable));
		if (sig.IsSignalled()) return false;
		AutoPtr<Image> pImage(new Image(Image::FORMAT_RGBA));
		pImage->Read(env, sig, *pStream, NULL);
		if (sig.IsSignalled()) {
			return false;
		}
		value = Value(new Object_image(env, pImage.release()));
		return true;
	}
	return false;
}

void Class_image::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(image);
}

}
