#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Outline implementation
//-----------------------------------------------------------------------------
Object *Object_Outline::Clone() const
{
	return NULL;
}

String Object_Outline::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Outline>");
	return String(buff);
}

bool Object_Outline::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Outline::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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

Value Object_Outline::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Outline
//-----------------------------------------------------------------------------
// freetype.Outline#Embolden(strength:number):reduce
Gura_DeclareMethod(Outline, Embolden)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(Outline, Embolden)
{
	FT_Outline *outline = Object_Outline::GetThisObj(args)->GetEntity();
	FT_Pos strength = static_cast<FT_Pos>(args.GetDouble(0) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Outline_Embolden(outline, strength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

// freetype.Outline#Transform(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Outline, Transform)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Outline, Transform)
{
	FT_Outline *outline = Object_Outline::GetThisObj(args)->GetEntity();
	FT_Matrix &matrix = Object_Matrix::GetObject(args, 0)->GetEntity();
	::FT_Outline_Transform(outline, &matrix);	// void function
	return args.GetThis();
}

Gura_ImplementUserClass(Outline)
{
	Gura_AssignMethod(Outline, Embolden);
	Gura_AssignMethod(Outline, Transform);
}

}}
