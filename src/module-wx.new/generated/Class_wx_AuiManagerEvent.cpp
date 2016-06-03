//----------------------------------------------------------------------------
// wxAuiManagerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiManagerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiManagerEvent
//----------------------------------------------------------------------------
Object_wx_AuiManagerEvent::~Object_wx_AuiManagerEvent()
{
}

Object *Object_wx_AuiManagerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_AuiManagerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.AuiManagerEvent:");
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
Gura_DeclareMethodAlias(wx_AuiManagerEvent, __wxAuiManagerEvent, "wxAuiManagerEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __wxAuiManagerEvent)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->wxAuiManagerEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __CanVeto, "CanVeto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __CanVeto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanVeto();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __GetButton, "GetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __GetButton)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __GetDC, "GetDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __GetDC)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __GetVeto, "GetVeto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __GetVeto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVeto();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __GetManager, "GetManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __GetManager)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __GetPane, "GetPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __GetPane)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __SetButton, "SetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __SetButton)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __SetCanVeto, "SetCanVeto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "can_veto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __SetCanVeto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int can_veto = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanVeto();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __SetDC, "SetDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pdc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __SetDC)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pdc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __SetManager, "SetManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __SetManager)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//pThis->GetEntity()->SetManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __SetPane, "SetPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __SetPane)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pane = arg.GetNumber(0)
	//pThis->GetEntity()->SetPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManagerEvent, __Veto, "Veto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "veto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, __Veto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int veto = arg.GetNumber(0)
	//pThis->GetEntity()->Veto();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiManagerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManagerEvent)
{
	Gura_AssignMethod(wx_AuiManagerEvent, __wxAuiManagerEvent);
	Gura_AssignMethod(wx_AuiManagerEvent, __CanVeto);
	Gura_AssignMethod(wx_AuiManagerEvent, __GetButton);
	Gura_AssignMethod(wx_AuiManagerEvent, __GetDC);
	Gura_AssignMethod(wx_AuiManagerEvent, __GetVeto);
	Gura_AssignMethod(wx_AuiManagerEvent, __GetManager);
	Gura_AssignMethod(wx_AuiManagerEvent, __GetPane);
	Gura_AssignMethod(wx_AuiManagerEvent, __SetButton);
	Gura_AssignMethod(wx_AuiManagerEvent, __SetCanVeto);
	Gura_AssignMethod(wx_AuiManagerEvent, __SetDC);
	Gura_AssignMethod(wx_AuiManagerEvent, __SetManager);
	Gura_AssignMethod(wx_AuiManagerEvent, __SetPane);
	Gura_AssignMethod(wx_AuiManagerEvent, __Veto);
}

Gura_ImplementDescendantCreator(wx_AuiManagerEvent)
{
	return new Object_wx_AuiManagerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
