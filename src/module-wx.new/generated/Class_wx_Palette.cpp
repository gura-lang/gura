//----------------------------------------------------------------------------
// wxPalette
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPalette
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPalette
//----------------------------------------------------------------------------
Object_wx_Palette::~Object_wx_Palette()
{
}

Object *Object_wx_Palette::Clone() const
{
	return nullptr;
}

String Object_wx_Palette::ToString(bool exprFlag)
{
	String rtn("<wx.Palette:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Palette, "Palette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Palette));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Palette)
{
	//wxPalette();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Palette_1, "Palette_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Palette));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Palette_1)
{
	//const wxPalette& palette = arg.GetNumber(0)
	//wxPalette(palette);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Palette_2, "Palette_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Palette));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Palette_2)
{
	//int n = arg.GetNumber(0)
	//const unsigned char* red = arg.GetNumber(1)
	//const unsigned char* green = arg.GetNumber(2)
	//const unsigned char* blue = arg.GetNumber(3)
	//wxPalette(n, red, green, blue);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Palette, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Palette, __Create)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const unsigned char* red = arg.GetNumber(1)
	//const unsigned char* green = arg.GetNumber(2)
	//const unsigned char* blue = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->Create(n, red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __GetColoursCount, "GetColoursCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Palette, __GetColoursCount)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetColoursCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __GetPixel, "GetPixel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Palette, __GetPixel)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned char red = arg.GetNumber(0)
	//unsigned char green = arg.GetNumber(1)
	//unsigned char blue = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->GetPixel(red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __GetRGB, "GetRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Palette, __GetRGB)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixel = arg.GetNumber(0)
	//unsigned char* red = arg.GetNumber(1)
	//unsigned char* green = arg.GetNumber(2)
	//unsigned char* blue = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->GetRGB(pixel, red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Palette, __IsOk)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPalette
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Palette)
{
	// Constructor assignment
	Gura_AssignFunction(__Palette);
	Gura_AssignFunction(__Palette_1);
	Gura_AssignFunction(__Palette_2);
	// Method assignment
	Gura_AssignMethod(wx_Palette, __Create);
	Gura_AssignMethod(wx_Palette, __GetColoursCount);
	Gura_AssignMethod(wx_Palette, __GetPixel);
	Gura_AssignMethod(wx_Palette, __GetRGB);
	Gura_AssignMethod(wx_Palette, __IsOk);
}

Gura_ImplementDescendantCreator(wx_Palette)
{
	return new Object_wx_Palette((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
