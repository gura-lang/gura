//----------------------------------------------------------------------------
// wxTextAttrDimensions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrDimensions
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrDimensions
//----------------------------------------------------------------------------
Object_wx_TextAttrDimensions::~Object_wx_TextAttrDimensions()
{
}

Object *Object_wx_TextAttrDimensions::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrDimensions::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrDimensions:");
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
Gura_DeclareFunctionAlias(__TextAttrDimensions, "TextAttrDimensions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttrDimensions));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextAttrDimensions)
{
	//wxTextAttrDimensions();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextAttrDimensions, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __Reset)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __EqPartial)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrDimensions& dims = arg.GetNumber(0)
	//bool weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __Apply)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrDimensions& dims = arg.GetNumber(0)
	//const wxTextAttrDimensions* compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __CollectCommonAttributes)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrDimensions& attr = arg.GetNumber(0)
	//wxTextAttrDimensions& clashingAttr = arg.GetNumber(1)
	//wxTextAttrDimensions& absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __RemoveStyle)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrDimensions& attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetLeft, "GetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetLeft)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetLeft_1, "GetLeft_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetLeft_1)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetRight, "GetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetRight)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetRight_1, "GetRight_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetRight_1)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetTop, "GetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetTop)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetTop_1, "GetTop_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetTop_1)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetBottom, "GetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetBottom)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __GetBottom_1, "GetBottom_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __GetBottom_1)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrDimensions, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, __IsValid)
{
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrDimensions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimensions)
{
	// Constructor assignment
	Gura_AssignFunction(__TextAttrDimensions);
	// Method assignment
	Gura_AssignMethod(wx_TextAttrDimensions, __Reset);
	Gura_AssignMethod(wx_TextAttrDimensions, __EqPartial);
	Gura_AssignMethod(wx_TextAttrDimensions, __Apply);
	Gura_AssignMethod(wx_TextAttrDimensions, __CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrDimensions, __RemoveStyle);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetLeft);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetLeft_1);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetRight);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetRight_1);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetTop);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetTop_1);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetBottom);
	Gura_AssignMethod(wx_TextAttrDimensions, __GetBottom_1);
	Gura_AssignMethod(wx_TextAttrDimensions, __IsValid);
}

Gura_ImplementDescendantCreator(wx_TextAttrDimensions)
{
	return new Object_wx_TextAttrDimensions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
