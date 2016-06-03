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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxSetCursorEvent, "wxSetCursorEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SetCursorEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxSetCursorEvent)
{
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxSetCursorEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SetCursorEvent, __GetCursor, "GetCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, __GetCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SetCursorEvent, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, __GetX)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SetCursorEvent, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, __GetY)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SetCursorEvent, __HasCursor, "HasCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SetCursorEvent, __HasCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SetCursorEvent, __SetCursor, "SetCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SetCursorEvent, __SetCursor)
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
	// Constructor assignment
	Gura_AssignFunction(__wxSetCursorEvent);
	// Method assignment
	Gura_AssignMethod(wx_SetCursorEvent, __GetCursor);
	Gura_AssignMethod(wx_SetCursorEvent, __GetX);
	Gura_AssignMethod(wx_SetCursorEvent, __GetY);
	Gura_AssignMethod(wx_SetCursorEvent, __HasCursor);
	Gura_AssignMethod(wx_SetCursorEvent, __SetCursor);
}

Gura_ImplementDescendantCreator(wx_SetCursorEvent)
{
	return new Object_wx_SetCursorEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
