//----------------------------------------------------------------------------
// wxWindowCreateEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowCreateEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowCreateEvent
//----------------------------------------------------------------------------
Object_wx_WindowCreateEvent::~Object_wx_WindowCreateEvent()
{
}

Object *Object_wx_WindowCreateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowCreateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowCreateEvent:");
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
Gura_DeclareMethodAlias(wx_WindowCreateEvent, __wxWindowCreateEvent, "wxWindowCreateEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowCreateEvent, __wxWindowCreateEvent)
{
	Object_wx_WindowCreateEvent *pThis = Object_wx_WindowCreateEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowCreateEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowCreateEvent, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WindowCreateEvent, __GetWindow)
{
	Object_wx_WindowCreateEvent *pThis = Object_wx_WindowCreateEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowCreateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowCreateEvent)
{
	Gura_AssignMethod(wx_WindowCreateEvent, __wxWindowCreateEvent);
	Gura_AssignMethod(wx_WindowCreateEvent, __GetWindow);
}

Gura_ImplementDescendantCreator(wx_WindowCreateEvent)
{
	return new Object_wx_WindowCreateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
