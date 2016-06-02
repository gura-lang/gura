//----------------------------------------------------------------------------
// wxFocusEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFocusEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFocusEvent
//----------------------------------------------------------------------------
Object_wx_FocusEvent::~Object_wx_FocusEvent()
{
}

Object *Object_wx_FocusEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FocusEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FocusEvent:");
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
Gura_DeclareMethod(wx_FocusEvent, wxFocusEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FocusEvent, wxFocusEvent)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxFocusEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FocusEvent, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FocusEvent, GetWindow)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FocusEvent, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FocusEvent, SetWindow)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FocusEvent)
{
	Gura_AssignMethod(wx_FocusEvent, wxFocusEvent);
	Gura_AssignMethod(wx_FocusEvent, GetWindow);
	Gura_AssignMethod(wx_FocusEvent, SetWindow);
}

Gura_ImplementDescendantCreator(wx_FocusEvent)
{
	return new Object_wx_FocusEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
