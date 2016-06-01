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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TextAttrDimensions, wxTextAttrDimensions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, wxTextAttrDimensions)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrDimensions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, EqPartial)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dims = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, Apply)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dims = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, CollectCommonAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensions, RemoveStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetLeft_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetLeft_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetRight_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetRight_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetTop_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetTop_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, GetBottom_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, GetBottom_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensions, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimensions, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrDimensions *pThis = Object_wx_TextAttrDimensions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrDimensions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimensions)
{
	Gura_AssignMethod(wx_TextAttrDimensions, wxTextAttrDimensions);
	Gura_AssignMethod(wx_TextAttrDimensions, Reset);
	Gura_AssignMethod(wx_TextAttrDimensions, EqPartial);
	Gura_AssignMethod(wx_TextAttrDimensions, Apply);
	Gura_AssignMethod(wx_TextAttrDimensions, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrDimensions, RemoveStyle);
	Gura_AssignMethod(wx_TextAttrDimensions, GetLeft);
	Gura_AssignMethod(wx_TextAttrDimensions, GetLeft_1);
	Gura_AssignMethod(wx_TextAttrDimensions, GetRight);
	Gura_AssignMethod(wx_TextAttrDimensions, GetRight_1);
	Gura_AssignMethod(wx_TextAttrDimensions, GetTop);
	Gura_AssignMethod(wx_TextAttrDimensions, GetTop_1);
	Gura_AssignMethod(wx_TextAttrDimensions, GetBottom);
	Gura_AssignMethod(wx_TextAttrDimensions, GetBottom_1);
	Gura_AssignMethod(wx_TextAttrDimensions, IsValid);
}

Gura_ImplementDescendantCreator(wx_TextAttrDimensions)
{
	return new Object_wx_TextAttrDimensions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
