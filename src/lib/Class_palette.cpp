//=============================================================================
// Gura class: palette
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

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

Iterator *Object_palette::CreateIterator(Signal &sig)
{
	return new Palette::IteratorEach(Palette::Reference(GetPalette()));
}

#if NEW_INDEXING

Value Object_palette::IndexGet(Environment &env, const ValueList &valListIdx)
{
	return Value::Nil;
}

void Object_palette::IndexSet(Environment &env, const ValueList &valListIdx, const Value &value)
{
}

#else

Value Object_palette::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number");
		return Value::Nil;
	}
	size_t idx = valueIdx.GetSizeT();
	if (idx >= _pPalette->CountEntries()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Nil;
	}
	return _pPalette->GetColorValue(env, idx);
}

void Object_palette::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number");
		return;
	}
	size_t idx = valueIdx.GetSizeT();
	if (idx >= _pPalette->CountEntries()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return;
	}
	if (value.Is_color()) {
		_pPalette->SetColor(idx, Object_color::GetObject(value)->GetColor());
	} else {
		Value valueCasted = value;
		if (!env.LookupClass(VTYPE_color)->CastFrom(env, valueCasted, FLAG_None)) {
			sig.SetError(ERR_ValueError, "color must be specified");
			return;
		}
		_pPalette->SetColor(idx, Object_color::GetObject(valueCasted)->GetColor());
	}
}

#endif

String Object_palette::ToString(bool exprFlag)
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
// Implementation of functions
//-----------------------------------------------------------------------------
// palette(type) {block?}
Gura_DeclareFunction(palette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_palette));
	AddHelp(
		Gura_Symbol(en), 
		"Creates a `palette` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("plt", "palette")
		"\n"
		"This function can be called in the following two forms:\n"
		"\n"
		"- `palette(n:number)` .. Creates an instance with the specified number of entries.\n"
		"  All the entries are initialized with a color of black.\n"
		"- `palette(type:symbol)` .. Creates an instance initialized with\n"
		"  a pre-defined set of entries associated with the specified symbol.\n"
		"\n"
		"In the second form, it can take one of the following symbols:\n"
		"\n"
		"- `` `basic`` .. A palette with 16 basic colors that are:\n"
		"  `color.black`, `color.maroon`, `color.green`, `color.olive`, `color.navy`,\n"
		"  `color.purple`, `color.teal`, `color.gray`, `color.silver`, `color.red`,\n"
		"  `color.lime`, `color.yellow`,  `color.blue`, `color.fuchsia`, `color.aqua`\n"
		"  and `color.white`.\n"
		"- `` `win256`` .. A palette with 256 colors defined by Windows.\n"
		"- `` `websafe`` .. A palette with 216 colors that assure to be displayed correctly\n"
		"  in any Web environments. It actually has 256 entries\n"
		"  though the last 40 entries are initialized with black.\n");
}

Gura_ImplementFunction(palette)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Palette> pPalette(new Palette());
	if (arg.Is_symbol(0)) {
		if (!pPalette->Prepare(sig, arg.GetSymbol(0))) return Value::Nil;
	} else if (arg.Is_number(0)) {
		size_t nEntries = arg.GetSizeT(0);
		if (nEntries > 0xffff) {
			sig.SetError(ERR_ValueError, "too large palette size");
			return Value::Nil;
		}
		pPalette->AllocBuff(nEntries);
	} else {
		sig.SetError(ERR_ValueError, "number or symbol must be specified");
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_palette(env, pPalette.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// palette#each() {block?}
Gura_DeclareMethod(palette, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that iterates each element in the palette.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(palette, each)
{
	Object_palette *pThis = Object_palette::GetObjectThis(arg);
	Iterator *pIterator = new Palette::IteratorEach(Palette::Reference(pThis->GetPalette()));
	return ReturnIterator(env, arg, pIterator);
}

// palette#nearest(color:color):map:[index]
Gura_DeclareMethod(palette, nearest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "color", VTYPE_color);
	DeclareAttr(Gura_Symbol(index));
	AddHelp(
		Gura_Symbol(en),
		"Returns a `color` instance in the palette that is the nearest with the specified color.\n"
		"\n"
		"If the attribute `:index` is specified, it would return an index\n"
		"of the nearst entry instead of its `color` instance.\n");
}

Gura_ImplementMethod(palette, nearest)
{
	Object_palette *pThis = Object_palette::GetObjectThis(arg);
	size_t idx = pThis->GetPalette()->LookupNearest(Object_color::GetObject(arg, 0)->GetColor());
	if (arg.IsSet(Gura_Symbol(index))) return Value(static_cast<UInt>(idx));
	return pThis->GetPalette()->GetColorValue(env, idx);
}

// palette#shrink():reduce:[align]
Gura_DeclareMethod(palette, shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareAttr(Gura_Symbol(align));
	AddHelp(
		Gura_Symbol(en), 
		"Shrinks the size of the palette to a number powered by two that is\n"
		"enough to contain unique entries. The ordef of existing entries will\n"
		"be kept intact.\n");
}

Gura_ImplementMethod(palette, shrink)
{
	Object_palette *pThis = Object_palette::GetObjectThis(arg);
	pThis->GetPalette()->Shrink(pThis->GetPalette()->NextBlankIndex(), arg.IsSet(Gura_Symbol(align)));
	return arg.GetValueThis();
}

// palette#updateby(image_or_palette):reduce:[shrink,align]
Gura_DeclareMethod(palette, updateby)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "image_or_palette", VTYPE_any);
	DeclareAttr(Gura_Symbol(shrink));
	DeclareAttr(Gura_Symbol(align));
	AddHelp(
		Gura_Symbol(en), 
		"Updates palette entries according to color data in an image or a palette.\n"
		"\n"
		"The order of existing entries will be kept intact. If attribute shrink is\n"
		"specified, the whole size will be shrinked to a number powered by two that\n"
		"is enough to contain unique entries.");
}

Gura_ImplementMethod(palette, updateby)
{
	Signal &sig = env.GetSignal();
	Object_palette *pThis = Object_palette::GetObjectThis(arg);
	Palette::ShrinkMode shrinkMode = Palette::ShrinkNone;
	if (arg.IsSet(Gura_Symbol(shrink))) {
		shrinkMode = arg.IsSet(Gura_Symbol(align))?
					Palette::ShrinkAlign : Palette::ShrinkMinimum;
	}
	if (arg.Is_image(0)) {
		if (!pThis->GetPalette()->UpdateByImage(sig,
				Object_image::GetObject(arg, 0)->GetImage(), shrinkMode)) {
			return Value::Nil;
		}
	} else if (arg.Is_palette(0)) {
		if (!pThis->GetPalette()->UpdateByPalette(sig,
				Object_palette::GetObject(arg, 0)->GetPalette(), shrinkMode)) {
			return Value::Nil;
		}
	} else {
		sig.SetError(ERR_ValueError, "image or palette must be specified");
		return Value::Nil;
	}
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_palette::Class_palette(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_palette)
{
}

void Class_palette::DoPrepare(Environment &env)
{
	Gura_AssignFunction(palette);
	Gura_AssignMethod(palette, each);
	Gura_AssignMethod(palette, nearest);
	Gura_AssignMethod(palette, shrink);
	Gura_AssignMethod(palette, updateby);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_palette::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_symbol()) {
		AutoPtr<Palette> pPalette(new Palette());
		if (!pPalette->Prepare(sig, value.GetSymbol())) return false;
		value = Value(new Object_palette(env, pPalette.release()));
		return true;
	}
	return false;
}

Object *Class_palette::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
