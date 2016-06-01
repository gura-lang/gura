//----------------------------------------------------------------------------
// wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Object_wx_WebKitBeforeLoadEvent::~Object_wx_WebKitBeforeLoadEvent()
{
}

Object *Object_wx_WebKitBeforeLoadEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitBeforeLoadEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitBeforeLoadEvent:");
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
Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, IsCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, IsCancelled)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsCancelled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, Cancel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, Cancel)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cancel = arg.GetNumber(0)
	//pThis->GetEntity()->Cancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, SetNavigationType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "navType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, SetNavigationType)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int navType = arg.GetNumber(0)
	//pThis->GetEntity()->SetNavigationType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, GetNavigationType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, GetNavigationType)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNavigationType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitBeforeLoadEvent, wxWebKitBeforeLoadEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, wxWebKitBeforeLoadEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxWebKitBeforeLoadEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitBeforeLoadEvent)
{
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, IsCancelled);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, Cancel);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, GetURL);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, SetURL);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, SetNavigationType);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, GetNavigationType);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, wxWebKitBeforeLoadEvent);
}

Gura_ImplementDescendantCreator(wx_WebKitBeforeLoadEvent)
{
	return new Object_wx_WebKitBeforeLoadEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
