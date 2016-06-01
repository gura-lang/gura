//----------------------------------------------------------------------------
// wxTextUrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextUrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextUrlEvent
//----------------------------------------------------------------------------
Object_wx_TextUrlEvent::~Object_wx_TextUrlEvent()
{
}

Object *Object_wx_TextUrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TextUrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TextUrlEvent:");
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
Gura_DeclareMethod(wx_TextUrlEvent, wxTextUrlEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "evtMouse", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextUrlEvent, wxTextUrlEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int winid = arg.GetNumber(0)
	//int evtMouse = arg.GetNumber(1)
	//int start = arg.GetNumber(2)
	//int end = arg.GetNumber(3)
	//pThis->GetEntity()->wxTextUrlEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextUrlEvent, wxTextUrlEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextUrlEvent, wxTextUrlEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextUrlEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextUrlEvent, GetMouseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, GetMouseEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMouseEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextUrlEvent, GetURLStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, GetURLStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetURLStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextUrlEvent, GetURLEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, GetURLEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetURLEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextUrlEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextUrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextUrlEvent)
{
	Gura_AssignMethod(wx_TextUrlEvent, wxTextUrlEvent);
	Gura_AssignMethod(wx_TextUrlEvent, wxTextUrlEvent_1);
	Gura_AssignMethod(wx_TextUrlEvent, GetMouseEvent);
	Gura_AssignMethod(wx_TextUrlEvent, GetURLStart);
	Gura_AssignMethod(wx_TextUrlEvent, GetURLEnd);
	Gura_AssignMethod(wx_TextUrlEvent, Clone);
}

Gura_ImplementDescendantCreator(wx_TextUrlEvent)
{
	return new Object_wx_TextUrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
