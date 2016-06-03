//----------------------------------------------------------------------------
// wxTextAttrBorders
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrBorders
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrBorders
//----------------------------------------------------------------------------
Object_wx_TextAttrBorders::~Object_wx_TextAttrBorders()
{
}

Object *Object_wx_TextAttrBorders::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrBorders::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrBorders:");
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
Gura_DeclareMethodAlias(wx_TextAttrBorders, __wxTextAttrBorders, "wxTextAttrBorders")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __wxTextAttrBorders)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrBorders();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __SetStyle)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __SetColour)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __SetColour_1, "SetColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __SetColour_1)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __SetWidth)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __SetWidth_1, "SetWidth_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __SetWidth_1)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __Reset)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "borders", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __EqPartial)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int borders = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "borders", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __Apply)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int borders = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __RemoveStyle)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, __CollectCommonAttributes)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __IsValid)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetLeft, "GetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetLeft)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetLeft_1, "GetLeft_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetLeft_1)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetRight, "GetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetRight)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetRight_1, "GetRight_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetRight_1)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetTop, "GetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetTop)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetTop_1, "GetTop_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetTop_1)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetBottom, "GetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetBottom)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorders, __GetBottom_1, "GetBottom_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, __GetBottom_1)
{
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrBorders
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrBorders)
{
	Gura_AssignMethod(wx_TextAttrBorders, __wxTextAttrBorders);
	Gura_AssignMethod(wx_TextAttrBorders, __SetStyle);
	Gura_AssignMethod(wx_TextAttrBorders, __SetColour);
	Gura_AssignMethod(wx_TextAttrBorders, __SetColour_1);
	Gura_AssignMethod(wx_TextAttrBorders, __SetWidth);
	Gura_AssignMethod(wx_TextAttrBorders, __SetWidth_1);
	Gura_AssignMethod(wx_TextAttrBorders, __Reset);
	Gura_AssignMethod(wx_TextAttrBorders, __EqPartial);
	Gura_AssignMethod(wx_TextAttrBorders, __Apply);
	Gura_AssignMethod(wx_TextAttrBorders, __RemoveStyle);
	Gura_AssignMethod(wx_TextAttrBorders, __CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrBorders, __IsValid);
	Gura_AssignMethod(wx_TextAttrBorders, __GetLeft);
	Gura_AssignMethod(wx_TextAttrBorders, __GetLeft_1);
	Gura_AssignMethod(wx_TextAttrBorders, __GetRight);
	Gura_AssignMethod(wx_TextAttrBorders, __GetRight_1);
	Gura_AssignMethod(wx_TextAttrBorders, __GetTop);
	Gura_AssignMethod(wx_TextAttrBorders, __GetTop_1);
	Gura_AssignMethod(wx_TextAttrBorders, __GetBottom);
	Gura_AssignMethod(wx_TextAttrBorders, __GetBottom_1);
}

Gura_ImplementDescendantCreator(wx_TextAttrBorders)
{
	return new Object_wx_TextAttrBorders((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
