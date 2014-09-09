#include "stdafx.h"
#include "DeclareSymbols.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Glyph implementation
//-----------------------------------------------------------------------------
Object_Glyph::~Object_Glyph()
{
	if (_pObjHolder.get() == NULL) {
		::FT_Done_Glyph(*_pGlyph);
		delete _pGlyph;
	}
}

Object *Object_Glyph::Clone() const
{
	return NULL;
}

String Object_Glyph::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Glyph>");
	return String(buff);
}

bool Object_Glyph::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Glyph::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
	return Value::Null;
}

Value Object_Glyph::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Glyph
//-----------------------------------------------------------------------------
// freetype.Glyph#Copy()
Gura_DeclareMethod(Glyph, Copy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Glyph, Copy)
{
	FT_Glyph *pGlyph = Object_Glyph::GetThisObj(args)->GetEntity();
	std::auto_ptr<FT_Glyph> pGlyphTgt(new FT_Glyph);
	FT_Error err = ::FT_Glyph_Copy(*pGlyph, pGlyphTgt.get());
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return Value(new Object_Glyph(NULL, pGlyphTgt.release()));
}

// freetype.Glyph#Stroke(stroker:freetype.Stroker):reduce
Gura_DeclareMethod(Glyph, Stroke)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stroker", VTYPE_Stroker);
}

Gura_ImplementMethod(Glyph, Stroke)
{
	FT_Glyph *pGlyph = Object_Glyph::GetThisObj(args)->GetEntity();
	FT_Stroker stroker = Object_Stroker::GetObject(args, 0)->GetEntity();
	FT_Error err = ::FT_Glyph_Stroke(pGlyph, stroker, false);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

// freetype.Glyph#StrokeBorder(stroker:freetype.Stroker, inside:boolean):reduce
Gura_DeclareMethod(Glyph, StrokeBorder)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stroker", VTYPE_Stroker);
	DeclareArg(env, "inside", VTYPE_boolean);
}

Gura_ImplementMethod(Glyph, StrokeBorder)
{
	FT_Glyph *pGlyph = Object_Glyph::GetThisObj(args)->GetEntity();
	FT_Stroker stroker = Object_Stroker::GetObject(args, 0)->GetEntity();
	FT_Bool inside = args.GetBoolean(1);
	FT_Error err = ::FT_Glyph_StrokeBorder(pGlyph, stroker, inside, false);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

Gura_ImplementUserClass(Glyph)
{
	Gura_AssignMethod(Glyph, Copy);
	Gura_AssignMethod(Glyph, Stroke);
	Gura_AssignMethod(Glyph, StrokeBorder);
}

Gura_EndModuleScope(freetype)
