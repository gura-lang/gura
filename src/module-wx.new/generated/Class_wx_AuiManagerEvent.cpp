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
Gura_DeclareMethod(wx_AuiManagerEvent, wxAuiManagerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, wxAuiManagerEvent)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->wxAuiManagerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, CanVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, CanVeto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanVeto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, GetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, GetButton)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, GetDC)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, GetVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, GetVeto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVeto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, GetManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, GetManager)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, GetPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManagerEvent, GetPane)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, SetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, SetButton)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, SetCanVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "can_veto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, SetCanVeto)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int can_veto = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanVeto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, SetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pdc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, SetDC)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pdc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, SetManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, SetManager)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//pThis->GetEntity()->SetManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, SetPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, SetPane)
{
	Object_wx_AuiManagerEvent *pThis = Object_wx_AuiManagerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pane = arg.GetNumber(0)
	//pThis->GetEntity()->SetPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManagerEvent, Veto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "veto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManagerEvent, Veto)
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
	Gura_AssignMethod(wx_AuiManagerEvent, wxAuiManagerEvent);
	Gura_AssignMethod(wx_AuiManagerEvent, CanVeto);
	Gura_AssignMethod(wx_AuiManagerEvent, GetButton);
	Gura_AssignMethod(wx_AuiManagerEvent, GetDC);
	Gura_AssignMethod(wx_AuiManagerEvent, GetVeto);
	Gura_AssignMethod(wx_AuiManagerEvent, GetManager);
	Gura_AssignMethod(wx_AuiManagerEvent, GetPane);
	Gura_AssignMethod(wx_AuiManagerEvent, SetButton);
	Gura_AssignMethod(wx_AuiManagerEvent, SetCanVeto);
	Gura_AssignMethod(wx_AuiManagerEvent, SetDC);
	Gura_AssignMethod(wx_AuiManagerEvent, SetManager);
	Gura_AssignMethod(wx_AuiManagerEvent, SetPane);
	Gura_AssignMethod(wx_AuiManagerEvent, Veto);
}

Gura_ImplementDescendantCreator(wx_AuiManagerEvent)
{
	return new Object_wx_AuiManagerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
