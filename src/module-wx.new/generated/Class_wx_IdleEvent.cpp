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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__IdleEvent, "IdleEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_IdleEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__IdleEvent)
{
	//wxIdleEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_IdleEvent, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IdleEvent, __GetMode)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IdleEvent, __MoreRequested, "MoreRequested")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IdleEvent, __MoreRequested)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoreRequested();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IdleEvent, __RequestMore, "RequestMore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "needMore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IdleEvent, __RequestMore)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int needMore = arg.GetNumber(0)
	//pThis->GetEntity()->RequestMore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IdleEvent, __SetMode, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IdleEvent, __SetMode)
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
	// Constructor assignment
	Gura_AssignFunction(__IdleEvent);
	// Method assignment
	Gura_AssignMethod(wx_IdleEvent, __GetMode);
	Gura_AssignMethod(wx_IdleEvent, __MoreRequested);
	Gura_AssignMethod(wx_IdleEvent, __RequestMore);
	Gura_AssignMethod(wx_IdleEvent, __SetMode);
}

Gura_ImplementDescendantCreator(wx_IdleEvent)
{
	return new Object_wx_IdleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
