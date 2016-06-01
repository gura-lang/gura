//----------------------------------------------------------------------------
// wxPowerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerEvent
//----------------------------------------------------------------------------
Object_wx_PowerEvent::~Object_wx_PowerEvent()
{
}

Object *Object_wx_PowerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PowerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PowerEvent:");
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
Gura_DeclareMethod(wx_PowerEvent, wxPowerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, wxPowerEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPowerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PowerEvent, wxPowerEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "evtType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PowerEvent, wxPowerEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int evtType = arg.GetNumber(0)
	//pThis->GetEntity()->wxPowerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PowerEvent, Veto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, Veto)
{
	Signal &sig = env.GetSignal();
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Veto();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PowerEvent, IsVetoed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, IsVetoed)
{
	Signal &sig = env.GetSignal();
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsVetoed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPowerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerEvent)
{
	Gura_AssignMethod(wx_PowerEvent, wxPowerEvent);
	Gura_AssignMethod(wx_PowerEvent, wxPowerEvent_1);
	Gura_AssignMethod(wx_PowerEvent, Veto);
	Gura_AssignMethod(wx_PowerEvent, IsVetoed);
}

Gura_ImplementDescendantCreator(wx_PowerEvent)
{
	return new Object_wx_PowerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
