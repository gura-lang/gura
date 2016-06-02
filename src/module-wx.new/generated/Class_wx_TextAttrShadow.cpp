//----------------------------------------------------------------------------
// wxTextAttrShadow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrShadow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrShadow
//----------------------------------------------------------------------------
Object_wx_TextAttrShadow::~Object_wx_TextAttrShadow()
{
}

Object *Object_wx_TextAttrShadow::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrShadow::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrShadow:");
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
Gura_DeclareMethod(wx_TextAttrShadow, wxTextAttrShadow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, wxTextAttrShadow)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrShadow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, Reset)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shadow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, EqPartial)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int shadow = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shadow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, Apply)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int shadow = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, RemoveStyle)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, CollectCommonAttributes)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetColour)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetColour_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetColourLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetColourLong)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColourLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetColour)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, HasColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, HasColour)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetOffsetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetOffsetX)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetOffsetX_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetOffsetX_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetOffsetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetOffsetX)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int offset = arg.GetNumber(0)
	//pThis->GetEntity()->SetOffsetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetOffsetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetOffsetY)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetOffsetY_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetOffsetY_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetOffsetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetOffsetY)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int offset = arg.GetNumber(0)
	//pThis->GetEntity()->SetOffsetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetSpread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetSpread)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetSpread_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetSpread_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetSpread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spread", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetSpread)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int spread = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetBlurDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetBlurDistance)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlurDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetBlurDistance_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetBlurDistance_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlurDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetBlurDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "blur", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetBlurDistance)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int blur = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlurDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetOpacity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetOpacity)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpacity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetOpacity_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetOpacity_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpacity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, IsValid)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetValid)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, GetFlags)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetFlags)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, AddFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, AddFlag)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->AddFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, RemoveFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, RemoveFlag)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, SetOpacity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "opacity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, SetOpacity)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int opacity = arg.GetNumber(0)
	//pThis->GetEntity()->SetOpacity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrShadow, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, IsDefault)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrShadow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrShadow)
{
	Gura_AssignMethod(wx_TextAttrShadow, wxTextAttrShadow);
	Gura_AssignMethod(wx_TextAttrShadow, Reset);
	Gura_AssignMethod(wx_TextAttrShadow, EqPartial);
	Gura_AssignMethod(wx_TextAttrShadow, Apply);
	Gura_AssignMethod(wx_TextAttrShadow, RemoveStyle);
	Gura_AssignMethod(wx_TextAttrShadow, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrShadow, SetColour);
	Gura_AssignMethod(wx_TextAttrShadow, SetColour_1);
	Gura_AssignMethod(wx_TextAttrShadow, GetColourLong);
	Gura_AssignMethod(wx_TextAttrShadow, GetColour);
	Gura_AssignMethod(wx_TextAttrShadow, HasColour);
	Gura_AssignMethod(wx_TextAttrShadow, GetOffsetX);
	Gura_AssignMethod(wx_TextAttrShadow, GetOffsetX_1);
	Gura_AssignMethod(wx_TextAttrShadow, SetOffsetX);
	Gura_AssignMethod(wx_TextAttrShadow, GetOffsetY);
	Gura_AssignMethod(wx_TextAttrShadow, GetOffsetY_1);
	Gura_AssignMethod(wx_TextAttrShadow, SetOffsetY);
	Gura_AssignMethod(wx_TextAttrShadow, GetSpread);
	Gura_AssignMethod(wx_TextAttrShadow, GetSpread_1);
	Gura_AssignMethod(wx_TextAttrShadow, SetSpread);
	Gura_AssignMethod(wx_TextAttrShadow, GetBlurDistance);
	Gura_AssignMethod(wx_TextAttrShadow, GetBlurDistance_1);
	Gura_AssignMethod(wx_TextAttrShadow, SetBlurDistance);
	Gura_AssignMethod(wx_TextAttrShadow, GetOpacity);
	Gura_AssignMethod(wx_TextAttrShadow, GetOpacity_1);
	Gura_AssignMethod(wx_TextAttrShadow, IsValid);
	Gura_AssignMethod(wx_TextAttrShadow, SetValid);
	Gura_AssignMethod(wx_TextAttrShadow, GetFlags);
	Gura_AssignMethod(wx_TextAttrShadow, SetFlags);
	Gura_AssignMethod(wx_TextAttrShadow, AddFlag);
	Gura_AssignMethod(wx_TextAttrShadow, RemoveFlag);
	Gura_AssignMethod(wx_TextAttrShadow, SetOpacity);
	Gura_AssignMethod(wx_TextAttrShadow, IsDefault);
}

Gura_ImplementDescendantCreator(wx_TextAttrShadow)
{
	return new Object_wx_TextAttrShadow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
