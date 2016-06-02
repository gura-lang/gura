//----------------------------------------------------------------------------
// wxTextAttrDimension
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrDimension
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrDimension
//----------------------------------------------------------------------------
Object_wx_TextAttrDimension::~Object_wx_TextAttrDimension()
{
}

Object *Object_wx_TextAttrDimension::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrDimension::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrDimension:");
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
Gura_DeclareMethod(wx_TextAttrDimension, wxTextAttrDimension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, wxTextAttrDimension)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrDimension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, wxTextAttrDimension_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, wxTextAttrDimension_1)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->wxTextAttrDimension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, Reset)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, EqPartial)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, Apply)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, CollectCommonAttributes)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, GetValue)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, GetValueMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, GetValueMM)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValueMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetValueMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetValueMM)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetValue)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetValue_1)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetValue_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetValue_2)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetValue_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetValue_3)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, GetUnits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, GetUnits)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUnits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetUnits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetUnits)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int units = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, GetPosition)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetPosition)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, IsValid)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetValid)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrDimension, GetFlags)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimension, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimension, SetFlags)
{
	Object_wx_TextAttrDimension *pThis = Object_wx_TextAttrDimension::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrDimension
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimension)
{
	Gura_AssignMethod(wx_TextAttrDimension, wxTextAttrDimension);
	Gura_AssignMethod(wx_TextAttrDimension, wxTextAttrDimension_1);
	Gura_AssignMethod(wx_TextAttrDimension, Reset);
	Gura_AssignMethod(wx_TextAttrDimension, EqPartial);
	Gura_AssignMethod(wx_TextAttrDimension, Apply);
	Gura_AssignMethod(wx_TextAttrDimension, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrDimension, GetValue);
	Gura_AssignMethod(wx_TextAttrDimension, GetValueMM);
	Gura_AssignMethod(wx_TextAttrDimension, SetValueMM);
	Gura_AssignMethod(wx_TextAttrDimension, SetValue);
	Gura_AssignMethod(wx_TextAttrDimension, SetValue_1);
	Gura_AssignMethod(wx_TextAttrDimension, SetValue_2);
	Gura_AssignMethod(wx_TextAttrDimension, SetValue_3);
	Gura_AssignMethod(wx_TextAttrDimension, GetUnits);
	Gura_AssignMethod(wx_TextAttrDimension, SetUnits);
	Gura_AssignMethod(wx_TextAttrDimension, GetPosition);
	Gura_AssignMethod(wx_TextAttrDimension, SetPosition);
	Gura_AssignMethod(wx_TextAttrDimension, IsValid);
	Gura_AssignMethod(wx_TextAttrDimension, SetValid);
	Gura_AssignMethod(wx_TextAttrDimension, GetFlags);
	Gura_AssignMethod(wx_TextAttrDimension, SetFlags);
}

Gura_ImplementDescendantCreator(wx_TextAttrDimension)
{
	return new Object_wx_TextAttrDimension((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
