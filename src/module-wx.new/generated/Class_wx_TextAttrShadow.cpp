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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxTextAttrShadow, "wxTextAttrShadow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttrShadow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTextAttrShadow)
{
	//wxTextAttrShadow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextAttrShadow, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __Reset)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shadow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __EqPartial)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int shadow = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shadow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __Apply)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int shadow = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __RemoveStyle)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __CollectCommonAttributes)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetColour)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetColour_1, "SetColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetColour_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetColourLong, "GetColourLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetColourLong)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColourLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetColour)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __HasColour, "HasColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __HasColour)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetOffsetX, "GetOffsetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetOffsetX)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetOffsetX_1, "GetOffsetX_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetOffsetX_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetOffsetX, "SetOffsetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetOffsetX)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int offset = arg.GetNumber(0)
	//pThis->GetEntity()->SetOffsetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetOffsetY, "GetOffsetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetOffsetY)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetOffsetY_1, "GetOffsetY_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetOffsetY_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffsetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetOffsetY, "SetOffsetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetOffsetY)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int offset = arg.GetNumber(0)
	//pThis->GetEntity()->SetOffsetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetSpread, "GetSpread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetSpread)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpread();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetSpread_1, "GetSpread_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetSpread_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpread();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetSpread, "SetSpread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spread", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetSpread)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int spread = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpread();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetBlurDistance, "GetBlurDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetBlurDistance)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlurDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetBlurDistance_1, "GetBlurDistance_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetBlurDistance_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlurDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetBlurDistance, "SetBlurDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "blur", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetBlurDistance)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int blur = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlurDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetOpacity, "GetOpacity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetOpacity)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpacity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetOpacity_1, "GetOpacity_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetOpacity_1)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpacity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __IsValid)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetValid, "SetValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetValid)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __GetFlags)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetFlags)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __AddFlag, "AddFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __AddFlag)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->AddFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __RemoveFlag, "RemoveFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __RemoveFlag)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __SetOpacity, "SetOpacity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "opacity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrShadow, __SetOpacity)
{
	Object_wx_TextAttrShadow *pThis = Object_wx_TextAttrShadow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int opacity = arg.GetNumber(0)
	//pThis->GetEntity()->SetOpacity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrShadow, __IsDefault, "IsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrShadow, __IsDefault)
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
	// Constructor assignment
	Gura_AssignFunction(__wxTextAttrShadow);
	// Method assignment
	Gura_AssignMethod(wx_TextAttrShadow, __Reset);
	Gura_AssignMethod(wx_TextAttrShadow, __EqPartial);
	Gura_AssignMethod(wx_TextAttrShadow, __Apply);
	Gura_AssignMethod(wx_TextAttrShadow, __RemoveStyle);
	Gura_AssignMethod(wx_TextAttrShadow, __CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrShadow, __SetColour);
	Gura_AssignMethod(wx_TextAttrShadow, __SetColour_1);
	Gura_AssignMethod(wx_TextAttrShadow, __GetColourLong);
	Gura_AssignMethod(wx_TextAttrShadow, __GetColour);
	Gura_AssignMethod(wx_TextAttrShadow, __HasColour);
	Gura_AssignMethod(wx_TextAttrShadow, __GetOffsetX);
	Gura_AssignMethod(wx_TextAttrShadow, __GetOffsetX_1);
	Gura_AssignMethod(wx_TextAttrShadow, __SetOffsetX);
	Gura_AssignMethod(wx_TextAttrShadow, __GetOffsetY);
	Gura_AssignMethod(wx_TextAttrShadow, __GetOffsetY_1);
	Gura_AssignMethod(wx_TextAttrShadow, __SetOffsetY);
	Gura_AssignMethod(wx_TextAttrShadow, __GetSpread);
	Gura_AssignMethod(wx_TextAttrShadow, __GetSpread_1);
	Gura_AssignMethod(wx_TextAttrShadow, __SetSpread);
	Gura_AssignMethod(wx_TextAttrShadow, __GetBlurDistance);
	Gura_AssignMethod(wx_TextAttrShadow, __GetBlurDistance_1);
	Gura_AssignMethod(wx_TextAttrShadow, __SetBlurDistance);
	Gura_AssignMethod(wx_TextAttrShadow, __GetOpacity);
	Gura_AssignMethod(wx_TextAttrShadow, __GetOpacity_1);
	Gura_AssignMethod(wx_TextAttrShadow, __IsValid);
	Gura_AssignMethod(wx_TextAttrShadow, __SetValid);
	Gura_AssignMethod(wx_TextAttrShadow, __GetFlags);
	Gura_AssignMethod(wx_TextAttrShadow, __SetFlags);
	Gura_AssignMethod(wx_TextAttrShadow, __AddFlag);
	Gura_AssignMethod(wx_TextAttrShadow, __RemoveFlag);
	Gura_AssignMethod(wx_TextAttrShadow, __SetOpacity);
	Gura_AssignMethod(wx_TextAttrShadow, __IsDefault);
}

Gura_ImplementDescendantCreator(wx_TextAttrShadow)
{
	return new Object_wx_TextAttrShadow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
