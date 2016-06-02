//----------------------------------------------------------------------------
// wxIdleEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIdleEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIdleEvent
//----------------------------------------------------------------------------
Object_wx_IdleEvent::~Object_wx_IdleEvent()
{
}

Object *Object_wx_IdleEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IdleEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IdleEvent:");
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
Gura_DeclareMethod(wx_IdleEvent, wxIdleEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IdleEvent, wxIdleEvent)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxIdleEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IdleEvent, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IdleEvent, GetMode)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IdleEvent, MoreRequested)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IdleEvent, MoreRequested)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoreRequested();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IdleEvent, RequestMore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "needMore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IdleEvent, RequestMore)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int needMore = arg.GetNumber(0)
	//pThis->GetEntity()->RequestMore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IdleEvent, SetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IdleEvent, SetMode)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIdleEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IdleEvent)
{
	Gura_AssignMethod(wx_IdleEvent, wxIdleEvent);
	Gura_AssignMethod(wx_IdleEvent, GetMode);
	Gura_AssignMethod(wx_IdleEvent, MoreRequested);
	Gura_AssignMethod(wx_IdleEvent, RequestMore);
	Gura_AssignMethod(wx_IdleEvent, SetMode);
}

Gura_ImplementDescendantCreator(wx_IdleEvent)
{
	return new Object_wx_IdleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
