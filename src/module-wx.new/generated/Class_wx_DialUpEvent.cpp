//----------------------------------------------------------------------------
// wxDialUpEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Object_wx_DialUpEvent::~Object_wx_DialUpEvent()
{
}

Object *Object_wx_DialUpEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DialUpEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DialUpEvent:");
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
Gura_DeclareFunctionAlias(__DialUpEvent, "DialUpEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isConnected", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isOwnEvent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DialUpEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DialUpEvent)
{
	//bool isConnected = arg.GetNumber(0)
	//bool isOwnEvent = arg.GetNumber(1)
	//wxDialUpEvent(isConnected, isOwnEvent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DialUpEvent, __IsConnectedEvent, "IsConnectedEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpEvent, __IsConnectedEvent)
{
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsConnectedEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpEvent, __IsOwnEvent, "IsOwnEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpEvent, __IsOwnEvent)
{
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOwnEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__DialUpEvent);
	// Method assignment
	Gura_AssignMethod(wx_DialUpEvent, __IsConnectedEvent);
	Gura_AssignMethod(wx_DialUpEvent, __IsOwnEvent);
}

Gura_ImplementDescendantCreator(wx_DialUpEvent)
{
	return new Object_wx_DialUpEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
