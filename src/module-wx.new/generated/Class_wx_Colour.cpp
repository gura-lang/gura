//----------------------------------------------------------------------------
// wxColour
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColour
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColour
//----------------------------------------------------------------------------
Object_wx_Colour::~Object_wx_Colour()
{
}

Object *Object_wx_Colour::Clone() const
{
	return nullptr;
}

String Object_wx_Colour::ToString(bool exprFlag)
{
	String rtn("<wx.Colour:");
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
Gura_DeclareMethodAlias(wx_Colour, __wxColour, "wxColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __wxColour)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __wxColour_1, "wxColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __wxColour_1)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int red = arg.GetNumber(0)
	//int green = arg.GetNumber(1)
	//int blue = arg.GetNumber(2)
	//int alpha = arg.GetNumber(3)
	//pThis->GetEntity()->wxColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __wxColour_2, "wxColour_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colourName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __wxColour_2)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colourName = arg.GetNumber(0)
	//pThis->GetEntity()->wxColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __wxColour_3, "wxColour_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colRGB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __wxColour_3)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colRGB = arg.GetNumber(0)
	//pThis->GetEntity()->wxColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __wxColour_4, "wxColour_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __wxColour_4)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->wxColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Alpha, "Alpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __Alpha)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Alpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Blue, "Blue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __Blue)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Blue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __GetAsString, "GetAsString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __GetAsString)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __SetRGB, "SetRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colRGB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __SetRGB)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colRGB = arg.GetNumber(0)
	//pThis->GetEntity()->SetRGB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __SetRGBA, "SetRGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colRGBA", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __SetRGBA)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colRGBA = arg.GetNumber(0)
	//pThis->GetEntity()->SetRGBA();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __GetRGB, "GetRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __GetRGB)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRGB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __GetRGBA, "GetRGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __GetRGBA)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRGBA();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __GetPixel, "GetPixel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __GetPixel)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPixel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Green, "Green")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __Green)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Green();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __IsOk)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Red, "Red")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Colour, __Red)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Red();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __Set)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int red = arg.GetNumber(0)
	//int green = arg.GetNumber(1)
	//int blue = arg.GetNumber(2)
	//int alpha = arg.GetNumber(3)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Set_1, "Set_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "RGB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __Set_1)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int RGB = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __Set_2, "Set_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __Set_2)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __MakeMono, "MakeMono")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __MakeMono)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//int on = arg.GetNumber(3)
	//pThis->GetEntity()->MakeMono();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __MakeDisabled, "MakeDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __MakeDisabled)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//int brightness = arg.GetNumber(3)
	//pThis->GetEntity()->MakeDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __MakeDisabled_1, "MakeDisabled_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __MakeDisabled_1)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int brightness = arg.GetNumber(0)
	//pThis->GetEntity()->MakeDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __MakeGrey, "MakeGrey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __MakeGrey)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//pThis->GetEntity()->MakeGrey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __MakeGrey_1, "MakeGrey_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight_r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight_g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight_b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __MakeGrey_1)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//int weight_r = arg.GetNumber(3)
	//int weight_g = arg.GetNumber(4)
	//int weight_b = arg.GetNumber(5)
	//pThis->GetEntity()->MakeGrey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __AlphaBlend, "AlphaBlend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __AlphaBlend)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fg = arg.GetNumber(0)
	//int bg = arg.GetNumber(1)
	//int alpha = arg.GetNumber(2)
	//pThis->GetEntity()->AlphaBlend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __ChangeLightness, "ChangeLightness")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ialpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __ChangeLightness)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//int ialpha = arg.GetNumber(3)
	//pThis->GetEntity()->ChangeLightness();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Colour, __ChangeLightness_1, "ChangeLightness_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ialpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, __ChangeLightness_1)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ialpha = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeLightness();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxColour
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Colour)
{
	Gura_AssignMethod(wx_Colour, __wxColour);
	Gura_AssignMethod(wx_Colour, __wxColour_1);
	Gura_AssignMethod(wx_Colour, __wxColour_2);
	Gura_AssignMethod(wx_Colour, __wxColour_3);
	Gura_AssignMethod(wx_Colour, __wxColour_4);
	Gura_AssignMethod(wx_Colour, __Alpha);
	Gura_AssignMethod(wx_Colour, __Blue);
	Gura_AssignMethod(wx_Colour, __GetAsString);
	Gura_AssignMethod(wx_Colour, __SetRGB);
	Gura_AssignMethod(wx_Colour, __SetRGBA);
	Gura_AssignMethod(wx_Colour, __GetRGB);
	Gura_AssignMethod(wx_Colour, __GetRGBA);
	Gura_AssignMethod(wx_Colour, __GetPixel);
	Gura_AssignMethod(wx_Colour, __Green);
	Gura_AssignMethod(wx_Colour, __IsOk);
	Gura_AssignMethod(wx_Colour, __Red);
	Gura_AssignMethod(wx_Colour, __Set);
	Gura_AssignMethod(wx_Colour, __Set_1);
	Gura_AssignMethod(wx_Colour, __Set_2);
	Gura_AssignMethod(wx_Colour, __MakeMono);
	Gura_AssignMethod(wx_Colour, __MakeDisabled);
	Gura_AssignMethod(wx_Colour, __MakeDisabled_1);
	Gura_AssignMethod(wx_Colour, __MakeGrey);
	Gura_AssignMethod(wx_Colour, __MakeGrey_1);
	Gura_AssignMethod(wx_Colour, __AlphaBlend);
	Gura_AssignMethod(wx_Colour, __ChangeLightness);
	Gura_AssignMethod(wx_Colour, __ChangeLightness_1);
}

Gura_ImplementDescendantCreator(wx_Colour)
{
	return new Object_wx_Colour((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
