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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Outline#x
Gura_DeclareProperty_RW(Outline, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Outline, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Outline, x)
{
	return Value::Nil;
}

// freetype.Outline#y
Gura_DeclareProperty_RW(Outline, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Outline, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Outline, y)
{
	return Value::Nil;
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
	FT_Outline *outline = Object_Outline::GetObjectThis(arg)->GetEntity();
	FT_Pos xOffset = static_cast<FT_Pos>(arg.GetInt(0));
	FT_Pos yOffset = static_cast<FT_Pos>(arg.GetInt(1));
	::FT_Outline_Translate(outline, xOffset, yOffset);	// void function
	return arg.GetValueThis();
}

// freetype.Outline#Transform(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Outline, Transform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Outline, Transform)
{
	FT_Outline *outline = Object_Outline::GetObjectThis(arg)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(arg, 0)->GetEntity();
	::FT_Outline_Transform(outline, matrix);	// void function
	return arg.GetValueThis();
}

// freetype.Outline#Embolden(strength:number):reduce
Gura_DeclareMethod(Outline, Embolden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(Outline, Embolden)
{
	Signal &sig = env.GetSignal();
	FT_Outline *outline = Object_Outline::GetObjectThis(arg)->GetEntity();
	FT_Pos strength = static_cast<FT_Pos>(arg.GetDouble(0) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Outline_Embolden(outline, strength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
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
	Signal &sig = env.GetSignal();
	FT_Outline *outline = Object_Outline::GetObjectThis(arg)->GetEntity();
	FT_Pos xstrength = static_cast<FT_Pos>(arg.GetDouble(0) * (1 << 6)); // 26.6
	FT_Pos ystrength = static_cast<FT_Pos>(arg.GetDouble(1) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Outline_EmboldenXY(outline, xstrength, ystrength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}
#endif

// freetype.Outline#Reverse():reduce
Gura_DeclareMethod(Outline, Reverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(Outline, Reverse)
{
	FT_Outline *outline = Object_Outline::GetObjectThis(arg)->GetEntity();
	::FT_Outline_Reverse(outline);	// void function
	return arg.GetValueThis();
}

Gura_ImplementUserClass(Outline)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Outline, x);
	Gura_AssignProperty(Outline, y);
#endif
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
