#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Outline implementation
//-----------------------------------------------------------------------------
Object *Object_Outline::Clone() const
{
	return nullptr;
}

String Object_Outline::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Outline>");
	return String(buff);
}

bool Object_Outline::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Outline::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
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

Value Object_Outline::DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
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
// Class implementation for freetype.Outline
//-----------------------------------------------------------------------------
// freetype.Outline#Translate(xOffset:number, yOffset:number):reduce
Gura_DeclareMethod(Outline, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "xOffset", VTYPE_Matrix);
	DeclareArg(env, "yOffset", VTYPE_Matrix);
}

Gura_ImplementMethod(Outline, Translate)
{
	FT_Outline *outline = Object_Outline::GetThisObj(args)->GetEntity();
	FT_Pos xOffset = static_cast<FT_Pos>(args.GetInt(0));
	FT_Pos yOffset = static_cast<FT_Pos>(args.GetInt(1));
	::FT_Outline_Translate(outline, xOffset, yOffset);	// void function
	return args.GetThis();
}

// freetype.Outline#Transform(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Outline, Transform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Outline, Transform)
{
	FT_Outline *outline = Object_Outline::GetThisObj(args)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(args, 0)->GetEntity();
	::FT_Outline_Transform(outline, matrix);	// void function
	return args.GetThis();
}

// freetype.Outline#Embolden(strength:number):reduce
Gura_DeclareMethod(Outline, Embolden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
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

#if FREETYPE_CHECK_VERSION(2, 4, 11)
// freetype.Outline#EmboldenXY(xstrength:number, ystrength:number):reduce
Gura_DeclareMethod(Outline, EmboldenXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "xstrength", VTYPE_number);
	DeclareArg(env, "ystrength", VTYPE_number);
}

Gura_ImplementMethod(Outline, EmboldenXY)
{
	FT_Outline *outline = Object_Outline::GetThisObj(args)->GetEntity();
	FT_Pos xstrength = static_cast<FT_Pos>(args.GetDouble(0) * (1 << 6)); // 26.6
	FT_Pos ystrength = static_cast<FT_Pos>(args.GetDouble(1) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Outline_EmboldenXY(outline, xstrength, ystrength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}
#endif

// freetype.Outline#Reverse():reduce
Gura_DeclareMethod(Outline, Reverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(Outline, Reverse)
{
	FT_Outline *outline = Object_Outline::GetThisObj(args)->GetEntity();
	::FT_Outline_Reverse(outline);	// void function
	return args.GetThis();
}

Gura_ImplementUserClass(Outline)
{
	Gura_AssignValue(Outline, Value(Reference()));
	Gura_AssignMethod(Outline, Translate);
	Gura_AssignMethod(Outline, Transform);
	Gura_AssignMethod(Outline, Embolden);
#if FREETYPE_CHECK_VERSION(2, 4, 11)
	Gura_AssignMethod(Outline, EmboldenXY);
#endif
	Gura_AssignMethod(Outline, Reverse);
}

Gura_EndModuleScope(freetype)
