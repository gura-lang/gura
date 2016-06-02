//----------------------------------------------------------------------------
// wxSetCursorEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSetCursorEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Object_wx_SetCursorEvent::~Object_wx_SetCursorEvent()
{
}

Object *Object_wx_SetCursorEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SetCursorEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SetCursorEvent:");
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
Gura_DeclareMethod(wx_SetCursorEvent, wxSetCursorEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SetCursorEvent, wxSetCursorEvent)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->wxSetCursorEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SetCursorEvent, GetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SetCursorEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetX)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SetCursorEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetY)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SetCursorEvent, HasCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, HasCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SetCursorEvent, SetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SetCursorEvent, SetCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->SetCursor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SetCursorEvent)
{
	Gura_AssignMethod(wx_SetCursorEvent, wxSetCursorEvent);
	Gura_AssignMethod(wx_SetCursorEvent, GetCursor);
	Gura_AssignMethod(wx_SetCursorEvent, GetX);
	Gura_AssignMethod(wx_SetCursorEvent, GetY);
	Gura_AssignMethod(wx_SetCursorEvent, HasCursor);
	Gura_AssignMethod(wx_SetCursorEvent, SetCursor);
}

Gura_ImplementDescendantCreator(wx_SetCursorEvent)
{
	return new Object_wx_SetCursorEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
