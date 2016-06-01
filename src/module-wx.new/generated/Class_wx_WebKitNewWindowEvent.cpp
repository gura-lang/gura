//----------------------------------------------------------------------------
// wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Object_wx_WebKitNewWindowEvent::~Object_wx_WebKitNewWindowEvent()
{
}

Object *Object_wx_WebKitNewWindowEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitNewWindowEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitNewWindowEvent:");
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
Gura_DeclareMethod(wx_WebKitNewWindowEvent, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitNewWindowEvent, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitNewWindowEvent, GetTargetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, GetTargetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTargetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitNewWindowEvent, SetTargetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, SetTargetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitNewWindowEvent, wxWebKitNewWindowEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, wxWebKitNewWindowEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxWebKitNewWindowEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitNewWindowEvent)
{
	Gura_AssignMethod(wx_WebKitNewWindowEvent, GetURL);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, SetURL);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, GetTargetName);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, SetTargetName);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, wxWebKitNewWindowEvent);
}

Gura_ImplementDescendantCreator(wx_WebKitNewWindowEvent)
{
	return new Object_wx_WebKitNewWindowEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
