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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FocusEvent, "FocusEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FocusEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FocusEvent)
{
	//wxEventType eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxFocusEvent(eventType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FocusEvent, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FocusEvent, __GetWindow)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FocusEvent, __SetWindow, "SetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FocusEvent, __SetWindow)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FocusEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__FocusEvent);
	// Method assignment
	Gura_AssignMethod(wx_FocusEvent, __GetWindow);
	Gura_AssignMethod(wx_FocusEvent, __SetWindow);
}

Gura_ImplementDescendantCreator(wx_FocusEvent)
{
	return new Object_wx_FocusEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
