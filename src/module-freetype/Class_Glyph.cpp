#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Glyph implementation
//-----------------------------------------------------------------------------
Object_Glyph::~Object_Glyph()
{
	if (_pObjHolder.get() == nullptr) {
		::FT_Done_Glyph(*_pGlyph);
		delete _pGlyph;
	}
}

Object *Object_Glyph::Clone() const
{
	return nullptr;
}

String Object_Glyph::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Glyph>");
	return String(buff);
}

bool Object_Glyph::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Glyph::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_Glyph::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Glyph#x
Gura_DeclareProperty_RW(Glyph, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Glyph, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Glyph, x)
{
	return Value::Nil;
}

// freetype.Glyph#y
Gura_DeclareProperty_RW(Glyph, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Glyph, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Glyph, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Glyph
//-----------------------------------------------------------------------------
// freetype.Glyph#Copy()
Gura_DeclareMethod(Glyph, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Glyph, Copy)
{
	Signal &sig = env.GetSignal();
	FT_Glyph *pGlyph = Object_Glyph::GetObjectThis(arg)->GetEntity();
	std::unique_ptr<FT_Glyph> pGlyphTgt(new FT_Glyph);
	FT_Error err = ::FT_Glyph_Copy(*pGlyph, pGlyphTgt.get());
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return Value(new Object_Glyph(nullptr, pGlyphTgt.release()));
}

// freetype.Glyph#Stroke(stroker:freetype.Stroker):reduce
Gura_DeclareMethod(Glyph, Stroke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stroker", VTYPE_Stroker);
}

Gura_ImplementMethod(Glyph, Stroke)
{
	Signal &sig = env.GetSignal();
	FT_Glyph *pGlyph = Object_Glyph::GetObjectThis(arg)->GetEntity();
	FT_Stroker stroker = Object_Stroker::GetObject(arg, 0)->GetEntity();
	FT_Error err = ::FT_Glyph_Stroke(pGlyph, stroker, false);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}

// freetype.Glyph#StrokeBorder(stroker:freetype.Stroker, inside:boolean):reduce
Gura_DeclareMethod(Glyph, StrokeBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stroker", VTYPE_Stroker);
	DeclareArg(env, "inside", VTYPE_boolean);
}

Gura_ImplementMethod(Glyph, StrokeBorder)
{
	Signal &sig = env.GetSignal();
	FT_Glyph *pGlyph = Object_Glyph::GetObjectThis(arg)->GetEntity();
	FT_Stroker stroker = Object_Stroker::GetObject(arg, 0)->GetEntity();
	FT_Bool inside = arg.GetBoolean(1);
	FT_Error err = ::FT_Glyph_StrokeBorder(pGlyph, stroker, inside, false);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}

Gura_ImplementUserClass(Glyph)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Glyph, x);
	Gura_AssignProperty(Glyph, y);
#endif
	Gura_AssignValue(Glyph, Value(Reference()));
	Gura_AssignMethod(Glyph, Copy);
	Gura_AssignMethod(Glyph, Stroke);
	Gura_AssignMethod(Glyph, StrokeBorder);
}

Gura_EndModuleScope(freetype)
