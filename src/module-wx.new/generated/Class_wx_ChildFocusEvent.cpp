//----------------------------------------------------------------------------
// wxChildFocusEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChildFocusEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Object_wx_ChildFocusEvent::~Object_wx_ChildFocusEvent()
{
}

Object *Object_wx_ChildFocusEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ChildFocusEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ChildFocusEvent:");
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
Gura_DeclareMethod(wx_ChildFocusEvent, wxChildFocusEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ChildFocusEvent, wxChildFocusEvent)
{
	Object_wx_ChildFocusEvent *pThis = Object_wx_ChildFocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxChildFocusEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ChildFocusEvent, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ChildFocusEvent, GetWindow)
{
	Object_wx_ChildFocusEvent *pThis = Object_wx_ChildFocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ChildFocusEvent)
{
	Gura_AssignMethod(wx_ChildFocusEvent, wxChildFocusEvent);
	Gura_AssignMethod(wx_ChildFocusEvent, GetWindow);
}

Gura_ImplementDescendantCreator(wx_ChildFocusEvent)
{
	return new Object_wx_ChildFocusEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
