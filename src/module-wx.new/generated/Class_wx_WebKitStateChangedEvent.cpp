//----------------------------------------------------------------------------
// wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
Object_wx_WebKitStateChangedEvent::~Object_wx_WebKitStateChangedEvent()
{
}

Object *Object_wx_WebKitStateChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitStateChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitStateChangedEvent:");
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
Gura_DeclareMethodAlias(wx_WebKitStateChangedEvent, __GetState, "GetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitStateChangedEvent, __GetState)
{
	Object_wx_WebKitStateChangedEvent *pThis = Object_wx_WebKitStateChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitStateChangedEvent, __SetState, "SetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitStateChangedEvent, __SetState)
{
	Object_wx_WebKitStateChangedEvent *pThis = Object_wx_WebKitStateChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitStateChangedEvent, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitStateChangedEvent, __GetURL)
{
	Object_wx_WebKitStateChangedEvent *pThis = Object_wx_WebKitStateChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitStateChangedEvent, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitStateChangedEvent, __SetURL)
{
	Object_wx_WebKitStateChangedEvent *pThis = Object_wx_WebKitStateChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitStateChangedEvent, __wxWebKitStateChangedEvent, "wxWebKitStateChangedEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitStateChangedEvent, __wxWebKitStateChangedEvent)
{
	Object_wx_WebKitStateChangedEvent *pThis = Object_wx_WebKitStateChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxWebKitStateChangedEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitStateChangedEvent)
{
	Gura_AssignMethod(wx_WebKitStateChangedEvent, __GetState);
	Gura_AssignMethod(wx_WebKitStateChangedEvent, __SetState);
	Gura_AssignMethod(wx_WebKitStateChangedEvent, __GetURL);
	Gura_AssignMethod(wx_WebKitStateChangedEvent, __SetURL);
	Gura_AssignMethod(wx_WebKitStateChangedEvent, __wxWebKitStateChangedEvent);
}

Gura_ImplementDescendantCreator(wx_WebKitStateChangedEvent)
{
	return new Object_wx_WebKitStateChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
