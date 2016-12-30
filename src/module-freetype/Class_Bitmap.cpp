#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Bitmap implementation
//-----------------------------------------------------------------------------
Object_Bitmap::~Object_Bitmap()
{
	if (_pObjHolder.get() == nullptr) {
		::FT_Bitmap_Done(g_lib, _pBitmap);
		delete _pBitmap;
	}
}

Object *Object_Bitmap::Clone() const
{
	return nullptr;
}

String Object_Bitmap::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Bitmap>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Bitmap#x
Gura_DeclareProperty_RW(Bitmap, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Bitmap, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Bitmap, x)
{
	return Value::Nil;
}

// freetype.Bitmap#y
Gura_DeclareProperty_RW(Bitmap, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Bitmap, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Bitmap, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Bitmap
//-----------------------------------------------------------------------------
// freetype.Bitmap() {block?}
Gura_DeclareFunction(Bitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Bitmap)
{
	FT_Bitmap *pBitmap = new FT_Bitmap;
	::FT_Bitmap_New(pBitmap);
	AutoPtr<Object_Bitmap> pObjRtn(new Object_Bitmap(nullptr, pBitmap));
	return ReturnValue(env, arg, Value(pObjRtn.release()));
}

// freetype.Bitmap#Embolden(xStrength:number, yStrength:number):reduce
Gura_DeclareMethod(Bitmap, Embolden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(Bitmap, Embolden)
{
	Signal &sig = env.GetSignal();
	FT_Bitmap *bitmap = Object_Bitmap::GetObjectThis(arg)->GetEntity();
	FT_Pos xStrength = static_cast<FT_Pos>(arg.GetDouble(0) * (1 << 6)); // 26.6
	FT_Pos yStrength = static_cast<FT_Pos>(arg.GetDouble(0) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Bitmap_Embolden(g_lib, bitmap, xStrength, yStrength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}

Gura_ImplementUserClass(Bitmap)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Bitmap, x);
	Gura_AssignProperty(Bitmap, y);
#endif
	Gura_AssignValue(Bitmap, Value(Reference()));
	Gura_AssignMethod(Bitmap, Embolden);
}

Gura_EndModuleScope(freetype)
