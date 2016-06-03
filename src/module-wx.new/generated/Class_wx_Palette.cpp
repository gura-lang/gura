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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Palette, __wxPalette, "wxPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Palette, __wxPalette)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPalette();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __wxPalette_1, "wxPalette_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Palette, __wxPalette_1)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int palette = arg.GetNumber(0)
	//pThis->GetEntity()->wxPalette();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __wxPalette_2, "wxPalette_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Palette, __wxPalette_2)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int red = arg.GetNumber(1)
	//int green = arg.GetNumber(2)
	//int blue = arg.GetNumber(3)
	//pThis->GetEntity()->wxPalette();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int red = arg.GetNumber(1)
	//int green = arg.GetNumber(2)
	//int blue = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __GetColoursCount, "GetColoursCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Palette, __GetColoursCount)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColoursCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __GetPixel, "GetPixel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Palette, __GetPixel)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int red = arg.GetNumber(0)
	//int green = arg.GetNumber(1)
	//int blue = arg.GetNumber(2)
	//pThis->GetEntity()->GetPixel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __GetRGB, "GetRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int red = arg.GetNumber(1)
	//int green = arg.GetNumber(2)
	//int blue = arg.GetNumber(3)
	//pThis->GetEntity()->GetRGB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Palette, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Palette, __IsOk)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPalette
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Palette)
{
	Gura_AssignMethod(wx_Palette, __wxPalette);
	Gura_AssignMethod(wx_Palette, __wxPalette_1);
	Gura_AssignMethod(wx_Palette, __wxPalette_2);
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
