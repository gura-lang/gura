//----------------------------------------------------------------------------
// wxPropertyGridEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridEvent
//----------------------------------------------------------------------------
Object_wx_PropertyGridEvent::~Object_wx_PropertyGridEvent()
{
}

Object *Object_wx_PropertyGridEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridEvent:");
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
Gura_DeclareMethod(wx_PropertyGridEvent, wxPropertyGridEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, wxPropertyGridEvent)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxPropertyGridEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, wxPropertyGridEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, wxPropertyGridEvent_1)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxPropertyGridEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, CanVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, CanVeto)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanVeto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, GetColumn)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, GetMainParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, GetMainParent)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, GetProperty)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, GetValidationFailureBehavior)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, GetValidationFailureBehavior)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValidationFailureBehavior();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, GetPropertyName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, GetPropertyName)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertyName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, GetPropertyValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, GetPropertyValue)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertyValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, SetCanVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canVeto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, SetCanVeto)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int canVeto = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanVeto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, SetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, SetProperty)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, SetValidationFailureBehavior)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, SetValidationFailureBehavior)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetValidationFailureBehavior();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, SetValidationFailureMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, SetValidationFailureMessage)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->SetValidationFailureMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, Veto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "veto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridEvent, Veto)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int veto = arg.GetNumber(0)
	//pThis->GetEntity()->Veto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridEvent, WasVetoed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridEvent, WasVetoed)
{
	Object_wx_PropertyGridEvent *pThis = Object_wx_PropertyGridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WasVetoed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridEvent)
{
	Gura_AssignMethod(wx_PropertyGridEvent, wxPropertyGridEvent);
	Gura_AssignMethod(wx_PropertyGridEvent, wxPropertyGridEvent_1);
	Gura_AssignMethod(wx_PropertyGridEvent, CanVeto);
	Gura_AssignMethod(wx_PropertyGridEvent, GetColumn);
	Gura_AssignMethod(wx_PropertyGridEvent, GetMainParent);
	Gura_AssignMethod(wx_PropertyGridEvent, GetProperty);
	Gura_AssignMethod(wx_PropertyGridEvent, GetValidationFailureBehavior);
	Gura_AssignMethod(wx_PropertyGridEvent, GetPropertyName);
	Gura_AssignMethod(wx_PropertyGridEvent, GetPropertyValue);
	Gura_AssignMethod(wx_PropertyGridEvent, SetCanVeto);
	Gura_AssignMethod(wx_PropertyGridEvent, SetProperty);
	Gura_AssignMethod(wx_PropertyGridEvent, SetValidationFailureBehavior);
	Gura_AssignMethod(wx_PropertyGridEvent, SetValidationFailureMessage);
	Gura_AssignMethod(wx_PropertyGridEvent, Veto);
	Gura_AssignMethod(wx_PropertyGridEvent, WasVetoed);
}

Gura_ImplementDescendantCreator(wx_PropertyGridEvent)
{
	return new Object_wx_PropertyGridEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
