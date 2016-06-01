//----------------------------------------------------------------------------
// wxSashEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSashEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSashEvent
//----------------------------------------------------------------------------
Object_wx_SashEvent::~Object_wx_SashEvent()
{
}

Object *Object_wx_SashEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SashEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SashEvent:");
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
Gura_DeclareMethod(wx_SashEvent, wxSashEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, wxSashEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int edge = arg.GetNumber(1)
	//pThis->GetEntity()->wxSashEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashEvent, GetDragRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashEvent, GetDragRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDragRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashEvent, GetDragStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashEvent, GetDragStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDragStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashEvent, GetEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashEvent, GetEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEdge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashEvent, SetEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, SetEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashEvent, SetDragRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, SetDragRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashEvent, SetDragStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "status", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, SetDragStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int status = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragStatus();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSashEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashEvent)
{
	Gura_AssignMethod(wx_SashEvent, wxSashEvent);
	Gura_AssignMethod(wx_SashEvent, GetDragRect);
	Gura_AssignMethod(wx_SashEvent, GetDragStatus);
	Gura_AssignMethod(wx_SashEvent, GetEdge);
	Gura_AssignMethod(wx_SashEvent, SetEdge);
	Gura_AssignMethod(wx_SashEvent, SetDragRect);
	Gura_AssignMethod(wx_SashEvent, SetDragStatus);
}

Gura_ImplementDescendantCreator(wx_SashEvent)
{
	return new Object_wx_SashEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
