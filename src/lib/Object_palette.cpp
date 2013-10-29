//
// Object_palette
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_palette
//-----------------------------------------------------------------------------
Object_palette::Object_palette(const Object_palette &obj) : Object(obj),
								_pPalette(new Palette(*obj.GetPalette()))
{
}

Object_palette::~Object_palette()
{
}

Object *Object_palette::Clone() const
{
	return new Object_palette(*this);
}

Iterator *Object_palette::CreateIterator(Signal sig)
{
	return new Palette::IteratorEach(Palette::Reference(GetPalette()));
}

Value Object_palette::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.IsNumber()) {
		sig.SetError(ERR_IndexError, "index must be a number");
		return Value::Null;
	}
	size_t idx = valueIdx.GetSizeT();
	if (idx >= _pPalette->CountEntries()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Null;
	}
	return _pPalette->GetColorValue(env, idx);
}

void Object_palette::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	if (!valueIdx.IsNumber()) {
		sig.SetError(ERR_IndexError, "index must be a number");
		return;
	}
	size_t idx = valueIdx.GetSizeT();
	if (idx >= _pPalette->CountEntries()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return;
	}
	if (value.IsColor()) {
		_pPalette->SetColor(idx, Object_color::GetObject(value)->GetColor());
	} else {
		Value valueCasted = value;
		if (!env.LookupClass(VTYPE_color)->CastFrom(env, sig, valueCasted, NULL)) {
			sig.SetError(ERR_ValueError, "color must be specified");
			return;
		}
		_pPalette->SetColor(idx, Object_color::GetObject(valueCasted)->GetColor());
	}
}


String Object_palette::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<Palette:";
	do {
		char buff[64];
		::sprintf(buff, "%dentries", static_cast<int>(_pPalette->CountEntries()));
		str += buff;
	} while (0);
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// palette(type) {block?}
Gura_DeclareFunction(palette)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_palette));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates a palette of the specified type. type is a number of palette size or\n"
	"one of symbols: `basic, `win256 and `websafe.\n");
}

Gura_ImplementFunction(palette)
{
	AutoPtr<Palette> pPalette(new Palette());
	if (args.IsSymbol(0)) {
		if (!pPalette->Prepare(sig, args.GetSymbol(0))) return Value::Null;
	} else if (args.IsNumber(0)) {
		size_t nEntries = args.GetSizeT(0);
		if (nEntries > 0xffff) {
			sig.SetError(ERR_ValueError, "too large palette size");
			return Value::Null;
		}
		pPalette->AllocBuff(nEntries);
	} else {
		sig.SetError(ERR_ValueError, "number or symbol must be specified");
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_palette(env, pPalette.release())));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_palette
//-----------------------------------------------------------------------------
// palette#each() {block?}
Gura_DeclareMethod(palette, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that iterates each element in the palette.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value, idx:number|");
}

Gura_ImplementMethod(palette, each)
{
	Object_palette *pThis = Object_palette::GetThisObj(args);
	Iterator *pIterator = new Palette::IteratorEach(Palette::Reference(pThis->GetPalette()));
	return ReturnIterator(env, sig, args, pIterator);
}

// palette#nearest(color:color):map:[index]
Gura_DeclareMethod(palette, nearest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "color", VTYPE_color);
	DeclareAttr(Gura_Symbol(index));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an index of the nearest entry with the specified color.");
}

Gura_ImplementMethod(palette, nearest)
{
	Object_palette *pThis = Object_palette::GetThisObj(args);
	size_t idx = pThis->GetPalette()->LookupNearest(Object_color::GetObject(args, 0)->GetColor());
	if (args.IsSet(Gura_Symbol(index))) return Value(static_cast<UInt>(idx));
	return pThis->GetPalette()->GetColorValue(env, idx);
}

// palette#updateby(image_or_palette):reduce:[shrink,align]
Gura_DeclareMethod(palette, updateby)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "image_or_palette", VTYPE_any);
	DeclareAttr(Gura_Symbol(shrink));
	DeclareAttr(Gura_Symbol(align));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Updates palette entries according to color data in an image or a palette.\n"
	"The order of existing entries will be kept intact. If attribute shrink is\n"
	"specified, the whole size will be shrinked to a number powered by two that\n"
	"is enough to contain unique entries.");
}

Gura_ImplementMethod(palette, updateby)
{
	Object_palette *pThis = Object_palette::GetThisObj(args);
	Palette::ShrinkMode shrinkMode = Palette::ShrinkNone;
	if (args.IsSet(Gura_Symbol(shrink))) {
		shrinkMode = args.IsSet(Gura_Symbol(align))?
					Palette::ShrinkAlign : Palette::ShrinkMinimum;
	}
	if (args.IsImage(0)) {
		if (!pThis->GetPalette()->UpdateByImage(sig,
				Object_image::GetObject(args, 0)->GetImage(), shrinkMode)) {
			return Value::Null;
		}
	} else if (args.IsPalette(0)) {
		if (!pThis->GetPalette()->UpdateByPalette(sig,
				Object_palette::GetObject(args, 0)->GetPalette(), shrinkMode)) {
			return Value::Null;
		}
	} else {
		sig.SetError(ERR_ValueError, "image or palette must be specified");
		return Value::Null;
	}
	return args.GetThis();
}

// palette#shrink():reduce:[align]
Gura_DeclareMethod(palette, shrink)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareAttr(Gura_Symbol(align));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Shrinks the size of the palette to a number powered by two that is\n"
	"enough to contain unique entries. The ordef of existing entries will\n"
	"be kept intact.");
}

Gura_ImplementMethod(palette, shrink)
{
	Object_palette *pThis = Object_palette::GetThisObj(args);
	pThis->GetPalette()->Shrink(pThis->GetPalette()->NextBlankIndex(), args.IsSet(Gura_Symbol(align)));
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_palette::Class_palette(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_palette)
{
}

void Class_palette::Prepare(Environment &env)
{
	Gura_AssignFunction(palette);
	Gura_AssignMethod(palette, each);
	Gura_AssignMethod(palette, nearest);
	Gura_AssignMethod(palette, updateby);
	Gura_AssignMethod(palette, shrink);
}

bool Class_palette::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsSymbol()) {
		AutoPtr<Palette> pPalette(new Palette());
		if (!pPalette->Prepare(sig, value.GetSymbol())) return false;
		value = Value(new Object_palette(env, pPalette.release()));
		return true;
	}
	return false;
}

Object *Class_palette::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
